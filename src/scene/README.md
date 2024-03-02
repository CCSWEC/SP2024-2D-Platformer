# 2D Platformer Game
## Entity Component System

This directory has an implementation of a (pseudo-) Entity Component System, or ECS, for our 2D Platformer game.

### Concepts

There are three main concepts in an ECS:

- **Scenes** are entire game worlds or menus. Only one scene can be active at a time.
- **Entities** are game objects, like drawable sprites or logical groups of multiple sprites.
- **Components** add programmed logic, like motion or control, to attach to entities.

#### Nested Entities

Entities can have nested "child" entities inside them.
This is especially useful for grouping the positions of entities.
For example, a boss entity might have multiple separately moving sprites that belong to it, but are all relative to the boss's position.

If an entity is the child of another entity, then it is said that its "parent" is the entity that it is a child of.

### Using the ECS

ECS classes each have their own header (ending with `.hpp`) and source file within this `scene` directory.
For example, to include the `Entity` class, use `#include "scene/Entity.hpp"`.

Every class in the ECS is in the `Platformer2D` namespace.
In your header files, use `Platformer2D::` before ECS class names,
and you can use `using namespace Platformer2D;` at the top of your source files.

You should check out the comments in the header files for documentation. Below is a brief description for getting started.

#### Basic ECS Classes

##### `Entity` class

```c++
#include "scene/Entity.hpp"
```

The `Entity` class represents a game entity. It has an `update` method to call the update logic on its components and then its child entities.

The `addChild` and `removeChild` methods can be used to manage the hierarchy, and `getParent` and `setParent` can access the parent entity, if any.

Components can be attached and detached with `addComponent` and `removeComponent`, respectively, and `findComponent` can get an attached component of a given type, if any.

##### `Component` class

```c++
#include <scene/Component.hpp>
```

`Component` is an abstract base class for all components.

Extend this class and implement its `update` method to create a component class.

#### Useful Components

##### `Transform` class

```c++
#include <scene/components/Transform.hpp>
```

While it does not add any update logic, the `Transform` component keeps track of the position, scale, and rotation of an entity relative to its parent entity, if any.

Other components may use this by getting an entity's `Transform` using `findComponent`.

To access the properties, use the `getPosition`, `setPosition`, `getScale`, `setScale`, `getRotation`, and `setRotation` methods.