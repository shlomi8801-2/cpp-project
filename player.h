#pragma once
class item{

};
class player{
    char controlKeys[6];
    item* inv;
    int vx =0;//velocity at x axis
    int vy=0; //velocity at y axis
    int x;
    int y;
    enum movement {
        up,
        left,
        down,
        right,
        stay,
        dropItem
    };
    public:
    player(int _x=0,int _y=0,char* keys = "waxdsq");
    void move();
    void keyCheck(char key);
};