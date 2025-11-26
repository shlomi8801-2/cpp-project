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
    
    // for (int x=0;x<100;x++){
    //     DrawAt(x,x,'#');
        
    // }
    // sleep_ms(100);
    while (1){
        showfps();
        sleep_ms(10);
        
        
    }
    
}