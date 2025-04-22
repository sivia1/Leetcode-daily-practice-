class Solution {
private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        int m = heights.size();
        int n = heights[0].size();
        visited[i][j] = true;
        for(auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            //boundary conditions check
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, visited, ni, nj);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> oceanA(m, vector<bool>(n, false));
        vector<vector<bool>> oceanB(m, vector<bool>(n, false));
        //from top and left
        for(int i = 0; i < m; i++) {
            dfs(heights, oceanA, i, 0);
            dfs(heights, oceanB, i, n-1);
        }

        //from bottom and right
        for(int j = 0; j < n; j++) {
            dfs(heights, oceanA, 0, j);
            dfs(heights, oceanB, m-1, j);
        }
        //count coordinates
        vector<vector<int>> result;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(oceanA[i][j] && oceanB[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};