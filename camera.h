#ifndef CAMERA_H
#define CAMERA_H
#include "vector3d.h"
#include "point2d.h"

class Camera
{
    Vector3D Position;
    Vector3D View;
    Vector3D UpVector;
    Vector3D Strafe;
public:
    Point2D mousePos;
    static const float kSpeed = 0.03;

    Camera();
    Camera(const double posX, const double posY, const double posZ,
           const double eyeX, const double eyeY, const double eyeZ,
           const double vUpX, const double vUpY, const double vUpZ);
    Vector3D getView()const;
    Vector3D getPosition()const;
    Vector3D getUpVector()const;
    Vector3D getStrafe()const;
    void positionCamera(double const posX, const double posY, const double posZ,
                        double const eyeX, const double eyeY, const double eyeZ,
                        double const vUpX, const double vUpY, const double vUpZ);
    void SetViewByMouse();
    void moveCamera(const double speed);
    void strafeCamera(const double speed);
    void checkForMovement();
    void update();
    void look();
    void rotateView(const double angle,const  double x,const  double y,const  double z);
    void rotateAroundPoint(Vector3D vCenter, double const angle, const double x, const double y, const double z);
};

#endif // CAMERA_H
