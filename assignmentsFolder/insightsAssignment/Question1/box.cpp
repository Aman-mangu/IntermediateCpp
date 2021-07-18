#include<iostream>
const int N=5;
const int N1=5;
class Box
{
private:    
    int m_length;
    int m_breadth;
    int m_height;
public:
    Box():m_length(0),m_breadth(0),m_height(0){}
    Box(int l,int b, int h):m_length(l),m_breadth(b),m_height(h){}
    Box(int array[3]):m_length(array[0]),m_breadth(array[1]),m_height(array[2]){}
    void setDim(int arr[3])
    {
        m_length=arr[0];
        m_breadth=arr[1];
        m_height=arr[2];
    }

void Display()
    {
        std::cout<<m_length<<" "<<m_breadth<<" "<<m_height<<std::endl;
    }
~Box(){};
};
Box array[N];
Box* construct(int index)
{
    
    Box* temp= new (array+index) Box;
    return temp;
}
Box* initialiseBoxArray(int arr[N1][3])
{
    Box* arry = new (arr) Box[N1];
    return(arry);

}
int main()
{
    int arr[3]={10,12,5};
    Box *ptr = new (arr) Box;
    ptr->Display();
    int arr2d[N1][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
    Box* boxinit=initialiseBoxArray(arr2d);
    Box* instance=construct(2);
    instance->setDim(arr);
    instance->Display();
    Box b1;
    b1.Display();
    Box b2(arr[0],arr[1],arr[2]);
    b2.Display();
    Box b3(2,2,2);
    b3.Display();
    for(int i=0;i<N1;i++)
    {
        (boxinit+i)->Display();
    }
    return 0;
}