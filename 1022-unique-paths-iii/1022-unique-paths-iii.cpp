class Solution {
public:
    int rows, cols;
    vector<vector<int>> grid;
    int path_count;

    void backtrack(int row, int col, int remain) {
        // base case: if destination is reached and all non-obstacle squares are visited
        if (grid[row][col] == 2 && remain == 1) {
            path_count += 1;
            return;
        }

        // mark the current cell as visited
        int temp = grid[row][col];
        grid[row][col] = -4;  // mark as visited
        remain -= 1;  // we visited one square

        // explore 4 possible directions (right, left, down, up)
        int row_offset[4] = {0, 0, 1, -1};
        int col_offset[4] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int next_row = row + row_offset[i];
            int next_col = col + col_offset[i];

            // Check boundaries and avoid revisiting obstacles or visited cells
            if (next_row < 0 || next_row >= rows || next_col < 0 || next_col >= cols || grid[next_row][next_col] < 0) {
                continue;
            }

            // Recursive call for the next cell
            backtrack(next_row, next_col, remain);
        }

        // unmark the current cell after visiting
        grid[row][col] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int non_obstacles = 0, start_row = 0, start_col = 0;

        rows = grid.size();
        cols = grid[0].size();

        // Initialize grid and find start position
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int cell = grid[row][col];
                if (cell >= 0) {
                    non_obstacles += 1;
                }
                if (cell == 1) {  // Start position
                    start_row = row;
                    start_col = col;
                }
            }
        }

        // Initialize path_count to 0
        path_count = 0;
        this->grid = grid;

        // Start backtracking from the start position
        backtrack(start_row, start_col, non_obstacles);

        return path_count;
    }
};