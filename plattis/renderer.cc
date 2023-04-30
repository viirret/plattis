#include "renderer.hh"
#include <SDL2/SDL_render.h>

namespace plattis
{

Renderer::Renderer(SDL_Window* window)
{
    m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!m_renderer)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
        return;
    }
}

Renderer::~Renderer() { SDL_DestroyRenderer(m_renderer); }

void Renderer::clear() { SDL_RenderClear(m_renderer); }

void Renderer::render() { SDL_RenderPresent(m_renderer); }

void Renderer::drawRect(SDL_Rect rect, const Color& color)
{
    setDrawColor(color);
    SDL_RenderDrawRect(m_renderer, &rect);
}

void Renderer::fillRect(SDL_Rect rect, const Color& color)
{
    setDrawColor(color);
    SDL_RenderFillRect(m_renderer, &rect);
}

void Renderer::setDrawColor(const Color& color)
{
    SDL_SetRenderDrawColor(m_renderer, color.getR(), color.getG(), color.getB(), color.getA());
}

}
