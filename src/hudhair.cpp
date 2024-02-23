#include "hudhair.hpp"

Hudhair::Hudhair(sf::RenderWindow& window) : window(window), circle(200) {}

void Hudhair::draw() {
    // change the number of sides (points) to 100
    circle.setPointCount(75);
    window.draw(circle);
}

void Hudhair::update() {
    // set the absolute position of the entity
    // circle.setPosition(10.f, 50.f);

    // move the entity relatively to its current position
    circle.move(0.10, 0.05f);

    // retrieve the absolute position of the entity
    // sf::Vector2f position = circle.getPosition(); // = (15, 55)
}