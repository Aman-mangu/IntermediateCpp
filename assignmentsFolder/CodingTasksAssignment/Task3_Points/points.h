#ifndef __POINTS_H_
#define __POINTS_H_
#include <iostream>
#include<cmath>
class Points
{
private:
    int m_x;
    int m_y;
public:
    Points();
    Points(int x,int y);
    Points(int p);
    double DistanceBtw2Points(Points& p2);
    Points& FindHorizontalFlip();
    Points& FindVerticleFlip();
    Points& DisplacePoint(int dx,int dy);
    void Display();
    int getX();
    int getY();
    ~Points();
};



#endif // #ifndef __POINTS_H_