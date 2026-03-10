#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;

int main()
{
    srand(time(0));

    // Screen resolution
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window(
        VideoMode(resolution.x, resolution.y), "Timber");

    // Background
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("graphics/background.png"))
        return -1;

    Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    // Tree
    Texture treeTexture;
    if (!treeTexture.loadFromFile("graphics/tree.png"))
        return -1;

    Sprite treeSprite(treeTexture);
    treeSprite.setPosition(resolution.x / 2.f - 150.f, 0);

    // Clouds
    Texture cloudTexture;
    if (!cloudTexture.loadFromFile("graphics/cloud.png"))
        return -1;

    Sprite cloud1(cloudTexture);
    Sprite cloud2(cloudTexture);
    Sprite cloud3(cloudTexture);

    cloud1.setPosition(0, 150);
    cloud2.setPosition(150, 300);
    cloud3.setPosition(300, 450);

    // Bee
    Texture beeTexture;
    if (!beeTexture.loadFromFile("graphics/bee.png"))
        return -1;

    Sprite beeSprite(beeTexture);
    beeSprite.setPosition(resolution.x, 500);

    float beeSpeed = 0.f;
    float beeHeight = 0.f;
    bool beeActive = false;

    bool cloudActive1 = true;

    bool paused = true;

    Clock clock;

    // Time bar
    RectangleShape timeBar;

    const float timeBarStartWidth = 400.f;
    const float timeBarHeight = 80.f;

    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition(
        resolution.x / 2.f - timeBarStartWidth / 2.f,
        resolution.y - 100);

    float timeRemaining = 6.f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

    // Message font
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    Text msgText;
    msgText.setFont(font);
    msgText.setFillColor(Color::White);
    msgText.setCharacterSize(100);
    msgText.setString("Press Enter Key to Start");
    FloatRect textrec = msgText.getLocalBounds();

    while (window.isOpen())
    {
        // Handle events
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = false;
            timeRemaining = 6.0f;
            clock.restart();
        }

        if (!paused)
        {
            Time dt = clock.restart();

            timeRemaining -= dt.asSeconds();

            timeBar.setSize(
                Vector2f(
                    timeBarWidthPerSecond * timeRemaining,
                    timeBarHeight));

            if (timeRemaining <= 0.0)
            {
                paused = true;
            }
            // Spawn bee
            if (!beeActive)
            {
                beeSpeed = rand() % 200 + 200;
                beeHeight = rand() % ((int)resolution.y - 100);

                beeSprite.setPosition(resolution.x, beeHeight);

                beeActive = true;
            }
            // if (!clo)
            else
            {
                beeSprite.setPosition(
                    beeSprite.getPosition().x - beeSpeed * dt.asSeconds(),
                    beeSprite.getPosition().y);

                if (beeSprite.getPosition().x < -100)
                    beeActive = false;
            }

            // if (cloudActive1){
            //     srand=(int)time(0)*10;
            //     cloudSpriteSpeed1=rand()%200;
            //     srand((int)time(0)*10);
            //     cloudSpriteHeight1=rand()%150;
            //     cloudSprite1.setPosition(-200.cloudSpriteHeight1);
            //     cloudSpriteActive1=true;
            // }
            // else{
            //     cloudSprite1.setPosition(cloud)
            // }

            // if (cloudActive1)
            // {
            //     beeSpeed = rand() % 200 + 200;
            //     beeHeight = rand() % ((int)resolution.y - 100);

            //     beeSprite.setPosition(resolution.x, beeHeight);

            //     cloudActive1 = true;
            // }
            // // if (!clo)
            // else
            // {
            //     beeSprite.setPosition(
            //         beeSprite.getPosition().x - beeSpeed * dt.asSeconds(),
            //         beeSprite.getPosition().y);

            //     if (beeSprite.getPosition().x < -100)
            //         cloudActive1 = false;
            // }
        }

        // Draw
        window.clear();

        window.draw(backgroundSprite);
        window.draw(cloud1);
        window.draw(cloud2);
        window.draw(cloud3);
        window.draw(treeSprite);
        window.draw(beeSprite);
        window.draw(timeBar);

        window.display();
    }

    return 0;
}