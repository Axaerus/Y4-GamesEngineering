#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

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

RectangleShape background(sf::Vector2f(gameWidth, gameHeight));
CircleShape ball;
RectangleShape paddles[2];

Vector2f ballVelocity;
bool server = false;

void Reset() {
    ball.setPosition(Vector2f(gameWidth / 2, gameHeight / 2));
    ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };
}

void Load() {
    //Set size and origin of paddles
    for (auto& p : paddles) {
        p.setSize(paddleSize - Vector2f(3, 3));
        p.setOrigin(paddleSize / 2.f);
    }
    //Set size and origin of ball
    ball.setRadius(ballRadius);
    ball.setOrigin(Vector2f(ballRadius, -ballRadius));
    paddles[0].setPosition(Vector2(10.f + paddleSize.x / 2.f, gameHeight / 2.f));
    paddles[1].setPosition(Vector2(gameWidth - (10.f + paddleSize.x / 2.f), gameHeight / 2.f));
    //reset ball position
    Reset();

    background.setFillColor(Color::Black);
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

    ball.move(ballVelocity * dt);

    //Quit via ESC key
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

    //handle paddle movement
    float direction = 0.0f;
    for (int x = 0; x < sizeof(paddles) / sizeof(*paddles); x++) {
        if (Keyboard::isKeyPressed(controls[x*2])) {
            direction--;
        }

        if (Keyboard::isKeyPressed(controls[x*2+1])) {
            direction++;
        }
        paddles[x].move(Vector2(0.f, direction * paddleSpeed * dt));
        direction = 0.0f;
    }
    

    // check ball collision
    const float bx = ball.getPosition().x;
    const float by = ball.getPosition().y;
    if (by > gameHeight || by < 0) {
        ballVelocity.x *= 1.1f;
        ballVelocity.y *= -1.1f;
        ball.move(Vector2(0.f, -10.f));
    }
    else if (bx > gameWidth || bx < 0) {
        Reset();
    }
    else if (
        //ball is inline or behind paddle
        bx < paddles[0].getPosition().x + (0.5 * paddleSize.x) &&
        //AND ball is below top edge of paddle
        by > paddles[0].getPosition().y - (paddleSize.y * 0.5) &&
        //AND ball is above bottom edge of paddle
        by < paddles[0].getPosition().y + (paddleSize.y * 0.5)
        ) {
        // bounce off left paddle
        ballVelocity.x *= -1.1f;
    }
    else if (//ball is inline or behind paddle
        bx > paddles[1].getPosition().x - (0.5 * paddleSize.x) &&
        //AND ball is below top edge of paddle
        by > paddles[1].getPosition().y - (paddleSize.y * 0.5) &&
        //AND ball is above bottom edge of paddle
        by < paddles[1].getPosition().y + (paddleSize.y * 0.5)
        ) {
        // bounce off right paddle
        ballVelocity.x *= -1.1f;
    }
}

void Render(RenderWindow &window){
	// Draw everthing
    window.draw(background);
    window.draw(paddles[0]);
    window.draw(paddles[1]);
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
        window.display();
    }
    return 0;
}