#include "player.hh"

namespace plattis
{
    
Player::Player(SDL_Renderer* renderer)
    : Image(renderer, "../assets/doodle.png", 200, 200)
{
    // Scale image to correct size.
    setScale(0.1f);

    setSpeed(40);
}

}
