#include <iostream>
#include <unordered_map>

int main()
{
    /*Даны две строки, состоящие из строчных латинских букв. 
    Требуется определить, являются ли эти строки анаграммами, 
    т. е. отличаются ли они только порядком следования символов.*/

    bool answer = true;

    std::string input1, input2;
    std::cin >> input1 >> input2;

    if(input1.length() != input2.length())
    {
        std::cout << false;
        return 0;
    }
    else
    {
        std::unordered_map<char, int> dic;

        for(int i = 0; i < input1.length(); ++i)
        {
            auto it = dic.find(input1[i]);

            if(it == dic.end())
                dic.emplace(input1[i], 1);
            else
                ++it->second;
        }

        for(int i = 0; i < input2.length(); ++i)
        {
            auto it = dic.find(input2[i]);

            if(it == dic.end())
            {
                std::cout << false;
                return 0;
            }
            else
                --it->second;
            
            if(it->second == 0)
                dic.erase(it);
        }

        if(dic.size() != 0)
            std::cout << false;
        else
            std::cout << true;
    }
}