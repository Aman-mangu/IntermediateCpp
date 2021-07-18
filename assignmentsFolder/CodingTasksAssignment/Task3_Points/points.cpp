#include "points.h"

Points::Points():m_x(0),m_y(0){}
Points::Points(int x,int y):m_x(x),m_y(y){}
Points::Points(int p):m_x(p),m_y(p){}
double Points::DistanceBtw2Points(Points& p2)
{
    double distance;
    distance=sqrt(pow(((this->m_x)-(p2.m_x)),2)+pow(((this->m_y)-(p2.m_y)),2));
    return distance;
}
Points& Points::FindHorizontalFlip()
{
    int p;
    p=-(this->m_x);
    this->m_x=p;
    return (*this);
}
Points& Points::FindVerticleFlip()
{
    int p;
    p=-(this->m_y);
    this->m_y=p;
    return (*this);
}
Points& Points::DisplacePoint(int dx,int dy)
{
    this->m_x=this->m_x+dx;
    this->m_y=this->m_y+dy;
    return (*this);
}
void Points::Display()
{
    std::cout<<m_x<<" "<<m_y<<std::endl;
}
int Points::getX()
{
    return m_x;
}
int Points::getY()
{
    return m_y;
}



Points::~Points()
{}