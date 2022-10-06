#include "Controller.h"

void Controller::start()
{
    this->view.print_msg("HELLO WELCOME TO ABALONE" );

    this->view.print_msg("CHOOSE YOUR COLOR w==> white b==>black");
    auto color = this->view.player_color();
    this->game.initialized(color);

    do {
        try {
            this->view.displayBoard(this->game);
            this->view.printPlayer(this->game.get_current_player());
            std::string input = this->view.playerInput();
            std::vector<AbaPro> abapro = this->view.tabInput(input);
            std::vector<Position> positions = this->game.convert(abapro);
            game.move(positions);
        }  catch (std::invalid_argument &
                e) {
            view.print_msg(e.what());
        }
    } while (!this->game.checkWin());

}
