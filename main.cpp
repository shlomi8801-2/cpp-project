#include "console.h"
#include "utils.h"
#include "screen.h"
#include "player.h"

#define fps 10
using namespace std;


int main(){
    cout << "program started!" << endl;
    //required for the terminal
    init_console();
    hideCursor();
    //define screen object(has all the array of objects)
    Screen mainscreen;
    //define a player object with startx starty postions and keys at this order: right down left up stay dispose item
    player p1(5,5,"dxawse",&mainscreen);
    //clear the screen and draw from the arrays in mainscreen object(by default has walls but can decide to not draw them)
    mainscreen.draw();
    //main loop handles key checking and delay for constant fps(mostly)
    while (1){
        showfps();
        if (check_kbhit()){
            char c=get_single_char();
            p1.keyCheck(c);
        }
        p1.move();
        p1.draw();
        sleep_ms((1.0/fps)*1000); // requires the 1.0 for it to stay not int
    }
    
}