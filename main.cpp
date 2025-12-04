#include "console.h"
#include "utils.h"
#include "Screen.h"
#include "Player.h"

#include "MainMenu.h"

#include "Blocks.h"

#define FPS 10
using namespace std;

int main()
{
    cout << "program started!" << endl;
    init_console();
    hideCursor();
    int currentLevel = 1;
    Screen mainscreen(&currentLevel);

    

    // Start game
    Player p1(77, 5, "dxawse", &mainscreen); // maybe it doesnt look friendly but i think its the best way to send key binds if we dont want another array with players
    mainscreen.setPlayer(0, &p1);
    Player p2(77, 10, "lmjiko", &mainscreen,'b');
    mainscreen.setPlayer(1, &p2);

    
    //moved the change layout to draw function
    mainscreen.draw();
    while (1)
    {
        showfps();
        //run all the "tick" functions
       if (check_kbhit())
        {
            char c = get_single_char();
            mainscreen.keyCheck(c);
        }
        mainscreen.tick();
        sleep_ms((1.0 / FPS) * 1000); // requires the 1.0 for it to stay not int
    }
    return 0;
}