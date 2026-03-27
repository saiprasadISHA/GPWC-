#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <SFML/Graphics.hpp>

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong !!!", Style::Fullscreen);

    // Declare and initialize score and lives variable
    int score = 0;
    int lives = 3;

    // Craete a bat
    Bat bat(window.getSize().x / 2.0, window.getSize().y - 10);

    // Create a ball
    Ball ball(window.getSize().x / 2 / 0, 0);

    // Create a text object called HUD (Heads Up Display)
    Font font;
    font.loadFromFile("/home/iteradmin/Sai GPWC/Mar_27/Pong");
    // Set font
    Text hud;
    hud.setFont(font);
    // Set font size
    hud.setCharacterSize(75.0);
    // Set font color
    hud.setColor(Color::Red);
    // Set Position of the text
    hud.setPosition(20.0, 20.0);
    // Declare a clock object for timing
    Clock clock;

    // Game loop
    while (window.isOpen())
    {

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

        // Handle player input
        // For left cursor
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (bat.get_Position().left <= 0)
            {
                bat.stopLeft();
            }
            else
            {
                bat.moveLeft();
            }
        }
        else
        {
            bat.stopLeft();
        }

        // Right cursor
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (bat.get_Position().left + bat.get_Position().width >= 1920)
            {
                bat.stopRight();
            }
            else
            {
                bat.moveRight();
            }
        }
        else
        {
            bat.stopRight();
        }

        // Update delta time
        Time dt = clock.restart();
        // Update bat
        bat.update(dt);
        // Update ball
        ball.update(dt);

        // Update the HUD text
        std::stringstream ss;
        ss << "SCORE:" << score << "LIVES:" << lives;
        hud.setString(ss.str());

        // Handle ball hitting the bottom
        if (ball.getPosition().top >= window.getSize().y)
        {
            --lives;
            if (lives <= 0)
            {
                lives = 3;
                score = 0;
            }

            ball.reboundBottom();
        }
        // doubt

        // Handle ball hitting top
        if (ball.getPosition().top <= 0)
        {
            score++;
            ball.reboundBatOrTop();
        }

        // Handle ball hitting sides
        if (ball.getPosition().left <= 0 || ball.getPosition.left + ball.getPosition().width >= window.getSize().x)
        {
            ball.reboundSides();
        }
    }
}