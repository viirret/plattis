#ifndef PLATTIS_RECTANGLE_HH
#define PLATTIS_RECTANGLE_HH

#include "renderer.hh"

#include <SDL2/SDL.h>

namespace plattis
{

class Rectangle
{
public:
    /// Constructor.
    Rectangle(int x, int y, int w, int h) : m_rect({x, y, w, h}) {}

    /// Draw outline of the rectangle.
    void draw(Renderer& renderer, const Color& color) { renderer.drawRect(m_rect, color); }

    // Fill the rendering area with color.
    void fill(Renderer& renderer, const Color& color) const { renderer.fillRect(m_rect, color); }

private:
    SDL_Rect m_rect;
};

}

#endif
