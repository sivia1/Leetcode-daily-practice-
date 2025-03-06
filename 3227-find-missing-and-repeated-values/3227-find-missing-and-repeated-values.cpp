class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n*n;
        int repeated = -1, missing = -1;

        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }
        for(int i = 1; i <= N; i++) {
            if(freq[i] == 2) {
                repeated = i;
            }
            if(freq[i] == 0) {
                missing = i;
            }
        }
        return {repeated, missing};
    }
};