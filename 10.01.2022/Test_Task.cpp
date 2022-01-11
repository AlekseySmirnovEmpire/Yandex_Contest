#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    /*Даны две строки строчных латинских символов: строка J и строка S. 
    Символы, входящие в строку J, — «драгоценности», входящие в строку S — «камни». 
    Нужно определить, какое количество символов из S одновременно являются 
    «драгоценностями». Проще говоря, нужно проверить, какое количество символов 
    из S входит в J.*/

    std::string first;
    std::string second;

    std::cin >> first >> second;

    int answer = 0;

    for(int i = 0; i < second.length(); ++i)
    {
        if(first.find(second[i]) != std::string::npos)
            ++answer;
    }

    std::cout << answer;
}