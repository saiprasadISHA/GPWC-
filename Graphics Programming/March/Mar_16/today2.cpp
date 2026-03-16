#include <SFML/Graphics.hpp>
#include <sstream>
#include <ctime>

using namespace sf;
using namespace std;
void updateBranches(int);
const int NUM_BRANCHES = 6;
enum class side
{
    LEFT,
    RIGHT,
    NONE
};
side branchPosition[NUM_BRANCHES];
Sprite Branches[NUM_BRANCHES];

int main()
{
    // 1. Setup Window
    Vector2f res;
    res.x = VideoMode::getDesktopMode().width;
    res.y = VideoMode::getDesktopMode().height;
    VideoMode vm(res.x, res.y);
    RenderWindow rm(vm, "Timber", Style::Fullscreen);

    // 2. Background
    Texture bgTexture;
    bgTexture.loadFromFile("graphics/background.png");
    Sprite bgSprite;
    bgSprite.setTexture(bgTexture);
    bgSprite.setPosition(0, 0);

    // 3. Tree
    Texture treeTexture;
    treeTexture.loadFromFile("graphics/tree.png");
    Sprite treeSprite;
    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition(res.x / 2 - 300 / 2, 0);

    // 4. Player
    Texture playerTexture;
    playerTexture.loadFromFile("graphics/player.png");
    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(500, res.y - 330);

    // 5. Bees
    Texture beeTexture;
    beeTexture.loadFromFile("graphics/bee.png");
    Sprite beeSprite1, beeSprite2, beeSprite3, beeSprite4;
    beeSprite1.setTexture(beeTexture);
    beeSprite2.setTexture(beeTexture);
    beeSprite3.setTexture(beeTexture);
    beeSprite4.setTexture(beeTexture);

    bool beeActive1 = false, beeActive2 = false, beeActive3 = false, beeActive4 = false;
    float beeSpeed1 = 0.0f, beeSpeed2 = 0.0f, beeSpeed3 = 0.0f, beeSpeed4 = 0.0f;

    // 6. Clouds
    Texture cloudTexture;
    cloudTexture.loadFromFile("graphics/cloud.png");
    Sprite cloudSprite1, cloudSprite2, cloudSprite3;
    cloudSprite1.setTexture(cloudTexture);
    cloudSprite2.setTexture(cloudTexture);
    cloudSprite3.setTexture(cloudTexture);

    bool cloudActive1 = false, cloudActive2 = false, cloudActive3 = false;
    float cloudSpeed1 = 0.0f, cloudSpeed2 = 0.0f, cloudSpeed3 = 0.0f;

    // 7. Time Bar
    RectangleShape timeBar;
    float timeBarStartWidth = 400.0f;
    float timeBarHeight = 40.0f;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((res.x / 2) - timeBarStartWidth / 2.0f, res.y - 100);

    Texture branchTexture;
    branchTexture.loadFromFile("graphics/branch.png");
    for (int i = 0; i < NUM_BRANCHES; i++)
    {
        Branches[i].setTexture(branchTexture);
        Branches[i].setOrigin(220, 20);
        Branches[i].setPosition(-2000, -2000);
    }
    updateBranches(1);
    updateBranches(2);
    updateBranches(3);
    updateBranches(4);
    updateBranches(5);

    /*
    Sprite branchSprite1, branchSprite2, branchSprite3;
    branchSprite1.setTexture(branchTexture);
    branchSprite2.setTexture(branchTexture);
    branchSprite3.setTexture(branchTexture);
    branchSprite1.setPosition(res.x / 2 + 150, 0);
    branchSprite2.setPosition(res.x / 2 + 150, 150);
    branchSprite3.setPosition(res.x / 2 + 150, 300);
    */

    float timeRemaining = 10.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

    Text scoreText, messageText;
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    int score = 0;
    messageText.setFont(font);
    scoreText.setFont(font);
    messageText.setString("Press Enter to start!");
    scoreText.setString("Score = 0");
    messageText.setCharacterSize(80);
    scoreText.setCharacterSize(60);
    messageText.setFillColor(Color::White);
    scoreText.setFillColor(Color::Red);

    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    messageText.setPosition(res.x / 2.0f, res.y / 2.0f);
    scoreText.setPosition(20, 20);

    Clock clock;
    bool paused = true;

    // Texture
    while (rm.isOpen())
    {
        // Event Polling
        Event event;
        while (rm.pollEvent(event))
        {
            if (event.type == Event::Closed)
                rm.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
            {
                paused = !paused;
                timeRemaining = 9.0f;
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
            {
                score++;
                if (score == 101)
                {
                    paused = true;
                    messageText.setString("Winner");
                    textRect = messageText.getLocalBounds();
                    messageText.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
                    messageText.setPosition(res.x / 2.0, res.y / 2.0);
                }
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
            {
                if (score > 0)
                {
                    score--;
                }
            }
        }

        // Input
        if (Keyboard::isKeyPressed(Keyboard::Escape))
            rm.close();

        // if (Keyboard::isKeyPressed(Keyboard::Enter)) {
        //     paused = !paused;
        //     timeRemaining=9.0f;
        // }

        if (!paused)
        {
            Time dt = clock.restart();
            // Time Bar Update
            timeRemaining -= dt.asSeconds();
            timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));
            if (timeRemaining <= 0.0)
            {
                paused = true;
                messageText.setString("Time Out!!");
                textRect = messageText.getLocalBounds();
                messageText.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
                messageText.setPosition(res.x / 2.0, res.y / 2.0);
            }
            // Bee Logic
            if (!beeActive1)
            {
                beeSpeed1 = (rand() % 200) + 200;
                float height = (rand() % (int)(res.y - 100)) + 50;
                beeSprite1.setPosition(res.x + 200, height);
                beeActive1 = true;
            }
            else
            {
                beeSprite1.move(-beeSpeed1 * dt.asSeconds(), 0);
                if (beeSprite1.getPosition().x < -100)
                    beeActive1 = false;
            }

            // Cloud 1: Height 0 to 150
            if (!cloudActive1)
            {
                srand((int)time(0) * 10);
                cloudSpeed1 = (rand() % 200);
                srand((int)time(0) * 10);
                float height = rand() % 150;
                cloudSprite1.setPosition(-200, height);
                cloudActive1 = true;
            }
            else
            {
                cloudSprite1.move(cloudSpeed1 * dt.asSeconds(), 0);
                if (cloudSprite1.getPosition().x > res.x)
                    cloudActive1 = false;
            }

            // Cloud 2: Height 150 to 300
            if (!cloudActive2)
            {
                srand((int)time(0) * 20);
                cloudSpeed2 = (rand() % 200);
                srand((int)time(0) * 20);
                float height = (rand() % 150);
                cloudSprite2.setPosition(-200, height);
                cloudActive2 = true;
            }
            else
            {
                cloudSprite2.move(cloudSpeed2 * dt.asSeconds(), 0);
                if (cloudSprite2.getPosition().x > res.x)
                    cloudActive2 = false;
            }

            // Cloud 3: Height 300 to 600
            if (!cloudActive3)
            {
                srand((int)time(0) * 30);
                cloudSpeed3 = (rand() % 200);
                srand((int)time(0) * 30);
                float height = (rand() % 300) - 150;
                cloudSprite3.setPosition(-200, height);
                cloudActive3 = true;
            }
            else
            {
                cloudSprite3.move(cloudSpeed3 * dt.asSeconds(), 0);
                if (cloudSprite3.getPosition().x > res.x)
                    cloudActive3 = false;
            }

            // For Branches
            for (int i = 0; i < NUM_BRANCHES; i++)
            {
                if (branchPosition[i] == side::LEFT)
                {
                    float branchHeight = i * 150;
                    Branches[i].setRotation(180); // flip
                    Branches[i].setPosition(465, branchHeight);
                }
                else if (branchPosition[i] == side::RIGHT)
                {
                    float branchHeight = i * 150;
                    Branches[i].setRotation(0); // No flip
                    Branches[i].setPosition(1100, branchHeight);
                }
                else
                {
                    float branchHeight = i * 150;
                    Branches[i].setPosition(3000, branchHeight);
                }
            }

            updateBranches(1);
            updateBranches(2);
            updateBranches(3);
            updateBranches(4);
            updateBranches(5);

            // test updation of score with left and right arrow
            //  if(Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::Right)){
            //      score++;
            //  }

            std::stringstream ss;
            ss << "Score = " << score;
            scoreText.setString(ss.str());
        }

        // Rendering
        rm.clear();
        rm.draw(bgSprite);
        rm.draw(cloudSprite1);
        rm.draw(cloudSprite2);
        rm.draw(cloudSprite3);
        for (int i = 0; i < NUM_BRANCHES; i++)
        {
            rm.draw(Branches[i]);
        }

        rm.draw(treeSprite);
        // if (!paused)
        // {
        //     rm.draw(branchSprite1);
        //     rm.draw(branchSprite2);
        //     rm.draw(branchSprite3);
        // }
        rm.draw(beeSprite1);
        rm.draw(timeBar);
        rm.draw(scoreText);
        if (paused)
        {
            rm.draw(messageText);
        }
        rm.draw(playerSprite);
        rm.display();
    }
    return 0;
}

void updateBranches(int seed)
{
    // Shift each position one place to the right shifting from last
    for (int i = NUM_BRANCHES - 1; i > 0; i--)
    {
        branchPosition[i] = branchPosition[i - 1];
    }
    // update 0th position
    srand(time(0) + seed);
    int r = rand() % 3;
    switch (r)
    {
    case 0:
        branchPosition[0] = side::LEFT;
        break;

    case 1:
        branchPosition[0] = side::RIGHT;
        break;
    default:
        branchPosition[0] = side::NONE;
    }
}
