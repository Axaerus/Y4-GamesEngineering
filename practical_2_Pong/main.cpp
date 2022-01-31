#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");

const Keyboard::Key controls[4] = {
    Keyboard::A, //Move player 1 up
    Keyboard::Z, //Move player 1 down
    Keyboard::Up, //Move player 2 up
    Keyboard::Down //Move player 2 down
};

const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;

CircleShape ball;
RectangleShape paddles[2];

void Load() {
    //Set size and origin of paddles
    for (auto& p : paddles) {
        p.setSize(paddleSize - Vector2f(3, 3));
        p.setOrigin(paddleSize / 2.f);
    }
    //Set size and origin of ball
    ball.setRadius(ballRadius);
    ball.setOrigin(Vector2f(gameWidth / 2, gameHeight / 2));
    paddles[0].setPosition(Vector2(10.f + paddleSize.x / 2.f, gameHeight / 2.f));
    paddles[1].setPosition(Vector2(10.f + paddleSize.x / 2.f, gameHeight / 2.f));
    //reset ball position
    ball.setPosition(Vector2f(gameWidth / 2, gameHeight / 2));
}

void Update(RenderWindow &window){
	//Reset clock, recalculate deltatime
    static Clock clock;
    float dt = clock.restart().asSeconds();
    //check and consume events
    Event event; 
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return;
        }
    }

    //Quite via ESC key
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

    //handle paddle movement
    float direction = 0.0f;
    if (Keyboard::isKeyPressed(controls[0])) {
        direction--;
    }

    if (Keyboard::isKeyPressed(controls[1])) {
        direction++;
    }
    paddles[0].move(Vector2(0.f, direction * paddleSpeed * dt));
}

void Render(RenderWindow &window){
	// Draw everthing
    for (auto& p : paddles) {
        window.draw(p);
    }
    window.draw(ball);
}

int main(){
    //initialise and load
    RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
    window.setVerticalSyncEnabled(true);
    Load();

    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
    }
    return 0;
}