#include "map.hh"
#include "enemy.hh"
#include "platform.hh"
#include "rectangle.hh"
#include "util.hh"

namespace plattis
{

Map::Map(int screenWidth, int screenHeight, Player* player)
    :   m_screenWidth(screenWidth), 
        m_screenHeight(screenHeight),
        m_player(player)
{
}

void Map::startingMap(b2World* world)
{
    for(int i = -500; i < 500; i += 100)
    {
        setTile(randomValue(0, 9), static_cast<float>(i), world);
    }
}

void Map::update(b2World* world)
{
    float playerY = m_player->getY();

    // Generate little map in the beginning
    if (!usedStartingMap) 
    {
        startingMap(world);
        yUpdateIndex = playerY;
        usedStartingMap = true;
    }

    // Generate more tiles once player has passed certain line
    if (-playerY > yUpdateIndex)
    {
        yUpdateIndex += 50;
        setTile(randomValue(0, 9), playerY + updateStep, world);
    }
}

void Map::setTile(int xIndex, float yIndex, b2World* world)
{
    m_tiles.emplace_back(std::make_unique<Platform>(std::move(static_cast<float>(m_screenWidth) / 10 * static_cast<float>(xIndex)), yIndex, 100, 50, world));
}

void Map::render(Renderer& renderer, Camera* camera)
{
    for (auto& tile : m_tiles)
    {
        tile->fill(renderer, Color(100, 100, 100, 255), camera);
    }
}


}
