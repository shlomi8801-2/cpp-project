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
    char sprite = 'a';
    enum movement {
        right,
        down,
        left,
        up,
        stay,
        dropItem
    };
    public:
    player(int _x,int _y,char const keys[]);
    void move();
    void keyCheck(char key);
    void draw();
};