#include<iostream>
class Currency
{
private:
    int m_paise;
    int m_rupees;
public:
    explicit Currency():m_paise(0),m_rupees(0){}
    explicit Currency(int paise,int rupees):m_paise(paise),m_rupees(rupees){}
    Currency operator=(int totalPaise)
    {
        this->m_paise=totalPaise%100;
        this->m_rupees=totalPaise/100;
        return(*this);
    }
    void Display()
    {
        std::cout<<m_paise<<" "<<m_rupees<<std::endl;
    }
    operator int()
    {
        return ((m_rupees*100)+m_paise);
    }
    ~Currency(){};
};
int main()
{
    Currency amount;
    int totpais=150;
    amount=totpais;
    amount.Display();
    int testPaise=amount;
    std::cout<<testPaise<<std::endl;

    return 0;
}