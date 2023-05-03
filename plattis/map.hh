#ifndef PLATTIS_MAP_HH
#define PLATTIS_MAP_HH

#include "player.hh"
#include "platform.hh"
#include "renderer.hh"

#include <box2d/box2d.h>

#include <vector>
#include <utility>

namespace plattis
{

class Map
{
public:

    /// Constructor.
    /// \param screenWidth The width of the screen.
    /// \param screenHeight The height of the screen.
    /// \param player Pointer to the player.
    Map(int screenWidth, int screenHeight, Player* player);

    /// Update the map.
    /// \param world b2World pointer.
    void update(b2World* world);

    /// Render the map.
    /// \param renderer The main renderer.
    /// \param camera The main camera.
    void render(Renderer& renderer, Camera* camera);

private:

    void setTile(float xIndex, float yIndex, b2World* world);

    bool flag = true;

private:

    int m_screenWidth, m_screenHeight;
    Player* m_player;

    // current tiles
    std::vector<Platform> m_tiles;

    // tile positions
    std::vector<std::pair<int, int>> m_positions;

    // When to create new tile
    float updateStep = -(static_cast<float>(m_screenHeight) / 2);
};

}

#endif
