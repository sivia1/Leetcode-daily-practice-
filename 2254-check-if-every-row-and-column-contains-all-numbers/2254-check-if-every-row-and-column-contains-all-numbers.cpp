class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        unordered_set<int> rows[n];
        unordered_set<int> cols[n];

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                int val = matrix[r][c];

                if(val < 1 || val > n) return false;

                if(rows[r].find(val) != rows[r].end()) return false;
                rows[r].insert(val);

                if(cols[c].find(val) != cols[c].end()) return false;
                cols[c].insert(val);
            }
        }
        for(int i = 0; i < n; i++) {
            if(rows[i].size() != n || cols[i].size() != n) return false;
        }
        return true;
    }
};