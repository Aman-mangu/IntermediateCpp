#include<iostream>
#include <vector>
#include<string>
#include <bits/stdc++.h>
#include<algorithm>
#include<map>
void numOfOccurences(std::string stringArray)
{
   std::unordered_map<char,int> chmap;
   for(char i : stringArray)
   {
       chmap[i]++;
   }
   for(char i : stringArray)
  {
    if(chmap[i] != 0)
    {
      std::cout << i << chmap[i] <<std::endl;
      chmap[i] = 0;
    }
  }
}



int main()
{
    std::string stringArray="Aman is a good Boy!";
    numOfOccurences(stringArray);
    return 0;
}