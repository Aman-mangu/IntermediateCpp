#include<iostream>
#include<string>
#include<cstring>
class MyString
{
private:
    char* m_str;
    size_t m_len;
public:
    MyString():m_str(NULL),m_len(0){}
    MyString(const char* p1)
    {
        if (p1==NULL)
        {
            m_str=NULL;
            m_len=0;
        }
        else
        {
            m_str = new char[strlen(p1)+1];
            int i=0;
            while(*(p1+i)!='\0')
            {
                *(m_str+i)=*(p1+i);
                i++;
            }
            m_len=strlen(m_str);
        }
    }
    char* get_str()
    {
        return m_str;
    }
    size_t get_len() 
    {
        return m_len;
    }
    MyString operator+(const MyString& ref)
    {
        MyString temp;
        if(ref.m_str==NULL)
        {
            temp.m_str=this->m_str;
            temp.m_len=strlen(temp.m_str); 
        }
        else
        {
            temp.m_str=strcat(this->m_str,ref.m_str);
            temp.m_len=this->m_len+ref.m_len;
        }
        return temp;
    }
    MyString& operator*=(const int val)
    {
        int l = this->m_len;
        char *temp = new char[l*val + 1];
        for(int i=0;i<val;i++)
        {
            for(int k=0;k<l;k++)
            {
                temp[k+(l*i)] = m_str[k];
            }
        }
        delete[] m_str;
        m_str = new char[l*val+1];
        for (int i = 0; i < l*val; i++)
            m_str[i] = temp[i];
        m_len = l*val;
        delete[] temp;
        return (*this);
    }
     MyString operator*(const int val)
    {
        int l = this->m_len;
        char *temp = new char[l*val + 1];
        for(int i=0;i<val;i++)
        {
            for(int k=0;k<l;k++)
            {
                temp[k+(l*i)] = m_str[k];
            }
        }
        delete[] m_str;
        m_str = new char[l*val+1];
        for (int i = 0; i < l*val; i++)
            m_str[i] = temp[i];
        m_len = l*val;
        delete[] temp;
        MyString s;
        s=*this;
        return s;
    }
    MyString& operator=(const MyString& ref)
    {
        this->m_str=ref.m_str;
        this->m_len=ref.m_len;
        return(*this);
    }
    MyString& operator+=(const MyString &ref)
    {
        int l = m_len + ref.m_len;
        char *temp = new char[l + 1];
        for (int i = 0; i < m_len; i++)
            temp[i] = m_str[i];
        for (int i = 0; i < ref.m_len; i++)
            temp[m_len + i] = ref.m_str[i];
        delete[] m_str;
        m_str = new char[l];
        for (int i = 0; i < l; i++)
            m_str[i] = temp[i];
        m_len = l;
        delete[] temp;
        return (*this);
    }
    MyString& operator+=(const char *p1)
    {
        if(p1==NULL)
        {
            return (*this);
        }
        else
        {
            int len = strlen(p1), old = m_len;
            char *temp = new char[old + 1];
            for (int i = 0; i < old; i++)
                temp[i] = m_str[i];
            m_len += len;
            delete[] m_str;
            m_str = new char[m_len + 1];
            for (int i = 0; i < old; i++)
                m_str[i] = temp[i];
            for (int i = old; i < m_len; i++)
                m_str[i] = p1[i - old];
            delete[] temp;
            return (*this);
        }
    }
    void Display()
    {
        std::cout<<this->m_str<<std::endl;
    }
    ~MyString(){}
};
int main()
{
    MyString s1("abcd");
    MyString s2("xyz");
    MyString s3,s4,s5;
    s3 = s1 + s2;  // 
    s3.Display();
    s3 += "hello";
    s3.Display(); // s3 should be "abcdxyzhello"
    s4 = s1 * 3;   // s4 will be "abcdabcdabcd", like in python
    s4.Display();
    s2 *= 5;       // s2 should be "xyzxyzxyzxyzxyz"
    s5 = s1 * 2 + "hello"; // s5 should be "abcdabcdhello"
    s2.Display();
    s5.Display();
    return 0;
}