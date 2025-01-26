#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;

const float paddleWidth = 100.f;
const float paddleHeight = 20.f;
const float ballRadius = 10.f;
const float windowWidth = 800.f;
const float windowHeight = 600.f;

int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong Game");

    sf::RectangleShape paddle(sf::Vector2f(paddleWidth, paddleHeight));
    paddle.setFillColor(sf::Color::Green);
    paddle.setPosition(windowWidth / 2 - paddleWidth / 2, windowHeight - paddleHeight - 10);

    sf::CircleShape ball(ballRadius);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(windowWidth / 2 - ballRadius, windowHeight / 2 - ballRadius);

    sf::Vector2f ballVelocity(0.3f, 0.3f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle.getPosition().x > 0) {
            paddle.move(-0.5f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle.getPosition().x + paddleWidth < windowWidth) {
            paddle.move(0.5f, 0.f);
        }

        ball.move(ballVelocity);

        if (ball.getPosition().x <= 0 || ball.getPosition().x + ballRadius * 2 >= windowWidth) {
            ballVelocity.x = -ballVelocity.x;
        }
        if (ball.getPosition().y <= 0) {
            ballVelocity.y = -ballVelocity.y;
        }
        if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds())) {
            ballVelocity.y = -ballVelocity.y;
        }
        if (ball.getPosition().y + ballRadius * 2 >= windowHeight) {
            cout << "Game Over!" << endl;
            window.close();
        }

        window.clear();
        window.draw(paddle);
        window.draw(ball);
        window.display();
    }

    return 0;
}