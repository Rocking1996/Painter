#ifndef GRAPH_H
#define GRAPH_H

/************************************************
 *Graph类
 *所有图形继承的父类
 *实现所有基本操作
 *
 *如果想为图形添加新功能，需要在该类中添加，并在
 *其他图形中重写
************************************************/

#include "Basic.h"
#include "Tool.h"
#include <vector>
#include <iostream>
#include <GL/glut.h>
using namespace std;


class Graph
{
    /**********************
     *有唯一标识一个图形的id
     *图形的形状s，使用枚举类型
     *该图形是否设置好
     *该图形的点集
     *图形的参数
    ***********************/
public:
    int id;    //图形id
    Shape s;   //形状
    bool ok;   //图形是否绘制完成
    GraphConfig conf;  //基本参数
    vector<Point> pArray;  //点集

public:
    Graph(int i): id(i), s(LINE), ok(false) {}
    ~Graph() {}


    //基本参数设置
    bool finish();                          //绘制结束
    void setColor(const Color &col);        //设置颜色
    void setLineSize(LineSize lineSize);    //设置粗细
    void setDash(bool isDashes);            //设置虚线
    void setpolymode(bool isfilled);        //设置填充
    void setConfig(const GraphConfig &config);  //所有设置

    //点设置
    virtual void setPoint(int x, int y);     //加入顶点，用于绘制
    virtual void changePoint(int x, int y);  //修改顶点，用于绘制与动作
    virtual double getDistance(int x, int y){} //计算点与图像的距离，用于鼠标选择

    virtual void copy(Graph*);   //复制自己，用于镜像


    //图形动作
    virtual void draw() = 0;   //绘制该图形
    void move(int, int);   //位移
    virtual void rotate() {};   //旋转
    virtual void drag(const Point &originalPoint, int x, int y);  //拉扯
    virtual void getRectangle(Point &, Point &);

protected:
    //配置
    void config();
};



#endif // GRAPH_H
