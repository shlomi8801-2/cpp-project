#include "console.h"
#include "utils.h"
#include "screen.h"
#include "player.h"
#include "Layouts.h"
#include "MainMenu.h"

#define fps 10
using namespace std;


int main(){
    cout << "program started!" << endl;
    init_console();
    hideCursor();

    Screen mainscreen;

    // Show main menu first
    mainmenu::showMainMenu(&mainscreen);
    int choice = mainmenu::getMenuChoice();

	// I want to move this to MainMenu namespace but for now its ok here
	// Also I want to add instructions screen later

    if (choice == 3) {
        // Quit
        return 0;
    }

    // Start game
    player p1(5, 5, "dxawse", &mainscreen);
    mainscreen.setPlayer(0,&p1);
    int currentLevel = 1;
    levels::changeLayout(currentLevel, &mainscreen);

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
	return 0;
}