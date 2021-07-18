
#include<iostream>
#include<vector>
bool isdigit(char ch){
    int test = ch-'0';
    if(test>=0&&test<=9)return true;
    else return false;
}
int main(){
    std::string expression = "235*+";
    std::vector<int> tokens;
    for(auto i:expression)
    {
        if(isdigit(i))
        {
            int digit = i-'0';
            tokens.push_back(digit);
        }
        else
        {
            int a = tokens.back();
            tokens.pop_back();
            int b = tokens.back();
            tokens.pop_back();

            switch(i)
            {
            case '+':
            {
                tokens.push_back(a+b);
                break;
            }
            case '-':
            {
                tokens.push_back(a-b);
                break;
            }
            case '*':
            {
                tokens.push_back(a*b);
                break;
            }
            case '/':
            {
                tokens.push_back(a/b);
                break;
            }
            }
        }
    }
    int result=tokens.back();
    std::cout<<"answer = "<< result << std::endl;

}