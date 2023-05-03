#include "rectangle.hh"

namespace plattis
{

SDL_Rect Rectangle::getDestRect(Camera* camera) const
{
    return
    {
        static_cast<int>(static_cast<float>(m_rect.x) - camera->getX()),
        static_cast<int>(static_cast<float>(m_rect.y) - camera->getY()),
        m_rect.w,
        m_rect.h
    };
}

}
