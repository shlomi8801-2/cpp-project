#include "console.h"
#include "utils.h"
#include "screen.h"

using namespace std;



int main(){
    cout << "program started!" << endl;
    init_console();
    Screen s;
    s.draw();
    while (1){
        showfps();
        usleep(16);
        
        
    }
    
}