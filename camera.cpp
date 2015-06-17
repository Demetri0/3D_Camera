#include "camera.h"
#include "point2d.h"
#include "defines.h"
#include <math.h>
#include <iostream>
#include <GL/glut.h>
#include <X11/Xcursor/Xcursor.h>

Camera::Camera()
{
    Position = Vector3D();
    View     = Vector3D(0.0, 1.0, 0.5);
    UpVector = Vector3D(0.0, 0.0, 1.0);
}

Camera::Camera(const double posX, const double posY, const double posZ, const double eyeX, const double eyeY, const double eyeZ, const double vUpX, const double vUpY, const double vUpZ){
    Position = Vector3D(posX, posY, posZ);
    View     = Vector3D(eyeX, eyeY, eyeZ);
    UpVector = Vector3D(vUpX, vUpY, vUpZ);
}

Vector3D Camera::getPosition()const{
    return Position;
}
Vector3D Camera::getView()const{
    return View;
}
Vector3D Camera::getUpVector()const{
    return UpVector;
}
Vector3D Camera::getStrafe()const{
    return Strafe;
}

void Camera::positionCamera(const double posX,const double posY,const double posZ,const double eyeX,const double eyeY,const double eyeZ,const double vUpX,const double vUpY,const double vUpZ){
    Position = Vector3D(posX, posY, posZ);
    View     = Vector3D(eyeX, eyeY, eyeZ);
    UpVector = Vector3D(vUpX, vUpY, vUpZ);
}

void Camera::moveCamera(const double speed){
    Vector3D vVector = View - Position;

//    Position *= speed; //Возможно реализовать скалярное произведение векторов?

    Position.rx() += vVector.x() * speed;
    Position.rz() += vVector.z() * speed;
    View.rx() += vVector.x() * speed;
    View.rz() += vVector.z() * speed;
}

void Camera::rotateView(const double angle, const double x, const double y, const double z){
    Vector3D vNewView;
    Vector3D vView = View - Position;

    double cosTheta = (double)cos(angle);
    double sinTheta = (double)sin(angle);

    vNewView.rx() = (cosTheta +(1 - cosTheta) * x * x) * vView.x();
    vNewView.rx() +=( (1 - cosTheta) * x * y - z * sinTheta) * vView.y();
    vNewView.rx() +=( (1 - cosTheta) * x * z + y * sinTheta) * vView.z();

    vNewView.ry() = ((1 - cosTheta) * x * y + z * sinTheta)   * vView.x();
    vNewView.ry() +=(cosTheta + (1 - cosTheta) * y * y)   * vView.y();
    vNewView.ry() +=((1 - cosTheta) * y * z - x * sinTheta)   * vView.z();

    vNewView.rz() = ((1 - cosTheta) * x * z - y * sinTheta)   * vView.x();
    vNewView.rz() +=((1 - cosTheta) * y * z + x * sinTheta)   * vView.y();
    vNewView.rz() +=(cosTheta + (1 - cosTheta) * z * z)   * vView.z();

    View = Position + vNewView;
}

void Camera::SetViewByMouse(){
    int middleX = screen::width  >> 1;
    int middleY = screen::height >> 1;
    float angleY = 0.0f;
    float angleZ = 0.0f;
    static float currentRotX = 0.0f;

    if((mousePos.x() == middleX) && (mousePos.y() == middleY)) return;

    Display *display = XOpenDisplay (NULL);
    XWarpPointer (display, None, DefaultRootWindow(display), 0,0,0,0, middleX, middleY);
    XFlush (display);
    XCloseDisplay (display);

    angleY = (double)(middleX - mousePos.x())/1000.0f;
    angleZ = (double)(middleY - mousePos.y())/1000.0f;

    static float lastRotX = 0.0f;

    lastRotX = currentRotX;

    if(currentRotX > 1.0f){
        currentRotX = 1.0f;

        if(lastRotX != 1.0f){
            Vector3D vAxis = cross(View - Position, UpVector);
            vAxis = normalize(vAxis);

            rotateView( 1.0f - lastRotX, vAxis.x(), vAxis.y(), vAxis.z() );
        }
    }else if(currentRotX < - 1.0f){
        currentRotX = -1.0f;
        if(lastRotX != -1.0f){
            Vector3D vAxis = cross(View - Position, UpVector);
            vAxis = normalize(vAxis);

            rotateView( -1.0f - lastRotX, vAxis.x(), vAxis.y(), vAxis.z() );
        }
    }else{
        Vector3D vAxis = cross(View - Position, UpVector);
        vAxis = normalize(vAxis);

        rotateView(angleZ, vAxis.x(), vAxis.y(), vAxis.z() );
    }
    rotateView(angleY, 0, 1, 0);
}

void Camera::rotateAroundPoint(Vector3D vCenter, const double angle, const double x, const double y, const double z){
    Vector3D vNewPosition;

    Vector3D vPos = Position - vCenter;

    double cosTheta = (double)cos(angle);
    double sinTheta = (double)sin(angle);

    vNewPosition.rx()  = (cosTheta + (1-cosTheta)*x*x) * vPos.x();
    vNewPosition.rx() += ((1-cosTheta)*x*y-z*sinTheta) * vPos.y();
    vNewPosition.rx() += ((1-cosTheta)*x*z+y*sinTheta) * vPos.z();

    vNewPosition.ry()  = ((1-cosTheta)*x*y+z*sinTheta) * vPos.x();
    vNewPosition.ry() += (cosTheta+(1-cosTheta)*y*y)   * vPos.y();
    vNewPosition.ry() += ((1-cosTheta)*y*z-x*sinTheta) * vPos.z();

    vNewPosition.rz()  = ((1-cosTheta)*x*z-y*sinTheta) * vPos.x();
    vNewPosition.rz() += ((1-cosTheta)*y*z+x*sinTheta) * vPos.y();
    vNewPosition.rz() += (cosTheta+(1-cosTheta)*z*z)   * vPos.z();

    Position = vCenter + vNewPosition;
}
