#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    VideoMode vm(resolution.x, resolution.y);

    RenderWindow window(vm, "Timber");
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("graphics/background.png");
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    while (window.isOpen())
    {
        // Discrete event handing
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            //

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
            window.clear();
            window.draw(backgroundSprite);
            window.display();
        }
    }
}