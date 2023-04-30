#ifndef PLATTIS_IMAGE_HH
#define PLATTIS_IMAGE_HH

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>

namespace plattis
{

class Image
{
public:
    /// Constructor.
    Image(SDL_Renderer* renderer, const std::string& filename, float x, float y);

    /// Destructor.
    ~Image();

    /// Draw the image.
    void draw(SDL_Renderer* renderer) const;

    /// Change the image size.
    void setScale(float scale);

    virtual float getX() { return m_x; }
    virtual float getY() { return m_y; }

protected:
    float m_x;
    float m_y;

    int m_width;
    int m_height;
    float m_scale = 1.f;

private:
    SDL_Texture* m_texture;
};

}

#endif
