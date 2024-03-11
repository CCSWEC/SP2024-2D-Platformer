#pragma once

#include "../Component.hpp"
#include <SFML/System.hpp>

namespace Platformer2D
{

/**
 * @brief Component that tracks position, scale, and rotation
*/
class Transform : public Component
{
    public:
        /**
         * @brief Create a new Transform at position (0, 0) with unit scaling and no rotation
         * @returns The new Transform
        */
        Transform();

        /**
         * @brief Create a new Transform that is a copy of another Transform
        */
        Transform(const Transform& other);

        /**
         * @brief Create a new Transform at the given position with unit scaling and no rotation
         * @param position The position for the Transform
         * @returns The new Transform
        */
        Transform(sf::Vector2<int> position);

        /**
         * @brief Create a new Transform at the given position with the given scaling and no rotation
         * @param position The position for the Transform
         * @param scale The scaling vector for the Transform
         * @returns The new Transform
        */
        Transform(sf::Vector2<int> position, sf::Vector2<double> scale);

        /**
         * @brief Create a new Transform at the given position with the given scaling and the given rotation
         * @param position The position for the Transform
         * @param scale The scaling vector for the Transform
         * @param rotation The rotation in radians for the given Transform
         * @returns The new Transform
        */
        Transform(sf::Vector2<int> position, sf::Vector2<double> scale, double rotation);

        /**
         * @brief Create a new Transform at the given position with unit scaling and the given rotation
         * @param position The position for the Transform
         * @param rotation The rotation in radians for the given Transform
         * @returns The new Transform
        */
        Transform(sf::Vector2<int> position, double rotation);

        /**
         * @brief Get the position of this Transform
         * @returns The position, relative to the parent transform, if any
        */
        sf::Vector2<int> getPosition() const;

        /**
         * @brief Get the scale of this Transform
         * @returns The scale, relative to the parent transform, if any
        */
        sf::Vector2<double> getScale() const;

        /**
         * @brief Get the rotation of this Transform
         * @returns The rotation, relative to the parent transform, if any
        */
        double getRotation() const;

        /**
         * @brief Set the position of this Transform
         * Sets the relative position with respect to the parent transform, if any.
         * @param position The new relative position
        */
        void setPosition(sf::Vector2<int> position);

        /**
         * @brief Set the scale of this Transform
         * Sets the relative scale with respect to the parent transform, if any.
         * @param scale The new relative scale
        */
        void setScale(sf::Vector2<double> scale);

        /**
         * @brief Set the rotation in radians of this Transform
         * Sets the relative rotation with respect to the parent transform, if any.
         * @param scale The new relative rotation in radians
        */
        void setRotation(double rotation);

        /**
         * @brief Resolve the absolute transform
         * Since attached Transforms are usually relative to parent entities,
         * this method resolves the absolute transform.
         * Do not attach the returned transform to an Entity.
         * @returns The absolute transform
        */
        Transform absolute();

        virtual void update();

    private:
        /**
         * @brief The position vector of this Transform
         * This field expresses the position relative to the parent transform, if any.
        */
        sf::Vector2<int> position;

        /**
         * @brief The scaling vector of this Transform
         * This field expresses the scale relative to the parent transform, if any.
        */
        sf::Vector2<double> scale;

        /**
         * @brief The rotation in radians of this Transform
         * This field expresses the rotation relative to the parent transform, if any.
        */
        double rotation;
};

}