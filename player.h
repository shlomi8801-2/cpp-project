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
        up,
        left,
        down,
        right,
        stay,
        dropItem
    };
    public:
    player(int _x,int _y,char keys[]);
    void move();
    void keyCheck(char key);
    void draw();
};