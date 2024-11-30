class Solution {
public:
    int row, col;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        row = mat.size();
        col = mat[0].size();

        vector<vector<int>> distMatrix(row, vector<int>(col, 0));
        vector<vector<bool>> seen(row, vector<bool>(col, false));

        queue<vector<int>> queue;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                distMatrix[i][j] = mat[i][j];
                if(distMatrix[i][j] == 0) {
                    queue.push({i, j, 0});
                    seen[i][j] = true;
                }
            }
        }

        while(!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int rows = curr[0], cols = curr[1], steps = curr[2];

            for( auto& direction : directions) {
                int nextRow = rows + direction[0], nextCol = cols + direction[1];
                if(valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, steps + 1});
                    distMatrix[nextRow][nextCol] = steps + 1;
                }
            }
        }
        return distMatrix;
    }
    bool valid(int rows, int cols) {
        return 0 <= rows && rows < row && 0 <= cols && cols < col;
    }
};