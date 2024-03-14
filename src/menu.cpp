#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
class Menu
{
public:
    Menu(sf::RenderWindow& window) : window(window)
    {
        window.draw(rectangle); 
        rectangle.setSize(sf::Vector2f(60, 60)); 
        rectangle.setFillColor(sf::Color::White); 
        rectangle.setOutlineColor(sf::Color::Blue);
        rectangle.setOutlineThickness(2);
        rectangle.setPosition(0, 60);      
    }
    void setScore(int score)
    {
        this -> score = score;
    }
    void setHealth(int health)
    {
        this -> health = health;
    }
    int getScore()
    {
        return this -> score;
    }
    int getHealth()
    {
        return this -> health;
    }
    void draw()
    {
        window.draw(rectangle);
    }
    void display()
    {
         sf::Text scoreText;
       sf::String o1 = "Score: " + std::to_string(getScore());
        scoreText.setString(o1);
        scoreText.setCharacterSize(24);
         scoreText.setPosition(20, 20);
          sf::Text healthText;
          sf::String o2 = "Health: " + std::to_string(getHealth());
        healthText.setString(o2);
        healthText.setCharacterSize(24);
         scoreText.setPosition(20, 50);
        window.draw(rectangle);
        window.draw(scoreText);
        window.draw(healthText);
    }
    private:
    int score = 0, health = 100;
    int* address_h = &health;
    int* address_s = &score;
    sf::RenderWindow& window;
    sf::RectangleShape rectangle;
};
