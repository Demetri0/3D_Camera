#include "point2d.h"

Point2D::Point2D()
    :X(0), Y(0){}
Point2D::Point2D(const double _x, const double _y)
    :X(_x), Y(_y){}

double Point2D::x() const{
    return X;
}
double Point2D::y() const{
    return Y;
}
void Point2D::x(const double _x){
    X = _x;
}
void Point2D::y(const double _y){
    Y = _y;
}
double& Point2D::rx(){
    return X;
}
double& Point2D::ry(){
    return Y;
}
void Point2D::setXY(const double _x, const double _y){
    X = _x;
    Y = _y;
}

Point2D Point2D::operator+(const Point2D &rightOperand)const{
    return Point2D( X+rightOperand.x(), Y+rightOperand.y() );
}

Point2D Point2D::operator-(const Point2D &rightOperand)const{
    return Point2D( X-rightOperand.x(), Y-rightOperand.y() );
}

Point2D Point2D::operator*(const double &rightOperand)const{
    return Point2D( X*rightOperand, Y*rightOperand );
}

Point2D Point2D::operator/(const double &rightOperand)const{
    return Point2D( X/rightOperand, Y/rightOperand );
}
void Point2D::operator+=(const Point2D &rightOperand){
    X += rightOperand.x();
    Y += rightOperand.y();
}
void Point2D::operator+=(const double &rightOperand){
    X += rightOperand;
    Y += rightOperand;
}
void Point2D::operator-=(const Point2D &rightOperand){
    X -= rightOperand.x();
    Y -= rightOperand.y();
}
void Point2D::operator-=(const double &rightOperand){
    X -= rightOperand;
    Y -= rightOperand;
}
void Point2D::operator*=(const double &rightOperand){
    X *= rightOperand;
    Y *= rightOperand;
}
void Point2D::operator/=(const double &rightOperand){
    X *= rightOperand;
    Y *= rightOperand;
}
/*
bool operator==(const Point2D &rightOperand)const{
    if( (X == rightOperand.x()) && (Y == rightOperand.y()) )
        return true;
    return false;
}
bool operator==(const double &rightOperand)const{
    if( (X == rightOperand) && (Y == rightOperand) )
        return true;
    return false;
}
*/
