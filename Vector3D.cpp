#include <iostream>
#include <cstring>
#include <cmath>
#include "Vector3D.h"

double E = 0.000001;

Vector3D::Vector3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::~Vector3D(){}

double Vector3D::getX() const{
    return x;
}

double Vector3D::getY() const{
    return y;
}

double Vector3D::getZ() const{
    return z;
}

Vector3D Vector3D::operator+(const Vector3D& secondVector) const{
    Vector3D vec(this->x + secondVector.x, this->y + secondVector.y, this->z + secondVector.z);
    return vec;
}

Vector3D Vector3D::operator-(const Vector3D& secondVector) const{
    Vector3D vec(this->x - secondVector.x, this->y - secondVector.y, this->z - secondVector.z);
    return vec;
}

Vector3D Vector3D::operator-() const{
    Vector3D vec(0 - this->x, 0 - this->y, 0 - this->z);
    return vec;
}

Vector3D Vector3D::operator*(double number) const{
    Vector3D vec(this->x * number, this->y * number, this->z * number);
    return vec;
}

Vector3D operator*(double number, const Vector3D & vector){
    return vector*number;
}

std::istream & operator>>(std::istream & iStream, Vector3D & vector){
    char input[30];
    iStream >> input;
    int wordCounter = 0;
    int counter = 0;
    char numbers[3][10] = {0};
    for(int i = 0; i < 30; i++){
        if(input[i] == '('){wordCounter = 1;}
        if(input[i] == ','){numbers[wordCounter-1][counter] = '\0' ; wordCounter++; counter = 0;}
        if(input[i] == '-'){numbers[wordCounter-1][counter] = input[i]; counter++;}
        if(input[i] >= '0' && input [i] <= '9'){numbers[wordCounter-1][counter] = input[i]; counter++;}
        if(input[i] == ')'){numbers[wordCounter-1][counter] = '\0' ; wordCounter++; counter = 0;}
    }
    int convertedNumber = 0;
    bool neg = false;
    for(int i = 0; i < strlen(numbers[0]); i++){
        if (i == 0 && numbers[0][i] == '-'){
            i++;
            neg = true;
        }
        if(neg){convertedNumber -= ((double)(numbers[0][i] - '0') * pow(10, strlen(numbers[0]) - i - 1) + E);}
        else {convertedNumber += ((double)(numbers[0][i] - '0') * pow(10, strlen(numbers[0]) - i - 1) + E);}

    }vector.x = convertedNumber; convertedNumber = 0; neg = false;

    for(int i = 0; i < strlen(numbers[1]); i++){
         if (i == 0 && numbers[1][i] == '-'){
            i++;
            neg = true;
        }
        if(neg){convertedNumber -= ((double)(numbers[1][i] - '0') * pow(10, strlen(numbers[1]) - i - 1) + E);}
        else {convertedNumber += ((double)(numbers[1][i] - '0') * pow(10, strlen(numbers[1]) - i - 1) + E);}
    }vector.y = convertedNumber; convertedNumber = 0; neg = false;

    for(int i = 0; i < strlen(numbers[2]); i++){
         if (i == 0 && numbers[2][i] == '-'){
            i++;
            neg = true;
        }
        if(neg){convertedNumber -= ((double)(numbers[2][i] - '0') * pow(10, strlen(numbers[2]) - i - 1) + E);}
        else {convertedNumber += ((double)(numbers[2][i] - '0') * pow(10, strlen(numbers[2]) - i - 1) + E);};
    }vector.z = convertedNumber; convertedNumber = 0;
}

std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector){
    oStream << "(" << vector.x << "," << vector.y << "," << vector.z << ")";
}

