#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
    double X,Y;
public:
    Point2D();
    Point2D(const double _x, const double _y);
    double x()const;
    double y()const;
    void x(const double _x);
    void y(const double _y);
    double& rx();
    double& ry();
    void setXY(const double _x, const double _y);
    Point2D operator+(const Point2D &rightOperand)const;
    Point2D operator-(const Point2D &rightOperand)const;
    Point2D operator*(const double &rightOperand)const;
    Point2D operator/(const double &rightOperand)const;
    void operator+=(const Point2D &rightOperand);
    void operator+=(const double &rightOperand);
    void operator-=(const Point2D &rightOperand);
    void operator-=(const double &rightOperand);
    void operator*=(const double &rightOperand);
    void operator/=(const double &rightOperand);
    bool operator==(const Point2D &rightOperand)const;
    bool operator==(const double &rightOperand)const;
};

#endif // POINT2D_H
