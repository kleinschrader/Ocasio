#ifndef CRENDEROBJECT_H
#define CRENDEROBJECT_H

#include <sfml/graphics.hpp>
#include <SFML/System.hpp>

#include <vector>

class cRenderObject : public sf::RenderWindow
{
    public:
        cRenderObject(sf::VideoMode mode, const sf::String &title, int style=sf::Style::Default, const sf::ContextSettings &settings=sf::ContextSettings());
        virtual ~cRenderObject();

        void StartThread();

        void AddObject(sf::Drawable*);
        void RemoveObject(sf::Drawable*);
        void RemoveAndDeleteObject(sf::Drawable*);

        void WaitForPaused();

        void Pause();
        void Resume();
    private:
        static void MainThread(cRenderObject*);


        sf::Thread *RenderThread;

        std::vector <sf::Drawable*>RenderTargets;

        sf::Clock *FrameTimer;

        int FrameTime = 0;
        int FPS = 0;

        bool shouldPause = false;
        bool isPaused = false;
};

#endif // CRENDEROBJECT_H
