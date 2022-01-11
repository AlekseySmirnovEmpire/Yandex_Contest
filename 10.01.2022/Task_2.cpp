#include <iostream>
#include <set>

int main()
{
    /*Дан упорядоченный по неубыванию массив целых 32-разрядных чисел. 
    Требуется удалить из него все повторения. Желательно получить решение, 
    которое не считывает входной файл целиком в память, т.е., использует 
    лишь константный объем памяти в процессе работы.*/

    int size;
    std::cin >> size;

    std::set<int> dic;

    while(size > 0)
    {
        --size;

        int temp;
        std::cin >> temp;

        if(dic.find(temp) == dic.end())
            dic.insert(temp);
    }

    for(const auto& el : dic)
        std::cout << el << std::endl;
}