#if 0
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define GMAX  4

enum ITERATION_PATTERN {
    COL_INCR = 0,  // row++, but implies row doesn't change
    ROW_INCR,      // col++, but implies col doesn't change
    COL_DECR,
    ROW_DECR
};

struct index_pair {
    int row;
    int col;
    int temp;
    unsigned int iteration;
};

void print_grid(int grid[GMAX][GMAX]) {
    for (int i = 0; i < GMAX; i++) {
        for (int j = 0; j < GMAX; j++)
            printf("%d\t", grid[i][j]);
        puts("\n");
    }
    puts("-----------------------------------\n");
}

void increment_index_pair(struct index_pair* pr, int grid[GMAX][GMAX]) {
    assert(pr);
    if (pr->iteration == COL_INCR) {
        if (pr->col < GMAX - 1)
            pr->col++;
    }
    else if (pr->iteration == ROW_INCR) {
        if (pr->row < GMAX - 1)
            pr->row++;
    }
    else if (pr->iteration == COL_DECR) {
        if (pr->col > 0)
            pr->col--;
    }
    else if (pr->iteration == ROW_DECR) {
        if (pr->row > 0)
            pr->row--;
    }
    else {
        assert(false);
    }

    if (pr->row < GMAX && pr->col < GMAX)
        pr->temp = grid[pr->row][pr->col];
}

void reset_index_pair_for_next_ring(struct index_pair* pr, int grid[GMAX][GMAX], int layer) {
    assert(pr);
    if (pr->iteration == COL_INCR) {
        pr->row = layer;
        pr->col = layer;
    }
    else if (pr->iteration == ROW_INCR) {
        pr->row = layer;
        pr->col = GMAX - 1 - layer;
    }
    else if (pr->iteration == COL_DECR) {
        pr->row = GMAX - 1 - layer;
        pr->col = GMAX - 1 - layer;
    }
    else if (pr->iteration == ROW_DECR) {
        pr->row = GMAX - 1 - layer;
        pr->col = layer;
    }

    // Reset the temp variable
    if (pr->row < GMAX && pr->col < GMAX && pr->row >= 0 && pr->col >= 0)
        pr->temp = grid[pr->row][pr->col];
}

void swap_elements(int grid[GMAX][GMAX], struct index_pair* pip1, struct index_pair* pip2) {
    assert(pip1 && pip2);
    if (pip1->row < GMAX && pip1->row >= 0 && pip1->col < GMAX && pip1->col >= 0 &&
        pip2->row < GMAX && pip2->row >= 0 && pip2->col < GMAX && pip2->col >= 0) {
        grid[pip1->row][pip1->col] = pip2->temp;
    }
}

void rotate_grid(int grid[GMAX][GMAX], struct index_pair* pul, struct index_pair* pur, struct index_pair* plr, struct index_pair* pll, int layer) {
    for (int i = 0; i < GMAX - 1 - 2 * layer; i++) {
        swap_elements(grid, pur, pul);
        swap_elements(grid, plr, pur);
        swap_elements(grid, pll, plr);
        swap_elements(grid, pul, pll);

        increment_index_pair(pul, grid);
        increment_index_pair(pur, grid);
        increment_index_pair(plr, grid);
        increment_index_pair(pll, grid);
    }
}

void test4() {
    int grid[GMAX][GMAX] = { { 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 }, { 12, 13, 14, 15 } };

    int layers = GMAX / 2;
    for (int layer = 0; layer < layers; layer++) {
        struct index_pair ul = { .row = layer, .col = layer, .temp = grid[layer][layer], .iteration = COL_INCR };
        struct index_pair ur = { .row = layer, .col = GMAX - 1 - layer, .temp = grid[layer][GMAX - 1 - layer], .iteration = ROW_INCR };
        struct index_pair lr = { .row = GMAX - 1 - layer, .col = GMAX - 1 - layer, .temp = grid[GMAX - 1 - layer][GMAX - 1 - layer], .iteration = COL_DECR };
        struct index_pair ll = { .row = GMAX - 1 - layer, .col = layer, .temp = grid[GMAX - 1 - layer][layer], .iteration = ROW_DECR };

        rotate_grid(grid, &ul, &ur, &lr, &ll, layer);
        print_grid(grid);
    }
}

int main() {
    test4();
    return 0;
}
#endif
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define GMAX  5

enum ITERATION_PATTERN {
    COL_INCR = 0,  // row++, but implies row doesn't change
    ROW_INCR,      // col++, but implies col doesn't change
    COL_DECR,
    ROW_DECR
};

struct index_pair {
    int row;
    int col;
    int temp;
    unsigned int iteration;
};

void print_grid(int grid[GMAX][GMAX]) {
    for (int i = 0; i < GMAX; i++) {
        for (int j = 0; j < GMAX; j++)
            printf("%d\t", grid[i][j]);
        puts("\n");
    }
    puts("-----------------------------------\n");
}

void increment_index_pair(struct index_pair* pr, int grid[GMAX][GMAX]) {
    assert(pr);
    if (pr->iteration == COL_INCR) {
        if (pr->col < GMAX - 1)
            pr->col++;
    }
    else if (pr->iteration == ROW_INCR) {
        if (pr->row < GMAX - 1)
            pr->row++;
    }
    else if (pr->iteration == COL_DECR) {
        if (pr->col > 0)
            pr->col--;
    }
    else if (pr->iteration == ROW_DECR) {
        if (pr->row > 0)
            pr->row--;
    }
    else {
        assert(false);
    }

    if (pr->row < GMAX && pr->col < GMAX)
        pr->temp = grid[pr->row][pr->col];
}

