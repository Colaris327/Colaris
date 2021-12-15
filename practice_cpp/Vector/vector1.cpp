#include <cmath>
#include "vector.h"

using std::cos;
using std::sin;
using std::atan2;
using std::cout;

namespace VECTOR
{
    const double RAD_TO_DEG = 57.2957795130823;

    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        if (x == 0 && y == 0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    void Vector::set_x() // set x from polar coordinate
    {
        x = mag * cos(ang);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = 'r';
    }

    Vector::Vector(double n1, double n2, char form)
    {
        mode = form;
        if (form == 'r')
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == 'p')
        {
            mag = n1;
            ang = n2 / RAD_TO_DEG;
            set_x();
            set_y();
        }
        else
        {
            cout << "Error! vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = 'r';
        }
    }

    void Vector::set(double n1, double n2, char form)
    {
        mode = form;
        if (form == 'r')
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == 'p')
        {
            mag = n1;
            ang = n2 / RAD_TO_DEG;
            set_x();
            set_y();
        }
        else
        {
            cout << "Error! vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = 'r';
        }
    }

    Vector::~Vector()
    {
    }

    void Vector::polar_mode()
    {
        mode = 'p';
    }

    void Vector::rect_mode()
    {
        mode = 'r';
    }

    Vector Vector::operator+(const Vector & B) const
    {
        return Vector(x + B.x, y + B.y);
    }

    Vector Vector::operator-(const Vector & B) const
    {
        return Vector(x - B.x, y - B.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    // friend
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == 'r')
            os << "(x, y) = (" << v.x << ", " << v.y << ") ";
        else if (v.mode == 'p')
            os << "(m, a) = (" << v.mag << ", " << v.ang << ") "; 
        else
            os << "Invalid mode";
        return os;
    }
}