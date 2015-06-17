#include "vector3d.h"
#include <math.h>

Vector3D::Vector3D(void){
    X=Y=Z=0.0;
}
Vector3D::Vector3D(double _x, double _y, double _z)
    :X(_x),Y(_y),Z(_z){}
Vector3D::Vector3D(const Vector3D &rightOperand)
    :X( rightOperand.x() ), Y( rightOperand.y() ), Z( rightOperand.z() ){}

double Vector3D::x()const{
    return X;
}
double Vector3D::y()const{
    return Y;
}
double Vector3D::z()const{
    return Z;
}
double& Vector3D::rx(){
    return X;
}
double& Vector3D::ry(){
    return Y;
}
double& Vector3D::rz(){
    return Z;
}

Vector3D Vector3D::operator -(const Vector3D rightOperand){
    return Vector3D( X-rightOperand.x(), Y-rightOperand.y(), Z-rightOperand.z() );
}
Vector3D Vector3D::operator +(const Vector3D rightOperand){
    return Vector3D( X+rightOperand.x(), Y+rightOperand.y(), Z+rightOperand.z() );
}
Vector3D Vector3D::operator *(const double rightOperand){
    return Vector3D( X*rightOperand, Y*rightOperand, Z*rightOperand );
}
Vector3D Vector3D::operator /(const double rightOperand){
    return Vector3D( X/rightOperand, Y/rightOperand, Z/rightOperand );
}

void Vector3D::x(double _x){
    X = _x;
}
void Vector3D::y(double _y){
    Y = _y;
}
void Vector3D::z(double _z){
    Z = _z;
}

void Vector3D::setXYZ(double _x, double _y, double _z)
{
    X = _x;
    Y = _y;
    Z = _z;
}
void Vector3D::getXYZ(double &x, double &y, double &z){
    x = X;
    y = Y;
    z = Z;
}

inline Vector3D Vector3D::cross(Vector3D &rightOperand){
    return Vector3D(Y*rightOperand.z() - Z*rightOperand.y(),
                    Z*rightOperand.x() - X*rightOperand.z(),
                    X*rightOperand.y() - Y*rightOperand.x());
}
Vector3D cross(Vector3D V1, Vector3D V2){
    return Vector3D(V1.y()*V2.z() - V1.z()*V2.y(),
                    V1.z()*V2.x() - V1.x()*V2.z(),
                    V1.x()*V2.y() - V1.y()*V2.x());
}

inline double Vector3D::magnitude(){
    return sqrt( (X*X) + (Y*Y) + (Z*Z) );
}
double magnitute(Vector3D &normal){
    return sqrt( (normal.x()*normal.x()) + (normal.y()*normal.y()) + (normal.z()*normal.z()) );
}

inline Vector3D Vector3D::normalize(double tolerance){
    Vector3D result;

    double length = magnitude();
    if(length >= tolerance){
        result.setXYZ(X/length, Y/length, Z/length);
    }
    return result;
}
Vector3D normalize(Vector3D vector){
    double length = magnitute(vector);
    return vector / length;
}
