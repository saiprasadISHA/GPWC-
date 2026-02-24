#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Namaskaram");

    // Game loop
    while (window.isOpen())
    {
        window.clear();

        // draw objects
        window.display();
    }
    return 0;
}
