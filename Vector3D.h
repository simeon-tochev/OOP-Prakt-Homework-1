#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <iostream>

class Vector3D
{
    public:
        /// Constructors and Destructors
        Vector3D();
        Vector3D(double, double, double);
        ~Vector3D();

        /// Getters
        double getX() const;
        double getY() const;
        double getZ() const;

        /// Operators
        Vector3D operator+(const Vector3D&) const;
        Vector3D operator-(const Vector3D&) const;
        Vector3D operator-() const;
        Vector3D operator*(double) const;

        /// Friends
        friend Vector3D operator*(double, const Vector3D);
        friend std::istream & operator>>(std::istream&, Vector3D&);
        friend std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector);

    private:
        double x;
        double y;
        double z;
};

#endif // VECTOR3D_H
