#include "console.h"
#include "utils.h"
#include "screen.h"
#include "player.h"

#define fps 10
using namespace std;


int main(){
    cout << "program started!" << endl;
    init_console();
    hideCursor();
    Screen mainscreen;
    player p1(5,5,"dxawse");
    mainscreen.draw();
    while (1){
        showfps();
        if (check_kbhit()){
            char c=getc(stdin);
            p1.keyCheck(c);
        }
        p1.move(&mainscreen);
        p1.draw();
        sleep_ms((1.0/fps)*1000); // requires the 1.0 for it to stay not int
        
        
    }
    
}