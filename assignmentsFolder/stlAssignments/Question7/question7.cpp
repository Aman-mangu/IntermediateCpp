#include<iostream>
#include <vector>
#include<list>
#include<string>
#include <bits/stdc++.h>
#include<algorithm>
double mean;
bool isLessThan(double val)
{
    if(val<mean) return true;
    else return false;
}
bool isGreaterThan(double val)
{
    if(val<mean) return true;
    else return false;
}
int findCountsDiff(std::list<double>lst)
{
    mean=accumulate(lst.begin(), lst.end(), 0.0)/lst.size();
    std::vector<double>::iterator iter;
    int countLess=std::count_if(lst.begin(),lst.end(),isLessThan);
    int countMore=std::count_if(lst.begin(),lst.end(),isGreaterThan);
    return abs(countLess-countMore);
}
int main()
{
    std::list<double> lst={1.5,2,3.7,4.8,5.1,6.4,7.8,8.9,9.1,10.5,11.8,12.6};
    int diffOfCounts=findCountsDiff(lst);
    std::cout<<diffOfCounts<<std::endl;
    return 0;
}