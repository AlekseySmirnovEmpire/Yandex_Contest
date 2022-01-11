#include <iostream>
#include <string>

void print(const int& count, std::string input = "", int leftSide = 0, int rightSide = 0)
{
    if(leftSide == count && rightSide == count)
        std::cout << input << std::endl;
    else
    {
        if(leftSide < count)
            print(count, input + "(", ++leftSide, rightSide);
        
        if(rightSide < count)
            print(count, input + ")", leftSide, ++rightSide);
    }
}

int main()
{
    /*Дано целое число n. Требуется вывести все правильные скобочные 
    последовательности длины 2 ⋅ n, упорядоченные лексикографически.
    В задаче используются только круглые скобки. Желательно получить 
    решение, которое работает за время, пропорциональное общему 
    количеству правильных скобочных последовательностей в ответе, 
    и при этом использует объём памяти, пропорциональный n.*/

    int n;
    std::cin >> n;

    print(n);
}