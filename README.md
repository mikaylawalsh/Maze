```
  __  __               
 |  \/  |              
 | \  / | __ _ _______ 
 | |\/| |/ _` |_  / _ \
 | |  | | (_| |/ /  __/
 |_|  |_|\__,_/___\___|
```

Generator: The way my generator works is by first checking to make sure we have a valid number of rows and columns, otherwise main is exited. Next, I initalize my maze
to be of the proper size. After this, the maze goes through a drunken walk in order to 
form walls in the maze. It does this by randomly picking directions to find paths between rooms. In the end, there will be a path from any one room to any other room in the maze. After this, the maze is encoded into a binary form. Lastly, I write the encoded maze to a file. 

Solver: The first thing my solver does is check to make sure we have a valid number of rows and columns and the start and end are in range. Then, the encoded maze is read in from the file. Next, solver decodes the maze that has been past in converting the hex number to binary and then forming the walls in each direction of a room. After that, solver runs dfs in order to find a solution to the maze by walking through and checking neighbors until it finds the goal row and goal col. There are two options from here; either the pruned version or the full version will print out. If the full verison is printed, dfs will write each room it goes to into a new file. If the pruned version is printed, print_pruned_path will use the next field in maze_room to print out a path with no repeated rooms. 