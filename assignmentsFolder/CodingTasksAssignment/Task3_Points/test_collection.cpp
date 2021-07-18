#include "collection.h"
#include <gtest/gtest.h>

bool islisteq(std::list<Points>l1,std::list<Points>l2)
{
    std::list<Points>::iterator i1;
    std::list<Points>::iterator i2;
    if(l1.size()==l2.size())
    {
        i2=l2.begin();
        for(i1=l1.begin();i1!=l1.end();i1++)
        {
            if((i1->getX()==i2->getX())&&(i1->getY()==i2->getY())) i2++;
            else return false;
        }
        return true;

    }else return false;
}

TEST(collection,CountPointsInQuadrant)
{
    collection C1;
    Points p1(-1,-1); 
    C1.addPoint(1,1);
    C1.addPoint(3,7);
    C1.addPoint(8,7);
    C1.addPoint(1,-2);
    C1.addPoint(-1,6);
    C1.addPoint(p1);
    ASSERT_EQ(3,C1.CountPointsInQuadrant(1));
    ASSERT_EQ(1,C1.CountPointsInQuadrant(2));
    ASSERT_EQ(1,C1.CountPointsInQuadrant(3));
    ASSERT_EQ(1,C1.CountPointsInQuadrant(4));
}

TEST(collection,CountPointsOnCircleBoundary)
{
    collection C1; 
    C1.addPoint(0,2);
    C1.addPoint(2,0);
    C1.addPoint(0,-2);
    C1.addPoint(-2,0);

    ASSERT_EQ(4,C1.CountPointsOnCircleBoundary(2));
}

TEST(collection,CountPointsInCircle)
{
    collection C1; 
    C1.addPoint(0,2);
    C1.addPoint(2,0);
    C1.addPoint(0,-2);
    C1.addPoint(-2,0);

    ASSERT_EQ(4,C1.CountPointsInCircle(4));
}

TEST(collection, findpointsinquadrant)
{
    collection C1;
    Points p1(-1,-1); 
    C1.addPoint(1,1);
    C1.addPoint(3,7);
    C1.addPoint(8,7);
    C1.addPoint(1,-2);
    C1.addPoint(-1,6);
    C1.addPoint(p1);
    std::list<Points> q1={{1,1},{3,7},{8,7}};
    std::list<Points> q2={{-1,6}};
    std::list<Points> q3={{-1,-1}};
    std::list<Points> q4={{1,-2}};
    std::list<Points> qt1,qt2,qt3,qt4;
    qt1=C1.FindPointsInQuadrant(1);
    qt2=C1.FindPointsInQuadrant(2);
    qt3=C1.FindPointsInQuadrant(3);
    qt4=C1.FindPointsInQuadrant(4);

    ASSERT_EQ(true,islisteq(q1,qt1));
    ASSERT_EQ(true,islisteq(q2,qt2));
    ASSERT_EQ(true,islisteq(q3,qt3));
    ASSERT_EQ(true,islisteq(q4,qt4));
}

TEST(collection, findpointsoncircle)
{
    collection C1;
    C1.addPoint(0,2);
    C1.addPoint(2,0);
    C1.addPoint(0,-2);
    C1.addPoint(-2,0);
    C1.addPoint(-2,5);
    std::list<Points> q1={{0,2},{2,0},{0,-2},{-2,0}};
    std::list<Points> qt1;
    qt1=C1.FindPointsOnCircleBoundary(2);

    ASSERT_EQ(true,islisteq(q1,qt1));
}

TEST(collection, findpointsincircle)
{
    collection C1;
    C1.addPoint(0,2);
    C1.addPoint(2,0);
    C1.addPoint(0,-2);
    C1.addPoint(-2,0);
    C1.addPoint(-4,5);
    C1.addPoint(6,7);
    std::list<Points> q1={{0,2},{2,0},{0,-2},{-2,0}};
    std::list<Points> qt1;
    qt1=C1.FindPointsInCircle(4);
    C1.DisplayAll();
    ASSERT_EQ(true,islisteq(q1,qt1));
}

TEST(Points,verticalflip)
{
    Points p1(1,-1);
    Points p2;
    p2=p1.FindVerticleFlip();
    ASSERT_EQ(1,p2.getX());
    ASSERT_EQ(1,p2.getY());
}

TEST(Points,horizontalflip)
{
    Points p1(1,-1);
    Points p2;
    p2=p1.FindHorizontalFlip();
    ASSERT_EQ(-1,p2.getX());
    ASSERT_EQ(-1,p2.getY());
}

TEST(Points,distance)
{
    Points p1(2,0);
    Points p2;
    double distance;
    distance=p1.DistanceBtw2Points(p2);
    ASSERT_DOUBLE_EQ(2.0,distance);
}

TEST(Points,displacement)
{
    Points p1(2);
    Points p2;
    p2=p1.DisplacePoint(0,2);
    ASSERT_EQ(2,p2.getX());
    ASSERT_EQ(4,p2.getY());
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}