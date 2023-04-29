#ifndef PLATTIS_PLAYER_HH
#define PLATTIS_PLAYER_HH

#include "image.hh"

#include "box2d/box2d.h"

namespace plattis
{

class Player : public Image
{
public:
    /// Constructor.
    Player(SDL_Renderer* renderer);

};

}

#endif
