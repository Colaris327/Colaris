#include <iostream>
using namespace std;

class Rectangle // class name : Rectangle
{
    friend ostream& operator<< (ostream&, Rectangle&);
    public:
        int Rectangle::operator==(const Rectangle&);
        Rectangle(); // constructor
        ~Rectangle(); // destructer
        int GetHeight();
        int GetWidth();
    private:
        int xLow, yLow, height, width;
        // (xLow, yLow) is the bottom left corner
};

int Rectangle::GetHeight() {return height;}
int Rectangle::GetWidth() {return width;}

Rectangle::Rectangle(int x, int y, int h, int w)
{
    xLow = x;
    yLow = y;
    height = h;
    width = w;
}

int Rectangle::operator==(const Rectangle& s)
//overload "=="
{
    if (this == &s) return 1;
    else if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width)) return 1;
    return 0;
}

ostream& Rectangle::operator<<(ostream& os, Rectangle& r)
{
    os << "Position is: " << r.xLow << " ";
    os << r.yLow << endl;
    os << "Height is: " << r.height << endl;
    os << "Width is: " << r.width << endl;
    return os;
}

int main() {
    Rectangle r(1, 3, 6, 6), t(1, 3, 6, 6);
    if (r == t) cout << 1 << endl;
    cout << r;
    return 0;
}
    