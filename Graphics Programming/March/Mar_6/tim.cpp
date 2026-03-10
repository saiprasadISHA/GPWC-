#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;

int main()
{
    // ---------------- SCREEN ----------------
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    VideoMode vm(resolution.x, resolution.y);
    RenderWindow window(vm, "Timber Window");
    Clock clock;
    while (window.isOpen())
    {
        // Handle user event
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
        }

        // Scenes update if game is running
        if (!beeActive)
        {
            srand(time(0) * 10);

            beeSpeed = rand() % 200 + 200;
            srand(time(0) * 20);
            beeHeight = rand() % 500 + 500;
            beeSprite.setPosition(2000, beeHeight, beeActive = true);
        }
        else
        {
            beeSprite.setPosition(beeSprite.getPosition().x - dt.asSeconds() * beeSpeed, beeSprite1.getPosition().y);
            if (beeSprite.getPosition().x < -100)
            {
                beeActive = false;
            }
        }
        window.clear();
        window.draw
    }
}