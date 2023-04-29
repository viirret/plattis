#include "window.hh"
#include "vector2.hh"

namespace plattis
{

Window::Window(const std::string& title)
{
    // Don't try to initialize SDL2 if it's already initialized
    if (!(SDL_WasInit(SDL_INIT_VIDEO) & SDL_INIT_VIDEO))
    {
        SDL_Log("Trying to initialize SDL2");

        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL2: %s\n",
                         SDL_GetError());
            return;
        }
        SDL_Log("SDL2 initialized");
    }

    // get monitor size
    SDL_DisplayMode display;
    if (SDL_GetCurrentDisplayMode(0, &display))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't get display info: %s\n",
                     SDL_GetError());
        return;
    }

    SDL_Log("Display size w: %d h: %d", display.w, display.h);

    // create window
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              display.w, display.h, SDL_WINDOW_FULLSCREEN);

    if (!m_window)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s\n", SDL_GetError());
        return;
    }

    // update window size
    SDL_GetWindowSize(m_window, &m_size.x, &m_size.y);

    SDL_Log("Window created");
}

Window::~Window()
{
    if (m_window)
    {
        SDL_DestroyWindow(m_window);
    }

    SDL_Quit();
}

Vec2i Window::swapSize(Vec2i newSize)
{
    Vec2i oldSize = m_size;
    m_size = newSize;
    return oldSize;
}

}
