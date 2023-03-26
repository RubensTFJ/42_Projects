The so_long is a game. In this Project your goal is to use a very simple and basic library, but very intuitive, the Minilibx.

My project was written in C using the concept of objects. Everything on display is an Object, from the floor and the walls, to the Player itself.

The game is themed around the 42 Piscine. The goal of the game, as a Pisciner, is to Collect 'Memory Addresses', avoid 'Seg Faults' and finally get to the 'Exit Pointer'. To achieve your goal you are able to control and move the 'Seg Faults'.

To achieve Movement and Collision, the floor was used as a Bidimensional HashTable. If an Object is not a piece of floor or a piece o wall, it will then be on_top of another object. The Floor objects have a linked list to all the objects standing in its area. When an Object moves, it will check the floor's around it, and verify if they have in their linked list another object "on top" of them. If there is, their distance is calculated to verify if they are colliding, and if they are, what actions have to be taken.

Instructions: 

  - Start Game: To start the game you have to open the so_long Folder in a Linux Terminal, and type the command "./so_long" followed by the name of the map file finished by ".ber". Ex: "./so_long map.ber" ou "./so_long 2map.ber"
  - Goal: Your goal is to Collect 'Memory Addresses', avoid 'Seg Faults' and finally get to the 'Exit Pointer'. If a 'Seg Fault' touches the Player or a 'Memory Address'
you fail.
  - Movement: | WASD |.
  - Ability.Move_Fire: | Space |. You are able to move all 'Seg Faults' at the same time, they will move in the same direction and at the same time that the player does.
One tap will activate movement, another tap will deactivate. Avoid holding Space since it will switch it on and off continuously.
<img width="776" alt="image" src="https://user-images.githubusercontent.com/89268663/226766926-60471dfa-39a4-42ac-8bea-a324cf9cb484.png">
