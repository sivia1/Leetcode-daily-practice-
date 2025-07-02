class Solution {
public:
//Don't think of DFS..but you do need to traverse to 8 directions 
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> nextBoard(m, vector<int>(n, 0));

        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {1, -1}, {0, -1}, {-1, 1}, {1, 0}, {0, 1}, {1, 1}};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int liveNeighbours = 0;


                for(auto& dir : directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;

                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 1) {                  
                        liveNeighbours++;

                    }
                }

                if(board[i][j] == 1) {
                    if(liveNeighbours < 2) {
                        nextBoard[i][j] = 0;

                    } else if (liveNeighbours == 2 || liveNeighbours == 3) {
                        nextBoard[i][j] = 1;
                    } else {
                        nextBoard[i][j] = 0;
                    }
                } else {
                    if(liveNeighbours == 3) {
                        nextBoard[i][j] = 1;
                    } else {
                        nextBoard[i][j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = nextBoard[i][j];
            }
        }
    }
};