#include "rectangle.hh"

namespace plattis
{

SDL_Rect Rectangle::getDestRect(Camera* camera) const
{
    return
    {
        static_cast<int>(m_rect.x - camera->getX()),
        static_cast<int>(m_rect.y - camera->getY()),
        m_rect.w,
        m_rect.h
    };
}

}
