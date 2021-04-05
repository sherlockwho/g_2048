#include <iostream>
#include <getopt.h>
#include "Game.h"
using namespace std;

int main(int argc, char *argv[])
{
    Game *game = new Game();
    char command; //用于接受命令行参数
    if (argc != 1)
    {
        while (EOF != (command = getopt(argc, argv, "t")))
        {
            switch (command)
            {
            case 't':
                game->g_test();
                break;
            default:
                cout << "Invalid option \"" << command << "\"" << endl;
                break;
            }
        }
    }
    else
    {
        game->g_game();
    }
    delete game;
    return 0;
}
