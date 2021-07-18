#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<cctype>
class Customer
{
private:
int m_id;
std::string m_name;
std::string m_phoneNo;
double m_amount;
public:
Customer():m_id(0),m_name(""),m_phoneNo(""),m_amount(0){}
Customer(int id,std::string name,std::string mobNo,double amount):m_id(id),m_name(name),m_phoneNo(mobNo),m_amount(amount){}
void Display()
{
    std::cout<<m_id<<std::endl;
    std::cout<<m_name<<std::endl;
    std::cout<<m_phoneNo<<std::endl;
    std::cout<<m_amount<<std::endl;
}
~Customer(){};
};

int main()
{
//---------------------------------------------------------------------
std::ifstream inFile("customer.csv");

if (inFile.is_open())
    {
        std::string line;
        while( std::getline(inFile,line) )
        {
            std::stringstream ss(line);
            std::string v1,v2,v3,v4;

            std::getline(ss,v1,',');   // std::cout<<"\""<<ID<<"\"";
            std::getline(ss,v2,','); //std::cout<<", \""<<fname<<"\"";
            std::getline(ss,v3,','); //std::cout<<", \""<<lname<<"\"";
            std::getline(ss,v4,','); //std::cout<<", \""<<fname<<"\";
            int ID;
            double amt;
            ID=stoi(v1);
            amt=stod(v4);
            Customer c1(ID,v2,v3,amt);
            c1.Display();
            
        }
    
    
    }



//----------------------------------------------------------------------
    return 0;
}