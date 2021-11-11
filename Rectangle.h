#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle // class name : Rectangle
{
    public:
        Rectangle(); // constructor
        ~Rectangle(); // destructer
        int GetHeight();
        int GetWidth();
    private:
        int xLow, yLow, height, width;
        // (xLow, yLow) is the bottom left corner
};