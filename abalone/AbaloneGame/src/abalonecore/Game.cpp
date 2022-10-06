#include "Game.h"

/**
 * @brief Game::move
 * @param positions
 */
void Game::move(std::vector<Position>&positions){
    std::vector<Position>group1;
    std::vector<Position>group2;
    Direction dir ;
    Direction moveDir;
    auto lateral =0;

    if(_currentPlayer.correct_position  (positions)){

        if(positions.size()==3)
        {

            Position posLat = positions.at(1)-positions.at(0);
            Position instance = positions.at(2)-positions.at(0);
            lateral = isLateral(posLat);
            if(lateral)
            {

                dir= get_direction_at(posLat);
                moveDir=get_direction_at(instance);
            }else{

                dir=get_direction_at(instance);
                moveDir=get_direction_at(instance);
            }
            group1 = creategroup(positions.at(0),positions.at(1),dir) ;
        }else{

            Position instance2 = positions.at(1)-positions.at(0);
            moveDir=get_direction_at(instance2);
            dir = get_direction_at(instance2);
            group1 = creategroupOneSize(positions.at(0),dir);
        }

        move(group1,moveDir,lateral);

         switchPlayer();

    }else {
        throw std::invalid_argument("SEEMS THAT THE MARBLE OR THE POSITION YOU CHOOSE ARE NOT YOURS OR NOT CORRECT");
    }
}
/**
 * @brief Game::initialized
 */
void Game::initialized(Color color)
{
    this->_currentPlayer = Player (color);
    Color opponent_color;
    if (   color == Color::WHITE)
    {
        opponent_color = Color::BLACK;
    }
    else
    {
        opponent_color = Color::WHITE;
    }
    this->_opponentPlayer = Player (opponent_color);
    this->_board = Board ();

    this->create_board();
    this->create_marble();
}
/**
 * @brief Game::create_board
 */
void Game::create_board()
{
    this->_board.createBoard();
}
/**
 * @brief Game::create_marble
 */
void Game::create_marble(){
    auto positions = g_function::square_busy();
    Color colorplayer = this->_currentPlayer.getPlayerColor();
    if(colorplayer==Color::WHITE){
        for(int i = 0 ; i<14; i++){
            _currentPlayer.creatMarble(positions.at(i),colorplayer,i);
        }
        int index = 0;
        Color colorplayer2 = this->_opponentPlayer.getPlayerColor();
        for(int i = 14 ; i<28; i++){
            _opponentPlayer.creatMarble(positions.at(i),colorplayer2,index);
            index++;
        }
    }else{
        int index = 0;
        Color colorplayer2 = this->_currentPlayer.getPlayerColor();
        for(int i = 14 ; i<28; i++){
            _currentPlayer.creatMarble(positions.at(i),colorplayer2,index);
            index++;
        }
        colorplayer=_opponentPlayer.getPlayerColor();
        for(int i = 0 ; i<14; i++){
            _opponentPlayer.creatMarble(positions.at(i),colorplayer,i);
        }


    }
}
/**
 * @brief Game::creategroup
 * @param start
 * @param end
 * @param final
 * @return
 */
std::vector<Position> Game::creategroup(Position& start,Position& end,Direction& final){
    std::vector<Position> group = std::vector<Position>(10);
    Position instance =start;
    int index=0;
    while(instance != end){
        group.at(index)=instance;
        instance=instance.neighbour(final);
        index++;
    }
    group.at(index)=end;
    index++;
    group.resize(index);

    return group;
}
std::vector<Position> Game::creategroupOneSize(Position &start, Direction dir){
    std::vector<Position> group = std::vector<Position>(10);
    auto next = start;
    auto index=0;
    while (!_board.square_is_free(next) && _currentPlayer.marble_is_mine(next)) {
        group.at(index)=next;
        next=next.neighbour(dir);
        index++;
    }
    group.resize(index);
    return group;
}

/**
 * @brief Game::verif_group
 * @param group1
 * @param group2
 * @return
 */
int Game::verif_group(std::vector<Position>& group1, std::vector<Position>& group2){
    if(group2.empty())
    {
        return 1;
    }
    else if(group1.size() > group2.size()){
        return 2;
    }
    return -1;
}

/**
 * @brief Game::setPlayerState
 */
