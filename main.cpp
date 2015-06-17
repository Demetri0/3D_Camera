#include <GL/glut.h>
#include "camera.h"
#include "defines.h"
#include <iostream>


Camera C;
bool keysPressed[4];

void CreatePyramid(float x, float y, float z, int width, int height)
{
    // Ниже мы создаем пирамиду. Её составляют 4 треугольника по бокам и квадрат внизу.

    // 4 треугольника для сторон:
    glBegin(GL_TRIANGLES);
        // Задняя сторона
        glColor3ub(255, 0, 0);   glVertex3f(x, y + height, z);
        glColor3ub(0, 255, 255); glVertex3f(x - width, y - height, z - width);
        glColor3ub(255, 0, 255); glVertex3f(x + width, y - height, z - width);

        // Передняя сторона
        glColor3ub(255, 0, 0);   glVertex3f(x, y + height, z);
        glColor3ub(0, 255, 255); glVertex3f(x + width, y - height, z + width);
        glColor3ub(255, 0, 255); glVertex3f(x - width, y - height, z + width);

        // Левая сторона
        glColor3ub(255, 0, 0);   glVertex3f(x, y + height, z);
        glColor3ub(255, 0, 255); glVertex3f(x - width, y - height, z + width);
        glColor3ub(0, 255, 255); glVertex3f(x - width, y - height, z - width);

        // Правая сторона
        glColor3ub(255, 0, 0);   glVertex3f(x, y + height, z);
        glColor3ub(255, 0, 255); glVertex3f(x + width, y - height, z - width);
        glColor3ub(0, 255, 255); glVertex3f(x + width, y - height, z + width);
    glEnd();

    // Теперь дно пирамиды
    glBegin(GL_QUADS);
        glColor3ub(0, 0, 255); glVertex3f(x - width, y - height, z + width);
        glColor3ub(0, 0, 255); glVertex3f(x + width, y - height, z + width);
        glColor3ub(0, 0, 255); glVertex3f(x + width, y - height, z - width);
        glColor3ub(0, 0, 255); glVertex3f(x - width, y - height, z - width);
    glEnd();
}

