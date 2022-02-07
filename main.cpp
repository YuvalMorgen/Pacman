#include "Game.h"
#include "Definitions.h"

int main() {
    bool KeepPlaying = true;
    Game* game = new Game;
    int status = game->init();

    if(status == EXIT) KeepPlaying = false;
    
    while(KeepPlaying) {
        game->run();
        Sleep(500);
        delete game;
        game = new Game;
        status = game->init();
        if(status == EXIT) KeepPlaying = false;
    }
}

