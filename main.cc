#include "plattis/core.hh"

using namespace plattis;

class Game : public Core
{
public:
    Game(const std::string& title)
        : Core(title)
    {
        setBackgroundColor(Color(120, 120, 44, 255));
    }
};

int main()
{
    Game game("title");
    game.start();

    return 0;
}

