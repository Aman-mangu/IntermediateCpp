
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
int main(){
    std::vector<double> Tdistance={1,2,3,4,5,6,7,8,1};
    double interval = 1.0;
   //double distance =std::accumulate(Tdistance.begin(),Tdistance.end(),0.0);
   double distance = Tdistance.back();
    double time =Tdistance.size()*interval;
    double average_speed = (distance)/(time);
    std::cout<<"average speed = "<< average_speed<<std::endl;
    return 0;
}