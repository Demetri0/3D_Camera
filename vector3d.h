#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D{
    double X,Y,Z;
public:
    Vector3D(void);
    Vector3D(double _x, double _y, double _z);
    Vector3D(const Vector3D &rightOperand);
    void x(const double _x);
    void y(const double _y);
    void z(const double _z);
    double x()const;
    double y()const;
    double z()const;
    double& rx();
    double& ry();
    double& rz();
    Vector3D operator-(const Vector3D rightOperand);
    Vector3D operator+(const Vector3D rightOperand);
    Vector3D operator*(const double rightOperand);
    Vector3D operator/(const double rightOperand);
    void setXYZ(const double _x, const double _y, const double _z);
    void getXYZ(double &x, double &y, double &z);

    //Вычисление векторного произведения векторов
    inline Vector3D cross(Vector3D &rightOperand);
    //Вычисление магнитуды вектора
    inline double magnitude();
    //Нормализация вектора
    inline Vector3D normalize(double tolerance);
};

    Vector3D normalize(Vector3D Vector);
    double magnitute(Vector3D &vNormal);
    Vector3D cross(Vector3D V1, Vector3D V2);
#endif // VECTOR3D_H
