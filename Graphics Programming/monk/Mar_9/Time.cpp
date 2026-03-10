#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    VideoMode vm(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
    RenderWindow window(vm, "Timber");
    Texture backgroundTexture, treeTexture, playerTexture, axeTexture, cloudTexture, beeTexture;
    backgroundTexture.loadFromFile("graphics/background.png");
    treeTexture.loadFromFile("graphics/tree.png");
    playerTexture.loadFromFile("graphics/player.png");
    axeTexture.loadFromFile("graphics/axe.png");
    cloudTexture.loadFromFile("graphics/cloud.png");
    beeTexture.loadFromFile("graphics/bee.png");
    Sprite backgroundSprite, treeSprite, playerSprite, axeSprite,
        cloudSprite1, cloudSprite2,
        beeSprite1, beeSprite2, beeSprite3, beeSprite4;
    backgroundSprite.setTexture(backgroundTexture);
    treeSprite.setTexture(treeTexture);
    playerSprite.setTexture(playerTexture);
    axeSprite.setTexture(axeTexture);
    cloudSprite1.setTexture(cloudTexture);
    cloudSprite2.setTexture(cloudTexture);
    beeSprite1.setTexture(beeTexture);
    beeSprite2.setTexture(beeTexture);
    beeSprite3.setTexture(beeTexture);
    beeSprite4.setTexture(beeTexture);
    backgroundSprite.setPosition(0, 0);
    treeSprite.setPosition(VideoMode::getDesktopMode().width / 2.0f - 150, 0);
    playerSprite.setPosition(150, VideoMode::getDesktopMode().height - 192 * 1.5);
    axeSprite.setPosition(300, VideoMode::getDesktopMode().height - 96 * 1.5);
    cloudSprite1.setPosition(100, VideoMode::getDesktopMode().height / 4.0f - 100);
    cloudSprite1.setPosition(VideoMode::getDesktopMode().width - 400, VideoMode::getDesktopMode().height / 4.0f - 70);
    beeSprite1.setPosition(100, VideoMode::getDesktopMode().height / 2.0f);
    beeSprite2.setPosition(200, VideoMode::getDesktopMode().height / 2.0f);
    beeSprite3.setPosition(300, VideoMode::getDesktopMode().height / 2.0f);
    beeSprite4.setPosition(400, VideoMode::getDesktopMode().height / 2.0f);
    // float beeDist = 0.2;
    // float cloudDist = 0.1;
    // int bee1Direction = 1, bee2Direction = 1, bee3Direction = 0, bee4Direction = 1;

    // <class>
    float beeSpeed = 0.0f;
    float beeHeight = 0.0f;
    bool beeActive = false;
    Clock clock;

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
        // beeSprite1.setOrigin(beeSprite1.getLocalBounds().width / 2.0f, beeSprite1.getLocalBounds().height / 2.0f);
        // beeSprite2.setOrigin(beeSprite2.getLocalBounds().width / 2.0f, beeSprite2.getLocalBounds().height / 2.0f);
        // beeSprite3.setOrigin(beeSprite3.getLocalBounds().width / 2.0f, beeSprite3.getLocalBounds().height / 2.0f);
        // beeSprite4.setOrigin(beeSprite4.getLocalBounds().width / 2.0f, beeSprite4.getLocalBounds().height / 2.0f);
        // if (bee1Direction == 1) {
        //     if (beeSprite1.getPosition().x > 0) {
        //         beeSprite1.setPosition(beeSprite1.getPosition().x - beeDist, beeSprite1.getPosition().y);
        //     } else {
        //         bee1Direction = -1;
        //         beeSprite1.setScale(-1.0f, 1.0f);
        //     }
        // } else {
        //     if (beeSprite1.getPosition().x < VideoMode::getDesktopMode().width) {
        //         beeSprite1.setPosition(beeSprite1.getPosition().x + beeDist, beeSprite1.getPosition().y);
        //     } else {
        //         bee1Direction = 1;
        //         beeSprite1.setScale(1.0f, 1.0f);
        //     }
        // }
        // if (bee2Direction == 1) {
        //     if (beeSprite2.getPosition().x > 0) {
        //         beeSprite2.setPosition(beeSprite2.getPosition().x - beeDist, beeSprite2.getPosition().y);
        //     } else {
        //         bee2Direction = -1;
        //         beeSprite2.setScale(-1.0f, 1.0f);
        //     }
        // } else {
        //     if (beeSprite2.getPosition().x < VideoMode::getDesktopMode().width) {
        //         beeSprite2.setPosition(beeSprite2.getPosition().x + beeDist, beeSprite2.getPosition().y);
        //     } else {
        //         bee2Direction = 1;
        //         beeSprite2.setScale(1.0f, 1.0f);
        //     }
        // }
        // if (bee3Direction == 1) {
        //     if (beeSprite3.getPosition().x > 0) {
        //         beeSprite3.setPosition(beeSprite3.getPosition().x - beeDist, beeSprite3.getPosition().y);
        //     } else {
        //         bee3Direction = -1;
        //         beeSprite3.setScale(-1.0f, 1.0f);
        //     }
        // } else {
        //     if (beeSprite3.getPosition().x < VideoMode::getDesktopMode().width) {
        //         beeSprite3.setPosition(beeSprite3.getPosition().x + beeDist, beeSprite3.getPosition().y);
        //     } else {
        //         bee3Direction = 1;
        //         beeSprite3.setScale(1.0f, 1.0f);
        //     }
        // }
        // if (bee4Direction == 1) {
        //     if (beeSprite4.getPosition().x > 0) {
        //         beeSprite4.setPosition(beeSprite4.getPosition().x - beeDist, beeSprite4.getPosition().y);
        //     } else {
        //         bee4Direction = -1;
        //         beeSprite4.setScale(-1.0f, 1.0f);
        //     }
        // } else {
        //     if (beeSprite4.getPosition().x < VideoMode::getDesktopMode().width) {
        //         beeSprite4.setPosition(beeSprite4.getPosition().x + beeDist, beeSprite4.getPosition().y);
        //     } else {
        //         bee4Direction = 1;
        //         beeSprite4.setScale(1.0f, 1.0f);
        //     }
        // }
        // if (cloudSprite1.getPosition().x < VideoMode::getDesktopMode().width) {
        //     cloudSprite1.setPosition(cloudSprite1.getPosition().x + cloudDist, cloudSprite1.getPosition().y);
        // } else {
        //     cloudSprite1.setPosition(0, cloudSprite1.getPosition().y);
        // }
        // if (cloudSprite2.getPosition().x < VideoMode::getDesktopMode().width) {
        //     cloudSprite2.setPosition(cloudSprite2.getPosition().x + cloudDist, cloudSprite2.getPosition().y);
        // } else {
        //     cloudSprite2.setPosition(0, cloudSprite2.getPosition().y);
        // }

        Time dt = clock.restart();
        if (!beeActive)
        {
            srand(time(0) * 10);
            beeSpeed = rand() % 200 + 200;
            srand(time(0) * 20);
            beeHeight = rand() % 500 + 500;
            beeSprite1.setPosition(2000, beeHeight);
            beeActive = true;
        }
        else
        {
            beeSprite1.setPosition(beeSprite1.getPosition().x - dt.asSeconds() * beeSpeed, beeSprite1.getPosition().y);
            if (beeSprite1.getPosition().x < -100)
            {
                beeActive = false;
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        // window.draw(cloudSprite1);
        // window.draw(cloudSprite2);
        window.draw(treeSprite);
        // window.draw(playerSprite);
        window.draw(beeSprite1);
        window.draw(beeSprite2);
        window.draw(beeSprite3);
        window.draw(beeSprite4);
        window.display();
    }
    return 0;
}