void reset_index_pair_for_next_ring(struct index_pair* pr, int grid[GMAX][GMAX], int layer) {
    assert(pr);
    if (pr->iteration == COL_INCR) {
        pr->row = layer;
        pr->col = layer;
    }
    else if (pr->iteration == ROW_INCR) {
        pr->row = layer;
        pr->col = GMAX - 1 - layer;
    }
    else if (pr->iteration == COL_DECR) {
        pr->row = GMAX - 1 - layer;
        pr->col = GMAX - 1 - layer;
    }
    else if (pr->iteration == ROW_DECR) {
        pr->row = GMAX - 1 - layer;
        pr->col = layer;
    }

    // Reset the temp variable
    if (pr->row < GMAX && pr->col < GMAX && pr->row >= 0 && pr->col >= 0)
        pr->temp = grid[pr->row][pr->col];
}

void swap_elements(int grid[GMAX][GMAX], struct index_pair* pip1, struct index_pair* pip2) {
    assert(pip1 && pip2);
    if (pip1->row < GMAX && pip1->row >= 0 && pip1->col < GMAX && pip1->col >= 0 &&
        pip2->row < GMAX && pip2->row >= 0 && pip2->col < GMAX && pip2->col >= 0) {
        grid[pip1->row][pip1->col] = pip2->temp;
    }
}

void rotate_grid(int grid[GMAX][GMAX], struct index_pair* pul, struct index_pair* pur, struct index_pair* plr, struct index_pair* pll, int layer) {
    for (int i = 0; i < GMAX - 1 - 2 * layer; i++) {
        swap_elements(grid, pur, pul);
        swap_elements(grid, plr, pur);
        swap_elements(grid, pll, plr);
        swap_elements(grid, pul, pll);

        increment_index_pair(pul, grid);
        increment_index_pair(pur, grid);
        increment_index_pair(plr, grid);
        increment_index_pair(pll, grid);
    }
}

void test4() {
    int grid[GMAX][GMAX] = {
        { 0, 1, 2, 3, 4 },
        { 5, 6, 7, 8, 9 },
        { 10, 11, 12, 13, 14 },
        { 15, 16, 17, 18, 19 },
        { 20, 21, 22, 23, 24 }
    };

    int layers = GMAX / 2;
    for (int layer = 0; layer < layers; layer++) {
        struct index_pair ul = { .row = layer, .col = layer, .temp = grid[layer][layer], .iteration = COL_INCR };
        struct index_pair ur = { .row = layer, .col = GMAX - 1 - layer, .temp = grid[layer][GMAX - 1 - layer], .iteration = ROW_INCR };
        struct index_pair lr = { .row = GMAX - 1 - layer, .col = GMAX - 1 - layer, .temp = grid[GMAX - 1 - layer][GMAX - 1 - layer], .iteration = COL_DECR };
        struct index_pair ll = { .row = GMAX - 1 - layer, .col = layer, .temp = grid[GMAX - 1 - layer][layer], .iteration = ROW_DECR };

        rotate_grid(grid, &ul, &ur, &lr, &ll, layer);
        print_grid(grid);
    }
}
void rotate(int matrix[GMAX][GMAX], int n) {
    for (int layer = 0; layer < n / 2; ++layer) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            int top = matrix[first][i]; // save top
            // left -> top
            matrix[first][i] = matrix[last - offset][first];
            // bottom -> left
            matrix[last - offset][first] = matrix[last][last - offset];
            // right -> bottom
            matrix[last][last - offset] = matrix[i][last];
            // top -> right
            matrix[i][last] = top; // right <- saved top
        }
    }
}
void my_rotate()
{
/*
1.) So I'm continuing with thinking about traversing the outer ring first, then moving toward the center.  Let's use a grid[4][4] as an example.  I was asking about 5 /2 because I think the number of "rings" in a grid is (number of cols or rows) / 2.  So for grid[4][4] or grid[5][5], the answer is 2, odd number size grids have a center element that can stay put.  

2.) Then I want to establist "column min" and "column max".  To start, col_min =0, col_max = 4 (the "size" variable passes as a argument that indicates how many rows-cols the grid has).  Same thing with row_min and row_max.   Int temp saves the copy destination priory to copy. So the very first copy will be:

temp = grid[row_min][col_max];  // temp = [0][3]
grid[row_min][col_max] = grid[row_min][col_min];  // grid[0][0] = grid[0][3];

//Then 3 more save temp and copy operation
temp = grid[row_max][col_max];
grid[row_max][col_max] = grid[row_max][col_min];

temp = grid[row_max][col_min];
grid[row_max][col_min] = grid[row_max][col_max];

/finally
temp = grid[row_min][col_min];
grid[row_min][col_min] = grid[row_max][col_min];

// that completes the outer ring, now reset the min and max
row_max--;
row_min++;
col_max--;
col_min++;

//Repeat until the we exhaust the rings
}
So I think the loop conditions might look like this for any sized grid, even or odd numbered.

void rotate(int *grid[], const int size)
{
	int min_row=0, max_row=size-1,min_col = 0, max_col = size-1;

	for(int rings = 0; rings < (size / 2); rings++) {
		for(int iter =0; iter < size; iter++) {
			// do the size number of set temps, and copies
		{
		row_max--;
		row_min++;
		col_max--;
		col_min++;
	}
}


*/
}
void test_traditional()
{
    int grid[GMAX][GMAX] = {
        { 0, 1, 2, 3, 4 },
        { 5, 6, 7, 8, 9 },
        { 10, 11, 12, 13, 14 },
        { 15, 16, 17, 18, 19 },
        { 20, 21, 22, 23, 24 }
    };
    rotate(grid, GMAX);
}
int main() {
    test4();
    test_traditional();
    return 0;
}
