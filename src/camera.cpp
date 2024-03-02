class Camera {
public:
    Camera(sf::RenderWindow& window) : window(window) {}

    void followPlayer(float p) {
        // Adjust camera position based on player's X coordinate
        // Example: Center the camera on the player
        sf::View view = window.getView();
        view.setCenter(p, view.getCenter().y);
        window.setView(view);
    }

private:
    sf::RenderWindow& window;
};