#include "image.hh"
#include "player.hh"

namespace plattis
{

Image::Image(SDL_Renderer* renderer, const std::string& filename, float x, float y) : m_x(x), m_y(y)
{
    SDL_Surface* surface = IMG_Load(filename.c_str());

    // Handle error with loading image.
    if (!surface)
    {
        return;
    }

    // Create texture from the surface
    m_texture = SDL_CreateTextureFromSurface(renderer, surface);

    // Handle texture creation error.
    if (!m_texture)
    {
        SDL_FreeSurface(surface);
        return;
    }

    // Store the width and height of the image.
    m_width = surface->w;
    m_height = surface->h;

    // Free the surface, since it's not needed anymore.
    SDL_FreeSurface(surface);
}

Image::~Image()
{
    if (m_texture)
    {
        SDL_DestroyTexture(m_texture);
    }
}

void Image::draw(SDL_Renderer* renderer) const
{
    if (m_texture)
    {
        // Create an SDL_Rect to specify the destination rectangle for the image.
        SDL_Rect destRect
        {
            static_cast<int>(m_x),
            static_cast<int>(m_y), 
            static_cast<int>(static_cast<float>(m_width) * m_scale),
            static_cast<int>(static_cast<float>(m_height) * m_scale)
        };

        SDL_RenderCopy(renderer, m_texture, nullptr, &destRect);
    }
}

void Image::setScale(float scale) { m_scale = scale; }

}
