#include "collection.h"

void collection::addPoint(int x, int y)
{
    points.push_back(Points(x,y));
}
void collection::addPoint(const Points &ref)
{
    points.push_back(ref);
}
void collection::DisplayAll()
{
    for (Points &ref : points)
        ref.Display();
}
int collection::CountPointsInQuadrant(int quadrant)
{
    int count=0;
    std::list<Points>::iterator itr;
    switch (quadrant)
    {
        case 1:
        {
            for(itr=points.begin();itr!=points.end();itr++)
            {
                if(((itr->getX())>0) && ((itr->getY())>0)) count++;
                else continue;
            }
            break;
        }
        case 2:
        {
            for(itr=points.begin();itr!=points.end();itr++)
            {
                if(((itr->getX())<0) && ((itr->getY())>0)) count++;
                else continue;
            }
            break;
        }
        case 3:
        {
            for(itr=points.begin();itr!=points.end();itr++)
            {
                if(((itr->getX())<0) && ((itr->getY())<0)) count++;
                else continue;
            }
            break;
        }
        case 4:
        {
            for(itr=points.begin();itr!=points.end();itr++)
            {
                if(((itr->getX())>0) && ((itr->getY())<0)) count++;
                else continue;
            }
            break;
        }
        default:
        {
            break;
        }
    }
    return count;
}
int collection::CountPointsOnCircleBoundary(int radius)
{
    int count=0;
    std::list<Points>::iterator itr;
    for(itr=points.begin();itr!=points.end();itr++)
    {
        if(((pow(itr->getX(),2))+(pow(itr->getY(),2)))==pow(radius,2)) count++;
        else continue;
    }
    return count;
}
std::list<Points> collection::FindPointsInQuadrant(int quadrant)
{
    std::list<Points> PointInQdrnt;
    std::list<Points>::iterator itr;
    switch (quadrant)
    {
        case 1:
        {
            for(itr=points.begin();itr!=points.end();itr++)
            {
                if(((itr->getX())>0) && ((itr->getY())>0)) PointInQdrnt.push_back(*itr);
                else continue;
            }
            break;
        }
        case 2:
        {
            for(itr=points.begin();itr!=points.end();itr++)
            {
                if(((itr->getX())<0) && ((itr->getY())>0)) PointInQdrnt.push_back(*itr);
                else continue;
            }
            break;
        }
        case 3:
        {
            for(itr=points.begin();itr!=points.end();itr++)
            {
                if(((itr->getX())<0) && ((itr->getY())<0)) PointInQdrnt.push_back(*itr);
                else continue;
            }
            break;
        }
        case 4:
        {
            for(itr=points.begin();itr!=points.end();itr++)
            {
                if(((itr->getX())>0) && ((itr->getY())<0)) PointInQdrnt.push_back(*itr);
                else continue;
            }
            break;
        }
        default:
        {
            break;
        }
    }
    return PointInQdrnt;
}
std::list<Points> collection::FindPointsOnCircleBoundary(int radius)
{
    std::list<Points> PointsOnCrcl;
    std::list<Points>::iterator itr;
    for(itr=points.begin();itr!=points.end();itr++)
    {
        if(((pow(itr->getX(),2))+(pow(itr->getY(),2)))==pow(radius,2)) PointsOnCrcl.push_back(*itr);
        else continue;
    }
    return PointsOnCrcl;
}
std::list<Points> collection::FindPointsInCircle(int radius)
{
    std::list<Points> PointsOnCrcl;
    std::list<Points>::iterator itr;
    for(itr=points.begin();itr!=points.end();itr++)
    {
        if(((pow(itr->getX(),2))+(pow(itr->getY(),2)))<pow(radius,2)) PointsOnCrcl.push_back(*itr);
        else continue;
    }
    return PointsOnCrcl;
}
int collection::CountPointsInCircle(int radius)
{
    int count=0;
    std::list<Points>::iterator itr;
    for(itr=points.begin();itr!=points.end();itr++)
    {
        if(((pow(itr->getX(),2))+(pow(itr->getY(),2)))<pow(radius,2)) count++;
        else continue;
    }
    return count;
}