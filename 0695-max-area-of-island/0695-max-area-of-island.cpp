class Solution {
public:
    //use dfs to calc the size of each valid island across 4 directions and then calc the maxIsland so far for every other island
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxIsland = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int island= dfs(grid, i, j, m, n, visited); //checkk
                    maxIsland = max(island, maxIsland); //check
                }
            }
        }
        return maxIsland;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n ,vector<vector<bool>>& visited) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j] == true) {
            return 0;
        }
        visited[i][j] = true;
        int island = 1; //check
        island += dfs(grid, i-1, j, m, n, visited);
        island += dfs(grid, i+1, j, m, n, visited);
        island += dfs(grid, i, j-1, m, n, visited);
        island += dfs(grid, i, j+1, m, n, visited);

        return island; //return the size of the island
    }
};