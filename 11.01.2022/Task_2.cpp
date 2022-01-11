#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    /*Даны два числа A и B. Вам нужно вычислить их сумму A+B. 
    В этой задаче вам нужно читать из файла и выводить ответ в файл*/

    int a, b;

    std::ifstream file1("input.txt");

    file1 >> a >> b;

    file1.close();

    std::ofstream file2("output.txt");

    file2 << a + b;

    file2.close();
}