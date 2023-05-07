#ifndef PLATTIS_MAP_HH
#define PLATTIS_MAP_HH

#include "player.hh"
#include "platform.hh"
#include "rectangle.hh"
#include "renderer.hh"

#include <box2d/box2d.h>

#include <vector>
#include <memory>

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

    /// Create a new tile.
    /// \param xIndex X position of the tile as tenth of the screen size (numbers 0-9).
    /// \param yIndex Y position of the tile.
    /// \param world The b2World.
    void setTile(int xIndex, float yIndex, b2World* world);

    /// Set a simple starting map since we update tiles so up that 
    /// it cannot be seen
    /// \param world The b2World.
    void startingMap(b2World* world);

private:

    int m_screenWidth, m_screenHeight;
    Player* m_player;

    // Current tiles existing in the game.
    // Note that smart pointers in this context are totally unnecessary as this could/should be initialized as:
    // std::vector<Platform> m_tiles;
    // However this initialization requires use of both smart pointers and move semantics.
    std::vector<std::unique_ptr<Rectangle>> m_tiles;

    // Where to create tile from player's y position.
    float updateStep = -(static_cast<float>(m_screenHeight) / 2);

    // Keep track of the y position where new tiles are added.
    float yUpdateIndex;

    bool usedStartingMap = false;
};

}

#endif
