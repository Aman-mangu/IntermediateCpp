
#include<iostream>
#include<list>
#include <sstream>
std::list<int> getlist(std::string MACaddr)
{
    std::stringstream ss(MACaddr);
    
    std::string array[6];
    std::list<int> maclist;
    int value;
    for(int i=0;i<6;i++)
    {
        std::getline(ss,array[i],':');
        std::stringstream str;
        str<<array[i];
        str >> std::hex >> value;
        maclist.push_back(value);
    }
    return maclist;

}
int main(){
    std::string MACaddr="A1:23:9B:F8:1D:5C";
    std::list<int> answerlist = getlist(MACaddr);
    for(auto i:answerlist)
    {
        std::cout<<i<<std::endl;
    }

}
