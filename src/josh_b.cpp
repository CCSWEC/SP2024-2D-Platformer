#include "josh_b.hpp"

JoshB::JoshB(sf::RenderWindow& window) : window(window), circle(200) {}

void JoshB::draw() {
    // change the number of sides (points) to 100
    circle.setPointCount(125);
    window.draw(circle);
}

void JoshB::update() {
    // set the absolute position of the entity
    // circle.setPosition(10.f, 50.f);

    // move the entity relatively to its current position
    circle.move(0.02f, 0.05f);

    // retrieve the absolute position of the entity
    // sf::Vector2f position = circle.getPosition(); // = (15, 55)
}