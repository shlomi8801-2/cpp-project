#include "console.h"
#include "utils.h"
#include <SFML/Window.hpp> // for continious button presses(holding a button) use -lsfml-<somthing> like "window"

using namespace std;
using namespace sf;
int main(){
    cout << "program started!" << endl;
    init_console();
    // for (int x=0;x<100;x++){
    //     DrawAt(x,x,'#');
        
    // }
    // sleep_ms(100);
    // while (1){
        // showfps();
        // sleep_ms(10);
        
        
    // }
        using sf::Keyboard;

    while( 1 ) { // <== probably a bad way
        if( Keyboard::isKeyPressed( Keyboard::Escape ) )
            break;
        else if( Keyboard::isKeyPressed( Keyboard::Left ) )
            std::cout << "Left Key pressed\n";
        else if( Keyboard::isKeyPressed( Keyboard::Right ) )
            std::cout << "Right key pressed\n";
        else if( Keyboard::isKeyPressed( Keyboard::Up ) )
            std::cout << "Up key pressed\n";
        else if( Keyboard::isKeyPressed( Keyboard::Down ) )
            std::cout << "Down key pressed\n";
    }
}