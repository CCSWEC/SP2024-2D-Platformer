#pragma once

#include <vector>

namespace Platformer2D
{

class Component;

/**
 * @brief Abstract base class for every scene entity
*/
class Entity {
    public:
        /**
         * @brief Update all Components on this Entity, and then update all child entities
        */
        void update();

        /**
         * @brief Get the vector of child entities
         * Child entities are entities "inside" this one,
         * which are positioned relative to this Entity's position.
         * @return The vector of child entities
        */
        std::vector<Entity*> getChildren();

        /**
         * @brief Add a new child entity
         * @param child The child to add
        */
        void addChild(Entity* child);

        /**
         * @brief Remove a given child entity from this entity's child vector
         * If the given entity is not a child of this entity, nothing happens.
         * This does not delete the child.
         * If the child should be deleted, the caller must do that.
         * @param child The child to remove
        */
        void removeChild(Entity* child);

        /**
         * @brief Get the parent Entity
         * If this Entity is a child of another Entity,
         * then the parent is the Entity that this Entity is a child of.
         * Otherwise, the parent is null.
         * @return The parent Entity
        */
        Entity* getParent();

        /**
         * @brief Get the vector of Components attached to this Entity
         * Components are objects that add update logic
         * @returns The vector of Components attached to this Entity
        */
        std::vector<Component*> getComponents();

        /**
         * @brief Attach a Component to this Entity
         * @param component The Component to attach
        */
        void addComponent(Component* component);

        /**
         * @brief Detach the given Component from this Entity and delete it
         * If the given Component is not attached to this Entity, nothing happens.
         * The component WILL be deleted.
         * @param component The Component to detach
        */
        void removeComponent(Component* component);

        /**
         * @brief A virtual destructor is required in a base class
        */
        virtual ~Entity();
    
    private:
        /**
         * @brief vector of child entities
         * Child entities are entities "inside" this one,
         * which are positioned relative to this Entity's position.
        */
        std::vector<Entity*> children;

        /**
         * @brief The parent Entity
         * If this Entity is a child of another Entity,
         * then the parent is the Entity that this Entity is a child of.
         * Otherwise, the parent is null.
        */
        Entity* parent;

        /**
         * @brief vector of Components attached to this Entity
         * Components are objects that add update logic
        */
        std::vector<Component*> components;

        /**
         * @brief Set the parent Entity
         * This should only be used in addChild and removeChild
         * @param parent The new parent Entity
        */
        void setParent(Entity* parent);
};

}
