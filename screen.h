class object{
    int x;
    int y;
    char sprite;
    bool filled = false;
    // friend ostream& operator<<(ostream& out, const object& s) {
    //     return out << s.sprite;
    // }
    public:
        char getSprite() { return sprite;}
};
class Screen{
    int width = 80;
    int height = 25;
    object* arr;
    Screen();
    object* getatxy(const int x,const int y);
    void setatxy(const int x, const int y,object* obj);
    void draw();
};
