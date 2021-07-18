#include<iostream>
#include <vector>
#include<string>
#include <bits/stdc++.h>
#include<algorithm>
#include<map>
std::unordered_map<std::string,int> findWordLength(std::string sntnce)
{
    std::unordered_map<std::string,int> wmap;
    std::list<std::string> wordsList;
    std::istringstream ss(sntnce);
    std::string word;
    while (ss >> word) 
    {
        wordsList.push_back(word);
    }
    std::list<std::string>::iterator iter;
    for(iter=wordsList.begin();iter!=wordsList.end();iter++)
    {
        if(wmap[*iter]==0)
        {
            wmap[*iter]=iter->length();
        }
        else
        {
            wmap[*iter]*=2; 
        }
    }
    return wmap;
}
int main()
{
    std::string sntnce="Aman is a good boy and good student";
    std::unordered_map<std::string,int> wordMap=findWordLength(sntnce);
    std::map<std::string,int>::iterator itr;
    for (auto i : wordMap)
    {
        std::cout << i.first << "   " << i.second<< std::endl;
    }
    return 0;
}