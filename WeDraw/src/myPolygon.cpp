#include "myPolygon.h"

void myPolygon::draw()
{
    config();
    //ֻ���������㣬ֻ�ܻ�һ��ֱ��
    if (pArray.size() == 2) {
        glBegin(GL_LINE_STRIP);
            glVertex2i(pArray[0].x, pArray[0].y);
            glVertex2i(pArray[1].x, pArray[1].y);
        glEnd();
        return;
    }

    //�������
    for (int i = 0; i < 2; i++) {
        glBegin(GL_POLYGON);
        for (int i = 0; i < pArray.size(); i++)
            glVertex2i(pArray[i].x, pArray[i].y);
        glEnd();
        if (!conf.frame) return;
        glColor3f(0.0, 0.0, 0.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
}

void myPolygon::setPoint(int x, int y)
{
    if (ok) return;
    //��ֹ��һ����δ����
    if (pArray.empty())
        pArray.push_back(Point(x, y));
    pArray.push_back(Point(x, y));
}


void myPolygon::changePoint(int x, int y)
{
    if (pArray.empty())
        return;
    int last = pArray.size()-1;
    pArray[last].x = x;
    pArray[last].y = y;
}


void myPolygon::drag(const Point &originalPoint, int x, int y)
{
    Point *temp = &pArray[0];
    int minVal = PPDistance(originalPoint, pArray[0]);
    int size = conf.lineSize + 2;

    for (int i = 1; i < pArray.size(); i++)
    {
        double dis = PPDistance(originalPoint, pArray[i]);
        if (dis < minVal) {
            minVal = dis;
            temp = &pArray[i];
        }
    }

    temp->x += x;
    temp->y += y;
}

void myPolygon::rotate()
{

}

double myPolygon::getDistance(int x, int y)
{
    double minVal = 99999999;
    Point p(x, y);
    //p0, p1, ... pn-1
    for (int i = 0; i < pArray.size()-1; i++) {
        double dis = PLDistance(p, pArray[i], pArray[i+1]);
        if (dis < minVal)
            minVal = dis;
    }

    //pn-1, p0
    double dis = PLDistance(p, pArray[0], pArray[pArray.size()-1]);
    if (dis < minVal)
        minVal = dis;

    return minVal;
}


/*********************************************����**********************************************/
void foldLine::draw()
{
    config();
    for (int i = 0; i < pArray.size()-1; i++) {
        glBegin(GL_LINE_STRIP);
            glVertex2i(pArray[i].x, pArray[i].y);
            glVertex2i(pArray[i+1].x, pArray[i+1].y);
        glEnd();
    }

}


double foldLine::getDistance(int x, int y)
{
    double minVal = 99999999;
    Point p(x, y);
    for (int i = 0; i < pArray.size()-1; i++) {
        double dis = PLDistance(p, pArray[i], pArray[i+1]);
        if (dis < minVal)
            minVal = dis;
    }

    return minVal;
}


void foldLine::rotate()
{

}