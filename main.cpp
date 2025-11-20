#include "console.h"
#include "utils.h"
using namespace std;
int main(){
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