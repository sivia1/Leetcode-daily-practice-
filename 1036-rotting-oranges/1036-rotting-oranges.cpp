class Solution {
public:
//it is suggesting me that rotting is spreading level by level, like if the first orange is rotten then it will affect in 4- directions, in terms of width than going deeper.
//all fresh oranges adjacent to rotten ones rot at the same time

//Think of each level in BFS as 1 minute.
// Start by pushing all rotten oranges' positions into a queue.
// For every orange in the queue (initially rotten ones), check 4 directions.
// If a neighboring cell has a fresh orange, rot it (i.e., change 1 to 2) and add it to the queue.
// Repeat this process and count minutes as BFS levels.
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0; 
        int minutes = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        while(!q.empty() && freshCount > 0) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(auto [dx, dy] : directions) {
                    int nx = x+dx;
                    int ny = y+dy;

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        freshCount--;
                        q.push({nx, ny});
                    }
                }
            }
            minutes++;
        }
        return (freshCount == 0) ? minutes : -1;
    }
};