void Draw3DSGrid()
{
    // Просто рисуем по 100 зеленых линий вертикально и горизонтально по осям X и Z

    glColor3ub(0, 255, 0);

    // Рисуем сетку 1х1 вдоль осей
    for(float i = -15; i <= 15; i+=0.05)
    {
        glBegin(GL_LINES);
            // Ось Х
            glVertex3f(-50, 0, i);
            glVertex3f(50, 0, i);

            // Ось Z
            glVertex3f(i, 0, -50);
            glVertex3f(i, 0, 50);
        glEnd();
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

//    glOrtho(0.0f, screen::width, screen::height, 0.0f, -1.0f, 1.0f);
    gluLookAt(C.getPosition().x(),C.getPosition().y(),C.getPosition().z(),
              C.getView().x(),C.getView().y(),C.getView().z(),
              C.getUpVector().x(),C.getUpVector().y(),C.getUpVector().z());
/*
    //Рисуем сетку
    Draw3DSGrid();

    // Создаем 4 пирамиды, просто для ориентирования в мире
    CreatePyramid(-6, 3, 6, 1, 6);
    CreatePyramid(6, 3, 6, 1, 6);
    CreatePyramid(6, 3, -6, 1, 6);
    CreatePyramid(-6, 3, -6, 1, 6);
    glTranslatef(C.Eye.x() , 0, C.Eye.z());

    // Теперь создаем 2 пирамиды, одна из которых перевернута.
    CreatePyramid(0, 2, 0, 1, 1);
    glRotatef(180, 1, 0, 0);
    CreatePyramid(0, -1, 0, 1, 1);
*/

    glBegin(GL_LINE_STRIP);
        glColor3ub(255,0,0);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f( 0.5,-0.5,-0.5);
        glVertex3f( 0.5, 0.5,-0.5);
        glVertex3f(-0.5, 0.5,-0.5);
        glVertex3f(-0.5,-0.5,-0.5);
      glEnd();
      glBegin(GL_LINE_STRIP);
        glColor3ub(0,255,0);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
        glVertex3f(-0.5,-0.5,0.5);
      glEnd();
      glBegin(GL_LINES);
        glColor3ub(0,0,255);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,-0.5);
      glEnd();
    //---
    glBegin(GL_LINE_STRIP);
      glColor3ub(255,0,0);
      glVertex3f(0.0,0.0,0.0);
      glVertex3f( 0.3,0.0,0.0);
      glVertex3f( 0.3, 0.3,0.0);
      glVertex3f(0.0, 0.3,0.0);
      glVertex3f(0.0,0.0,0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glColor3ub(0,255,0);
      glVertex3f(0.0,0.0,0.3);
      glVertex3f(0.3,0.0,0.3);
      glVertex3f(0.3,0.3,0.3);
      glVertex3f(0.0,0.3,0.3);
      glVertex3f(0.0,0.0,0.3);
    glEnd();
    glBegin(GL_LINES);
      glColor3ub(0,0,255);
      glVertex3f(0.0,0.0,0.3);
      glVertex3f(0.0,0.0,0.0);
      glVertex3f(0.3,0.0,0.3);
      glVertex3f(0.3,0.0,0.0);
      glVertex3f(0.3,0.3,0.3);
      glVertex3f(0.3,0.3,0.0);
      glVertex3f(0.0,0.3,0.3);
      glVertex3f(0.0,0.3,0.0);
    glEnd();
    //---

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
//    glOrtho( 0,screen::width,screen::height, 0, 0, 1 );
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int, int){
    switch (key){
        case 'a':
        case 'A':
//        case GLUT_KEY_LEFT:
            keysPressed[screen::Right]= false;
            keysPressed[screen::Left] = true;
            break;
        case 'd':
        case 'D':
//        case GLUT_KEY_RIGHT:
            keysPressed[screen::Left] = false;
            keysPressed[screen::Right]= true;
            break;
        case 'w':
        case 'W':
//        case GLUT_KEY_UP:
            keysPressed[screen::Down] = false;
            keysPressed[screen::Up]   = true;
            break;
        case 's':
        case 'S':
//        case GLUT_KEY_DOWN:
            keysPressed[screen::Up]   = false;
            keysPressed[screen::Down] = true;
            break;
        case 27:
            exit(0);
    }
}

void keyboardup(unsigned char key, int, int){
    switch (key){
        case 'a':
        case 'A':
//        case GLUT_KEY_LEFT:
            keysPressed[screen::Left] = false;
            break;
        case 'd':
        case 'D':
//        case GLUT_KEY_RIGHT:
            keysPressed[screen::Right]= false;
            break;
        case 'w':
        case 'W':
//        case GLUT_KEY_UP:
            keysPressed[screen::Up]   = false;
            break;
        case 's':
        case 'S':
//        case GLUT_KEY_DOWN:
            keysPressed[screen::Down] = false;
            break;
    }
}

void mouseMotion(int x, int y){
    C.mousePos.setXY(x,y);
//    std::cerr << "x("<<C.mousePos.x()<<"); y("<<C.mousePos.y()<<")" << std::endl;
}

void timer(int = 0){
    C.SetViewByMouse();
    display();
    if(keysPressed[screen::Left]) C.rotateAroundPoint(C.getView(), -Camera::kSpeed, 0, 1, 0);//C.rotateView(Camera::kSpeed*2,0,0,1);
    if(keysPressed[screen::Right])C.rotateAroundPoint(C.getView(), Camera::kSpeed, 0, 1, 0);//C.rotateView(-Camera::kSpeed*2,0,0,1);
    if(keysPressed[screen::Up])   C.moveCamera(Camera::kSpeed);
    if(keysPressed[screen::Down]) C.moveCamera(-Camera::kSpeed);
    glutTimerFunc(30, timer, 0);
}

int main(int argc, char **argv){
/*
 *void glutSetWindow(int win); //Эта функция делает окно win текущим. После этого можно производить различные операции над этим окном.
 *int glutGetWindow(void); //Эта функция позволяет вам определить какое в данный момент окно является активным. Функция возвращает дескриптор окна.
 *void glutSetWindowTitle(const char *title); //Изменяет заголовок окна
 *void glutPositionWindow(int x, int y);  //Изменяет расположение окна. Новые координаты левого верхнего угла окна (x,y)
 *void glutReshapeWindow(int width, int height); 	//Изменяет размеры окна. Новые размеры окна: width, height
 *void glutIconifyWindow(void); 	//Сворачивает окно в иконку.
 *void glutHideWindow(void); 	//Скрывает окно.
 *void glutShowWindow(void); 	//Показывает окно.
 *void glutFullScreen(void); 	//Развернуть окно на весь экран. При этом убираются с экрана заголовок окна и его остальные части, кроме содержимого окна, т.е. ваше приложение становится полноэкранным.
 *void glutSetCursor(int cursor); //GLUT_CURSOR_RIGHT_ARROW, GLUT_CURSOR_LEFT_ARROW, GLUT_CURSOR_INFO, GLUT_CURSOR_DESTROY, GLUT_CURSOR_HELP, GLUT_CURSOR_CYCLE, GLUT_CURSOR_SPRAY, GLUT_CURSOR_WAIT, GLUT_CURSOR_TEXT, GLUT_CURSOR_CROSSHAIR, GLUT_CURSOR_UP_DOWN, GLUT_CURSOR_LEFT_RIGHT, GLUT_CURSOR_TOP_SIDE, GLUT_CURSOR_BOTTOM_SIDE, GLUT_CURSOR_LEFT_SIDE, GLUT_CURSOR_RIGHT_SIDE, GLUT_CURSOR_TOP_LEFT_CORNER, GLUT_CURSOR_TOP_RIGHT_CORNER, GLUT_CURSOR_BOTTOM_RIGHT_CORNER, GLUT_CURSOR_BOTTOM_LEFT_CORNER, GLUT_CURSOR_INHERIT, GLUT_CURSOR_NONE, GLUT_CURSOR_FULL_CROSSHAIR.
 *void glutGameModeString(const char *string); //Эта функция определяет параметры устанавливаемого разрешения экрана, глубину цвета и частоту обновления экрана(в герцах). Например: glutGameModeString("640x480:16@72");
 *int glutEnterGameMode(void); //Войти в режим GAME MODE
 *void glutLeaveGameMode(void); //Выйти из режима GAME MODE
 */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screen::width, screen::height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Test3D_Camera");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(mouseMotion);
    glutFullScreen();
    glutSetCursor(GLUT_CURSOR_NONE);
    glutKeyboardUpFunc(keyboardup);
    glEnable(GL_ALPHA_TEST);        // Включаем прозрачность
    glAlphaFunc(GL_GREATER,0.0);    // - * -
//    glEnable (GL_BLEND);          // В источнике указаны ещё 2 функции, но прозрачность прекрасно работает и без них.
//    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    timer();
    glutMainLoop();
    return 0;
}
