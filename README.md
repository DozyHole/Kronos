# Kronos
Framework for creating a game world in which the player can travel to any point in time, alter the past and have real effects on the future.


Challenges:

1. family hierarchy for living entities - if you remove one from the past, all childern are affected
  - static tree with all possibilies, traverse tree when event in time alters something.

2. efficient lookup (through space and time) of what entities should be present on screen
  - use 2 dimensions of space and 1 dimension of time to build a geometric representation of the world, we can then do distance or bounds checks very similar to any 2d/3d game.
  - utilise 'rountines' which have a min and max bound in space and time, if routine overlaps current space-time position then we consider rendering that entity, depending on where it is within the routine.

3. enitity component system and data oriented structures, to provide flexibility and efficiency when creating and iterating entities
