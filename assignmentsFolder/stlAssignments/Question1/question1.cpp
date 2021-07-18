#include<iostream>
#include <vector>
#include<algorithm>
#define SizeOfArray 10
/**
 * @brief Finding sum with out using algorithm
 * 
 * @param array 
 * @param targetValue 
 * @return std::pair<int,int> 
 */
/*
std::pair<int,int> isEqual(std::vector<int> array,int targetValue)
{
    
    
    for(int i=0;i<=SizeOfArray;i++)
    {
        for ( int j=i+1;j<=SizeOfArray ; ++j ) 
        {
            //std::cout<<*iter<<std::endl;
            if((array[i])+array[j]==targetValue)
            {
                //std::cout<<array[i]<<" "<<i<<" "<<j<<std::endl;
                return std::make_pair(i,j);
            }
        }
    }
    return std::make_pair(-1,-1);
}
*/
std::pair<int,int> isEqual(std::vector<int> array,int targetValue)
{
    
    
    for(int i=0;i<=SizeOfArray;i++)
    {
        for ( int j=i+1;j<=SizeOfArray ; ++j ) 
        {
            //std::cout<<*iter<<std::endl;
            if((array[i])+array[j]==targetValue)
            {
                //std::cout<<array[i]<<" "<<i<<" "<<j<<std::endl;
                return std::make_pair(i,j);
            }
        }
    }
    return std::make_pair(-1,-1);
}
int main()
{
    std::vector<int> array;
    int targetValue=12;
    for(int i=1;i<=SizeOfArray;i++)
    {
        array.push_back(i);
    }
    std::pair<int,int> pairOfElem=isEqual(array,targetValue);
    std::cout<<pairOfElem.first<<" "<<pairOfElem.second<<std::endl;
    //std::cout<<array[pairOfElem.first]<<" "<<array[pairOfElem.second]<<std::endl;   
    return 0;
}