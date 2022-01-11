#include <iostream>
#include <vector>

int main()
{
    /*Требуется найти в бинарном векторе самую длинную последовательность 
    единиц и вывести её длину.
    Желательно получить решение, работающее за линейное время и при этом 
    проходящее по входному массиву только один раз.*/

    int amount;

    std::cin >> amount;

    std::vector<bool> vec(amount);

    int max = 0;
    int tempMax = 0;

    for(int i = 0; i < vec.size(); ++i)
    {
        int temp;

        std::cin >> temp;

        vec[i] = temp;

        if(temp)
            ++tempMax;
        else 
        {
            if(max < tempMax)
                max = tempMax;

            tempMax = 0;
        }
    }

    if(max < tempMax)
        max = tempMax;

    std::cout << max;
}