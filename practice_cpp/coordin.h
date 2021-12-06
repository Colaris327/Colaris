// coordin.h -- structure templates and function prototype
// structure templates
#ifndef COORDIN_H_
#define COORDIN_H_

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

polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar ans;
    ans.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    ans.angle = atan2(xypos.y, xypos.x);
    return ans;
}

void show_polar(polar dapos)
{
    using namespace std;
    const double RAD_to_DEG = 57.29577951;
    cout << "distance = " << dapos.distance << endl;
    cout << "degree = " << dapos.angle * RAD_to_DEG << " degrees\n";
}
#endif

