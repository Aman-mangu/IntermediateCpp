
#include<iostream>
#include<iterator>
#include <fstream>
#include <sstream>
#include<string>
int main(){
    std::ifstream inFile("textFile.txt");
    int words=0;
    int lines =0;
    int characters=0;

    if(inFile.is_open())
    {
        std::string line;
       
        while( std::getline(inFile,line) )
        {
            std::stringstream str;
            str<<line;
            
            std::istream_iterator<std::string> ss(str);
            words+=std::distance(ss, {});
            lines++;
            characters+= line.length();
            
        }
        

    }

    std::cout<< "Words : "<<words<<std::endl;
    std::cout<< "Lines : "<<lines<<std::endl;
    std::cout<< "Characters : "<<characters<<std::endl;

}