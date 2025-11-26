#include "console.h"
#include "utils.h"
#include "screen.h"

using namespace std;
class item{

};

class player{
    char* controlKeys[6];
    item* inv;
    enum movement {
        up,
        down,
        left,
        right,
        stay,
        dropItem
    };
    void move(char key){
        
    }
};
int main(){
    cout << "program started!" << endl;
    init_console();
    Screen s;
    s.draw();
    while (1){
        showfps();
        usleep(1);
        
        
    }
    
}