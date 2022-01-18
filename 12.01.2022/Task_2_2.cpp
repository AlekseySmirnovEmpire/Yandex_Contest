#include <iostream>
#include <vector>

class Bottle {
private:
    std::vector<std::string> Levels;
    int CurrentLevel;
public:
    Bottle();

    void Fill(char symbol);
    void Draw();
};

Bottle::Bottle()
{
    size_t height, width = 0;
        std::cin >> height >> width;
        std::cin.ignore(1);
        Levels.resize(height);
        std::string level;
        for (int i = 0; i < height; ++i) 
        {
            std::getline(std::cin, level);
            Levels[i] = level;
        }
        CurrentLevel = height - 1;
}

void Bottle::Fill(char symbol)
{
    auto& level = Levels[--CurrentLevel];

        int start = level.find(' ');
        if (start == std::string::npos) 
            return;
        
        int finish = level.rfind(' ');
        for (int i = start; i <= finish; ++i)
            level[i] = symbol;
}

void Bottle::Draw()
{
    for (const auto& level : Levels)
        std::cout << level << std::endl;
}

class Cocktail {
private:
    std::string Name;
    int LayersCount;
    char Symbol;
public:
    Cocktail();

    void Fill(Bottle& cup);
};

Cocktail::Cocktail()
{
    std::cin >> Name;
        std::cin >> LayersCount;
        std::cin >> Symbol;
}

void Cocktail::Fill(Bottle& cup)
{
    for (int i = 0; i < LayersCount; ++i)
        cup.Fill(Symbol);
}

int main() 
{
    Bottle cup;

    int count;
    std::cin >> count;
    
    
    for (int i = 0; i < count; ++i) 
    {
        Cocktail* ingredient = new Cocktail;

        ingredient->Fill(cup);

        delete ingredient;
        ingredient = nullptr;
    }

    cup.Draw();
    return 0;
}