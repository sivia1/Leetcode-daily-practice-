class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr[0], r = curr[1], c = curr[2];

            if(r == n-1 && c == n-1) {
                return time;
            } 
            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
            
                // Check boundaries and if already visited
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({max(time, grid[nr][nc]), nr, nc}); // max to ensure we take the least possible time
                }
            }
        }
        return -1; 
    }
};