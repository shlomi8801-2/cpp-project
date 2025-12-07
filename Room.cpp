#include "Room.h"
#include "Layouts.h"


Room::Room(int id) : roomId(id), active(false), haveMods(false) {

    for (int i = 0; i < 10; i++) {
        objectsArr[i] = Object();  // AIR
    }

    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            mods[i][j] = ' ';
            visible[i][j] = false;
        }
    }
}

void Room::loadObjectsFromLayout(const Screen& layout) {
    int objectIndex = 0;

    for (int i = 0; i < MAX_Y_INGAME && i < layout.size(); i++) {
        for (int j = 0; j < MAX_X && j < layout[i].length(); j++) {
            char ch = layout[i][j];
            ObjectType type = ObjectType::AIR;
            bool shouldAdd = false;

            switch (ch) {
            case '\\':
                type = ObjectType::SWITCH_OFF;
                shouldAdd = true;
                break;
            case '/':
                type = ObjectType::SWITCH_ON;
                shouldAdd = true;
                break;
            case 'K':
                type = ObjectType::KEY;
                shouldAdd = true;
                break;
            case '@':
                type = ObjectType::BOMB;
                shouldAdd = true;
                break;
            case '!':
                type = ObjectType::TORCH;
                shouldAdd = true;
                break;
            case '#':
                type = ObjectType::SPRING;
                shouldAdd = true;
                break;
            case '*':
                type = ObjectType::OBSTACLE;
                shouldAdd = true;
                break;
            case '?':
                type = ObjectType::RIDDLE;
                shouldAdd = true;
                break;
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                type = ObjectType::DOOR;
                shouldAdd = true;
                break;
            default:
                break;
            }

            if (shouldAdd && objectIndex < 10) {
                Point pos(j, i);
                objectsArr[objectIndex] = Object(type, pos);

                if (type == ObjectType::DOOR) {
                    objectsArr[objectIndex].setSprite(ch);
                }

                objectIndex++;
            }
        }
    }

    for (int i = objectIndex; i < 10; i++) {
        objectsArr[i] = Object(ObjectType::AIR, Point(-1, -1));
    }
}


void Room::initializeRooms(Room** rooms) { rooms[0]->objectsArr = Object::createObjectArr(0); }

