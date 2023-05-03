#include "map.hh"

namespace plattis
{

Map::Map(int screenWidth, int screenHeight, Player* player)
    :   m_screenWidth(screenWidth), 
        m_screenHeight(screenHeight),
        m_player(player)
{
}

void Map::update(b2World* world)
{
    float playerY = m_player->getY();
    
    if(flag) 
    {
        setTile(0, playerY, world);
        flag = false;
    }
}

void Map::setTile(float xIndex, float yIndex, b2World* world)
{
    m_tiles.emplace_back(Platform((static_cast<float>(m_screenWidth) / 10 * xIndex), yIndex + updateStep, 100, 50, world));

    m_positions.emplace_back(xIndex, yIndex);
}

void Map::render(Renderer& renderer, Camera* camera)
{
    for(auto& tile : m_tiles)
    {
        tile.fill(renderer, Color(100, 100, 100, 255), camera);
    }
}



}
