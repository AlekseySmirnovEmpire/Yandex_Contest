#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Arr
{
private:
    std::vector<int> vec;
    std::vector<bool> output;
public:
    Arr();
    Arr(std::vector<int>& input) : vec(input) {}

    void print();
    void doSomeMagic();
    int findIndexMid(std::vector<int>& input);
};

Arr::Arr()
{
    do
    {
        int temp;
        std::cin >> temp;
        vec.push_back(temp);
        output.push_back(false);

    } while(vec.size() < 3);
}


int Arr::findIndexMid(std::vector<int>& input)
{
    Arr* temp = new Arr(input);

    int backUp = input[2];
    int frontUp = input[0];

    std::sort(temp->vec.begin(), temp->vec.end());

    int answer = temp->vec[1] == backUp ? 2 : (temp->vec[1] == frontUp ? 0 : 1);

    delete temp;
    temp = nullptr;

    return answer;
}

void Arr::print()
{
    for(const auto& el : output)
        std::cout << (el ? "YES" : "NO") << std::endl;
}

void Arr::doSomeMagic()
{
    for(size_t i = 0; i < vec.size(); ++i)
    {
        Arr* temp = new Arr(vec);

        for(size_t j = 0; j < vec.size(); ++j)
        {
            if(i != j)
            {
                temp->vec[i] -= temp->vec[j];

                this->output[findIndexMid(temp->vec)] = true;
            }
        }

        delete temp;
        temp = nullptr;   
    }    
}

int main(int argc, char* argv[])
{
    Arr numbers;

    numbers.doSomeMagic();

    numbers.print();
}