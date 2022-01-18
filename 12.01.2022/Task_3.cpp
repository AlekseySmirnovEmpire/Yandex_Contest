#include <iostream>
#include <vector>
#include <unordered_set>

int main(int argc, char** argv)
{
    int plateAmount, manCount;
    std::cin >> plateAmount >> manCount;

    std::vector<int> input(plateAmount);

    for(auto& el : input)
        std::cin >> el;

    std::unordered_multiset<int> place;
    int temp = std::move(input[plateAmount - 1]);
    place.insert(temp);

    for(size_t i = input.size() - 1; i > 0; --i)
    {

        if(temp < input[i - 1] && place.find(temp) != place.end())
        {
            place.insert(input[i - 1] - temp);
            temp = std::move(input[i - 1]);
        }
    }

    if(input[0] > temp)
        place.insert(input[0] - temp);

    int answer = 0;

    std::vector<int> guards(manCount);

    for(auto& el : guards)
        std::cin >> el;

    for(size_t i = 0; i < guards.size(); ++i)
    {
        auto it = place.begin();

        if(it == place.end())
            break;

        while(it != place.end())
        {
            if(guards[i] <= *it)
            {
                ++answer;
                place.erase(it);
            }
            ++it;
        }
    }

    std::cout << answer << std::endl;
}