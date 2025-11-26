#pragma once
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