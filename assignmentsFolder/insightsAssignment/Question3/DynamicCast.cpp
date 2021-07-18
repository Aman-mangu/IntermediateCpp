#include<iostream>
#include<cmath>

enum Type{equilateral=0,isosceles=1,scalene=2,rightangled=3};

class Shape { 
public: 
virtual double area(){}
virtual double circumference(){}
~Shape(){}
};

class Triangle : public Shape { 
int m_side1;
int m_side2;
int m_side3;
public:
Triangle():m_side1(0),m_side2(0),m_side3(0)
{}
Triangle(int s1, int s2, int s3):m_side1(s1),m_side2(s2),m_side3(s3)
{}
double area(){
    double s = ((m_side1 + m_side2 + m_side3)/2.0);
    return(sqrt(s*(s-m_side1)*(s-m_side2)*(s-m_side3)));
}
double circumference(){
    return(m_side1 + m_side2 + m_side3);
}
bool isRightAngled(){
    if((pow(m_side1,2)==pow(m_side2,2)+pow(m_side3,2))||(pow(m_side2,2)==pow(m_side1,2)+pow(m_side3,2))||(pow(m_side3,2)==pow(m_side2,2)+pow(m_side1,2))) return true;
    else return false;
}

Type TypeofTriangle(){
    if(m_side1==m_side2==m_side3) return equilateral;
    else if(m_side1==m_side2||m_side1==m_side3||m_side2==m_side3) return isosceles;
    else if(isRightAngled()) return rightangled;
    else return scalene;

}

~Triangle(){}

};

void tcompute(Shape* sp1){
    Triangle* tp2;
    Shape* sp2;
    tp2 = dynamic_cast<Triangle*>(sp1);
    if(tp2->isRightAngled())
    {
        std::cout<< "right angled" << std::endl;
    }
    else {
        std::cout<< "not right angled" << std::endl;
    }

    Type tr1 = tp2->TypeofTriangle();
    if(tr1==equilateral) std::cout<< "equilateral" << std::endl;
    else if(tr1==isosceles) std::cout<< "isosceles" << std::endl;
    else if(tr1==rightangled) std::cout<< "rightangled" << std::endl;
    else if(tr1==scalene) std::cout<< "scalene" << std::endl;
    else std::cout<< "type not defined" << std::endl;

    std::cout<< "area = " << tp2->area() << std::endl;
    std::cout<< "perimeter = " << tp2->circumference() << std::endl;

    sp2 = dynamic_cast<Shape*>(tp2);
    std::cout<< "area = " << sp2->area() << std::endl;
    std::cout<< "circumference = " << sp2->circumference() << std::endl;

}

int main(){
    Triangle t1(3,4,5);
    Triangle* tp = &t1;
    Shape* sp;
    sp = dynamic_cast<Shape*>(tp);
    tcompute(sp);
    return 0;
}