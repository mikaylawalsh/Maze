#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

/*
 * Determines whether or not the room at [row][col] is a valid room within the
 *maze with dimensions num_rows x num_cols
 *
 * Parameters:
 *  - row: row of the current room
 *  - col: column of the current room
 *  - num_rows: number of rows in the maze
 *  - num_cols: number of columns in the maze
 *
 * Returns:
 *  - 0 if room is not in the maze, 1 if room is in the maze
 */
int is_in_range(int row, int col, int num_rows, int num_cols) {
    if (row < num_rows && col < num_cols && row >= 0 && col >= 0) {
        return 1;
        } else {
            return 0;
            } 
} 

/*
 * Given a pointer to the room and a Direction to travel in, return a pointer to
 *the room that neighbors the current room on the given Direction. For example:
 *get_neighbor(&maze[3][4], EAST) should return &maze[3][5]
 *
 * Parameters:
 *  - num_rows: number of rows in the maze
 *  - num_cols: number of columns in the maze
 *  - room: pointer to the current room
 *  - dir: Direction to get the neighbor from
 *  - maze: a 2D array of maze_room structs representing your maze
 * Returns:
 *  - pointer to the neighboring room
 */
struct maze_room *get_neighbor(int num_rows, int num_cols,
                               struct maze_room maze[num_rows][num_cols],
                               struct maze_room *room, Direction dir) {
    if (is_in_range(room->row, room->col, num_rows, num_cols) != 0) {
        if (dir == 0) {
            if (room->row != 0) {
                room = &maze[room->row - 1][room->col]; //try arrow notation if this fails
            }
        } else if (dir == 1) {
            if (room->row != num_rows - 1) {
                room = &maze[room->row + 1][room->col];
            }
        } else if (dir == 4) {
            if (room->col != num_cols - 1) {
                room = &maze[room->row][room->col + 1];
            }
        } else if (dir == 3) {
            if (room->col != 0) {
                room = &maze[room->row][room->col - 1];
            }
        }
    } else {
        return NULL; 
        }
    return room; 
    }

/*
 * Initializes a 2D array of maze rooms with all of the necessary values
 *
 * Parameters:
 *  - num_rows: the number of the rows in the maze
 *  - num_cols: the number of columns in the maze
 *  - maze: a 2D array of uninitialized maze_rooms (to be initialized in
 *     this function)
 *
 * Returns:
 *  - nothing (the initialized maze will be stored in the 'maze' array)
 */
void initialize_maze(int num_rows, int num_cols,
           struct maze_room maze[num_rows][num_cols]) {
    int i;
    int j;
    for (i = 0; i<sizeof maze; i++) {
        for (j = 0; j<sizeof maze; j++){
            maze[i][j].row = i; 
            maze[i][j].col = j;
            maze[i][j].visited = 0;
            for (i=0; i<4;i++) {
                maze[i][j].dirs[i] = 1000;
            }
        }
    }
}

