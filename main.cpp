#include "console.h"
#include "utils.h"
#include "screen.h"
#include "player.h"

using namespace std;



int main(){
    cout << "program started!" << endl;
    init_console();
    hideCursor();
    Screen s;
    player p1(5,5,"waxdsq");
    s.draw();
    while (1){
        showfps();
        if (check_kbhit()){
            char c=getc(stdin);
            p1.keyCheck(c);
        }
        p1.move();
        p1.draw();

        usleep(100000);
        
        
    }
    
}