class Solution {
public:

//Find out connected components in a 2d grid--> immediately think of graph traversal 
//everytime you visit an unvisited land--> it's a new island
//DFS with In-place modification (if allowed)
//Pros:

// Minimal space complexity O(1) extra space
// Clean and intuitive
// Modifies input destructively

// Cons:

// Destroys original data
// Not suitable if you need to preserve the grid

//TC --> O(mxn), SC --> Recursion stack in the worst case O(mxn)

//I'll iterate through the grid, and whenever I find an unvisited land cell, I'll increment my island counter and use DFS to mark that entire island as visited.

//I can solve this with DFS or BFS. DFS is more intuitive here since we just need to mark connected components. I can either modify the grid in-place or use a visited matrix - which would you prefer?

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int numOfIslands = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    numOfIslands++;
                }
            }
        }
        return numOfIslands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';

        dfs(grid, i-1, j, m, n);
        dfs(grid, i+1, j, m, n);
        dfs(grid, i, j-1, m, n);
        dfs(grid, i, j+1, m, n);
    }
};