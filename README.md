# 2D Platformer Game

Check the [build instructions document](BUILD_INSTRUCTIONS.md) for setting up your environment and compiling this code.

---
We will be using the SFML libary to create a 2d platformer

Here is a very basic idea of a 2D platformer:

Collision Detection:
Implement collision detection between the player character, platforms, obstacles, and other game objects.
Use bounding boxes or pixel-perfect collision detection techniques to determine if objects are colliding.
Handle collisions by calculating the intersection points or areas between objects and resolving them appropriately (e.g., deflecting the player character when hitting a wall).

Character Movement:
Allow the player character to move left and right, jump, and interact with the environment.
Implement physics-based movement for the character, including acceleration, velocity, and gravity.
Handle user input (keyboard, gamepad) to control the character's movement and actions.
Add animations for character movement, jumping, and other interactions.

Level Design:
Create 2D level layouts with platforms, obstacles, enemies, and collectibles.
Design challenging and engaging levels that require the player to navigate through different environments, avoid hazards, and solve puzzles.
Use tilemaps or sprite sheets to create and organize the visual elements of the levels.
Implement camera movement to follow the player character as they navigate through the level.

Game Mechanics:
Implement game mechanics such as double jumping, wall jumping, power-ups, checkpoints, and enemy interactions.
Add interactive elements like switches, moving platforms, springs, and portals to enhance gameplay variety.
Design gameplay challenges that test the player's skills in platforming, timing, and precision.

UI and Feedback:
Display important information to the player, such as the player's health, score, level progress, and collected items.
Provide visual and auditory feedback for player actions, interactions, and game events (e.g., collecting a coin, defeating an enemy).
Implement menus, HUD elements, and other user interface components to enhance the player experience.

Remember this is just a basic idea, you as a group needs to expand more on it and add any features you'd like.

Challenges (you do not have to implement these (you can implement one or more) )
  1. Add an xp feature, the more a character levels, the more their base dmg
  2. Add a speedrun option
  3. Add in a boss fight
  4. Implement a multiplayer feature (2 players max) 

SFML general tutorials (everything you need to know about sfml and how to use it) https://www.sfml-dev.org/tutorials/2.6/

<!-- Reach out to togunleye1@collin.edu if you have questions. -->