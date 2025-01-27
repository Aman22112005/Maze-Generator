 Hello everyone,
 
27 Jan 2025:
It's already been two months since i start learning C as my first programming language. I've been working on a project to generate a maze using a simple backtracking algorithm. This code defines a 2D array to represent the maze, with '0' indicating walls and ' ' indicating open paths.

           The generator function recursively explores the maze, randomly choosing a direction to move in. If a move is possible and leads to a new unexplored area, it marks the cell as visited by creating path and continues the exploration. If the algorithm reaches a dead end, it backtracks to the previous cell, where movement is possible,i.e move possible is true, and tries a different direction.
           
           The move_possible and can_move functions determine if a move is valid based on the surrounding cells. The move function updates the current position based on the chosen direction.
           
I'm still learning and refining my understanding of recursion and backtracking algorithms. This project was really helpful for me to understand the recursion-backtracking.

Future Improvements:
 * Visual Enhancements
 * Maze Solver

Thanks for reading!
