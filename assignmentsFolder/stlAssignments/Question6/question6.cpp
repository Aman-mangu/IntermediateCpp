#include<iostream>
#include <vector>
#include<string>
#include <bits/stdc++.h>
#include<algorithm>
double mean;
bool isLessThan(double val)
{
    if(val<mean) return true;
    else return false;
}
int countElemSmallMean(std::vector<double> vec)
{
    int count=0;
    mean=accumulate(vec.begin(), vec.end(), 0.0)/vec.size();
    std::vector<double>::iterator iter;
    return std::count_if(vec.begin(),vec.end(),isLessThan);
}
int main()
{
    std::vector<double> vec={1,2,3,4,5,6,7,8,9,10};
    int numOfElem=countElemSmallMean(vec);
    std::cout<<numOfElem<<std::endl;
    return 0;
}