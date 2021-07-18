#ifndef __COLLECTION_H_
#define __COLLECTION_H_
#include "points.h"
#include <list>
#include <vector>

class collection
{
private:
    std::list<Points> points;
public:
    void addPoint(int x,int y);
    void addPoint(const Points& ref);
    void DisplayAll();
    int CountPointsInQuadrant(int quadrant);
    int CountPointsOnCircleBoundary(int radius);
    int CountPointsInCircle(int radius);
    std::list<Points> FindPointsInQuadrant(int quadrant);
    std::list<Points> FindPointsOnCircleBoundary(int radius);
    std::list<Points> FindPointsInCircle(int radius);
     
};







#endif // #ifndef __COLLECTION_H_