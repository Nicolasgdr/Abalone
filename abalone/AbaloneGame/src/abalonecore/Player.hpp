/**
 * Project Untitled
 */


#ifndef _PLAYER_H
#define _PLAYER_H
#include "Color.h"
#include "Marble.hpp"
#include "Direction.h"
#include "State.h"
#include "vector"
#include "iostream"
class Player {
public: 

    Player()=default;
    /**
      getter of playerColor
     * @brief getPlayerColor
     * @return playerColor
     */
    inline Color getPlayerColor()
    {
        return playerColor;
    }
    
    /**
      remove a marble at the player
     * @brief remove
     * @param marble
     */
    void remove(Marble &marble){
        for(auto it = this->_marbles.begin();it!=this->_marbles.end();it++){
            if(marble.equals(*it)){
                this->_marbles.erase(it);
            }
        }
    }
    
    /**
      Constructor of Color
     * @brief Player
     * @param color
     */
    Player(Color color){
        this->playerColor=color;
        this->_marbles = std::vector<Marble>(14);
        this->_playerState = State::NEUTRAL;
    }
    /**
      getter of state
     * @brief getState
     * @return state
     */
    inline State getState()
    {
        return this->_playerState;
    }
    /**
      create a marble
     * @brief creatMarble
     * @param position
     * @param color
     * @param indice
     */
    void creatMarble(Position &position,Color& color, int indice)
    {
        this->_marbles.at(indice) = Marble(color,position);
    }
    /**
      setter of state
     * @brief setState
     * @param state
     */
    void setState(State state){
        this->_playerState = state;
    }
    /**
      getter of allMarbles
     * @brief getAllMarbles
     * @return
     */
    std::vector<Marble> &getAllMarbles()
    {
        return _marbles;
    }
    /**
      return marble at a position
     * @brief get_marble
     * @param position
     * @return
     */
    Marble &get_marble(Position &position)
    {
        for (Marble &m: this->_marbles ) {
            if(m.getPosition().equals(position)){
                return m;
            }
        }
        throw "Error";
    }
    bool marble_exist_at (Position &position)
    {
        for (Marble m: this->_marbles)
        {
            if (m.getPosition ().equals (position))
            {
                return true;
            }
        }
        return false;
    }
    /**
      return index of a marble
     * @brief IndexOf
     * @param marble
     * @return Integer
     */
    int IndexOf(Marble marble)
    {
        auto index =0;
        for(auto i=this->_marbles.begin();i!=this->_marbles.end();i++){
            if(i->equals(marble)){
                return index;
            }else{
                index++;
            }
        }
        return index;
    }
    /**
      check if the marble are the same color than the player
     * @brief marble_are_mines
     * @param elements
     * @return boolean
     */
    bool  marble_are_mines (std::vector<Position> elements)
    {
        auto cpt = 0;
        for (int i = 0; i < static_cast<int>(elements.size()); ++i)
        {
            for (Marble m : this->_marbles)
            {
                if (m.getPosition()==elements.at(i))
                    if(m.getColor() == this->getPlayerColor()){
                        cpt++;
                    }
            }
        }
        return cpt == static_cast<int>(elements.size());
    }
    /**
      check if the position of marble are mine
     * @brief correct
     * @param element
     * @return true /false
     */
    bool correct_position(std::vector<Position>element)
    {
        std::vector<Position>positions;
        if(element.size()==2){
            positions=std::vector<Position>(1);
            positions.at(0)=element.at(0);
        }else if(element.size()==3){

            positions=std::vector<Position>(2);
            positions.at(0)=element.at(0);
            positions.at(1)=element.at(1);
        }

        return isValid(positions) && marble_are_mines(positions);
    }
    /**
      return a marble as position given as argument
     * @brief get_marble_at
     * @param position
     * @return Marble
     */
    Marble &get_marble_at (Position &position)
    {
        for (Marble &m : this->getAllMarbles())
        {
            if (m.getPosition()==position)
            {
                return m;
            }
        }
        throw std::invalid_argument("EROR");
    }
    /**
      check if the marble is mine or not
     * @brief marble_is_mine
     * @param position
     * @return boolean
     */
    bool marble_is_mine (Position &position)
    {
        try {
            return get_marble_at (position).getColor() == this->getPlayerColor ();

        }  catch (std::invalid_argument &e) {
            return false;

        }

    }
private:
    /**
      Attribut of player
     * @brief playerColor
     */
    Color playerColor;
    /**
      Attribut of player
     * @brief _marbles
     */
    std::vector< Marble> _marbles;
    /**
      Attribut of player
     * @brief _playerState
     */
    State _playerState;
    bool isValid(std::vector<Position>position)
    {
        int compteur=0;
        for(Marble m:_marbles)
        {
            for(Position p:position)
            {
                if(m.getPosition()==p)
                {
                    compteur++;
                }
            }
        }

        return compteur==static_cast<int>(position.size());
    }


};

#endif //_PLAYER_H
