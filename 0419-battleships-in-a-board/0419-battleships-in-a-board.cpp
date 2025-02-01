class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        //vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X') { // && visited[i][j] == 0
                    dfs(board, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.') {
            return;
        }

        board[i][j] = '.';

        dfs(board, i+1, j, m, n);
        dfs(board, i-1, j, m, n);
        dfs(board, i, j+1, m, n);
        dfs(board, i, j-1, m, n);
    }
};