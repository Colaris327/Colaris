#include <iostream>
#include <cmath>
using namespace std;

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

polar Rect_to_polar(rect xypos);
void Show_polar(polar dapos);

int main()
{
    rect rplace;
    polar pplace;
    cout << "Enter x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = Rect_to_polar(rplace);
        Show_polar(pplace);
        cout << "Next numbers(q to quit): ";
    }
    return 0;
}

polar Rect_to_polar(rect xypos)
{
    polar ans;
    ans.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    ans.angle = atan2(xypos.y, xypos.x);
    return ans;
}

void Show_polar(polar dapos)
{
    const double RAD_to_DEGREE = 57.29577951;
    cout << "distance = " << dapos.distance << endl;
    cout << "angle = " << RAD_to_DEGREE * dapos.angle << " degrees" << endl;
}