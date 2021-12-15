#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{
    class Vector
    {
        private:
            double x; // horizontal value
            double y; // vertical value
            double mag; // length
            double ang; // direction
            char mode; // 'r' = rectangular, 'p' = polar
        // private method for setting values
            void set_x();
            void set_y();
            void set_mag();
            void set_ang();
        public:
            Vector();
            Vector(double n1, double n2, char form = 'r');
            void set(double n1, double n2, char form = 'r');
            ~Vector();
            double xval() const {return x;}; // report x value
            double yval() const {return y;};
            double magval() const {return mag;};
            double angval() const {return ang;};
            void polar_mode(); // set mode 'p'
            void rect_mode();
        // operator overloading
            Vector operator+(const Vector & B) const;
            Vector operator-(const Vector & B) const; // overload minus
            Vector operator-() const; // overload negative sign
            Vector operator*(double n) const;
        // fridend
            friend Vector operator*(double n, const Vector & a);
            friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}
#endif