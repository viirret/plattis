#include "core.hh"
#include "rectangle.hh"

namespace plattis
{

Core::Core(const std::string& title)
    :   m_window(title),
        m_renderer(m_window.getWindow()),
        rectangle(50, 50, 50, 50),
        m_player(m_renderer.getRenderer()),
        m_windowSize({ 0, 0, m_window.getSizeX(), m_window.getSizeY() }),
        m_running(true)
{
}

void Core::start()
{
    while(m_running)
    {
        update();
    }
}

void Core::update()
{
    m_renderer.clear();
    
    // Update background color.
    m_renderer.fillRect(m_windowSize, m_backgroundColor);

    updateTime();
    trackEvents();

    rectangle.draw(m_renderer, Color(10, 10, 10, 255));
    rectangle.fill(m_renderer, Color(200, 200, 200, 255));

    m_player.draw(m_renderer.getRenderer());

    m_renderer.render();
}

void Core::setBackgroundColor(const Color& color)
{
    m_backgroundColor = color;
}

void Core::updateTime()
{
    m_currentTime = SDL_GetTicks();
	m_elapsedTime = m_currentTime - m_lastTime;
	m_lastTime = m_currentTime;

	// sleep for the remaining FPS
	int elapsedTimeMs = SDL_GetTicks() - m_currentTime;
	if(elapsedTimeMs < m_fps)
		SDL_Delay(m_fps - elapsedTimeMs);
}

void Core::trackEvents()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
            {
                m_running = false;
                break;
            }

            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym) 
                {
                    case SDLK_ESCAPE:
                    {
                        m_running = false;
                        break;
                    }

                    case SDLK_LEFT:
                    {
                        m_player.moveLeft();
                        break;
                    }

                    case SDLK_RIGHT:
                    {
                        m_player.moveRight();
                        break;
                    }
                }
                break;
            }
        }
    }
}


}
