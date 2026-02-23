#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    VideoMode vm(resolution.x, resolution.y);
    // abhipsamohapatra270805@gmail.com
    RenderWindow window(vm, "Hello");
    RectangleShape rect;
    Vector2f d1;
    d1.x = 200.0f;
    d1.y = 100.0f;
    rect.setSize(d1);
    rect.setOutlineThickness(5);
    rect.setOutlineColor(Color::Green);
    rect.setFillColor(Color::Magenta);
    rect.setPosition(Vector2f((resolution.x - 1) / 2.0 - d1.x, (resolution.y - 1) / 2.0 - d1.y));
    while (window.isOpen())
    {
        window.clear(Color::Blue);
        window.draw(rect);
        window.display();
    }
}