void Game::setPlayerState(){
    if(_currentPlayer.getAllMarbles().size() <= 6 && _opponentPlayer.getAllMarbles().size()>6){
        _currentPlayer.setState(State::FAIL);
        _opponentPlayer.setState(State::WIN);

    }else
    {

    }
}
bool Game::checkWin(){
    setPlayerState();
    return _currentPlayer.getState()==FAIL || _opponentPlayer.getState()==FAIL;
}

void Game::move(std::vector<Position>&group1,Direction direction,bool lateral){
    Position next = group1.at(group1.size()-1).neighbour(direction);
    auto group2 = std::vector<Position>(10);
    if(lateral){

        createLateralGroup(group1,direction,group2);
    }else{
        createNormalGroup(group2,next,direction);
    }

    auto verif = verif_group(group1,group2);
    if(verif==1){
        apply_move(group1,direction,verif);
    }else if(verif==2){

        apply_move(group2,direction, verif);

        apply_move(group1,direction, 1);
    }else if(verif>0)
    {
        throw std::invalid_argument("MOVE NOT ALLOW");
    }


}
void Game::apply_move(std::vector<Position>&group1,Direction direction,int verif){
    for (auto it=group1.rbegin();it!=group1.rend() ;it++ ) {
        Position &ref = *it;
        auto type =Type::EMPTY;
        _board.setSquareType(ref,type);
        auto next = ref.neighbour(direction);
        if(this->_board.isInside(next)){
            if(verif==1){
                auto type2= Type::BUSY;
                _currentPlayer.get_marble_at(ref).setPosition(next);
                _board.setSquareType(next,type2);
            }else if(verif==2)
            {
                auto type2= Type::BUSY;
                _opponentPlayer.get_marble_at(ref).setPosition(next);
                _board.setSquareType(next,type2);
            }
        }else{
            _board.setSquareType(ref,type);
            _opponentPlayer.remove(_opponentPlayer.get_marble_at(ref));
        }
    }
}
std::vector<Position> Game::convert(std::vector<AbaPro>&input)
{
    auto position = std::vector<Position> (input.size ());
    for (auto i = 0; i < static_cast<int>(input.size()); i++)
    {
        auto row = input.at (i).get_row ();
        auto column = input.at (i).get_column ();
        position.at (i) = get_accurate_position (row, column);
    }

    return position;
}
bool Game::isLateral(Position&pos)
{
    return pos.getRow()==0 || pos.getRow()<0;
}

void Game::switchPlayer()
{
    auto player = _currentPlayer;
    _currentPlayer =_opponentPlayer;
    _opponentPlayer=player;
}
bool Game::marble_is_present_at (Position &position)
{
    return _currentPlayer.marble_exist_at (position) || _opponentPlayer.marble_exist_at (position);
}
/**
 *
 * @param position
 * @return
 */
Marble Game::get_marble_at (Position &position)
{
    return _currentPlayer.marble_exist_at (position) ? _currentPlayer.get_marble_at (position)
                                                     : _opponentPlayer.get_marble_at (position);
}


void Game::createLateralGroup(std::vector<Position>&positions, Direction direction, std::vector<Position>&group2)
{
    int i=0;
    int index=0;

    Position posLat = positions.at(1)-positions.at(0);
    if(posLat.getRow()<0)
    {
        i= positions.size()-1;
        auto next = positions.at(i).neighbour(direction);
        createNormalGroup(group2,next,direction);
    }else if(posLat.getRow()==0){
        for (;i<static_cast<int>(positions.size()) ;i++ ) {
            auto next = positions.at(i).neighbour(direction);
            if(marble_is_present_at(next))
            {
                if(!_currentPlayer.marble_is_mine(next))
                {
                    group2.at(i)= next;
                    index++;
                }
            }
        }
        group2.resize(index);
    }

}
void Game::createNormalGroup(std::vector<Position>&group2,Position&next, Direction direction)
{
    int index=0;
    while(!_board.square_is_free(next) && !_board.is_out_of_bount(next)){
        group2.at(index)=next;
        next=next.neighbour(direction);
        index++;
    }
    group2.resize(index);
}

std::string Game::get_winner_name()
{
    if(_currentPlayer.getState()==WIN)
    {
        if(_currentPlayer.getPlayerColor()==WHITE)
        {
            return "WHITE";
        }else
        {
            return "BLACK";
        }
    }else
    {
        if(_opponentPlayer.getPlayerColor()==WHITE)
        {
            return "WHITE";
        }else
        {
            return "BLACK";
        }
    }
}
