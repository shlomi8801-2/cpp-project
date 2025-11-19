#include "console.h"
#include "utils.cpp"
int main(){
    init_console();
    for (int x=0;x<100;x++){
        DrawAt(x,5,'#');
        sleep_ms(100);

    }
}