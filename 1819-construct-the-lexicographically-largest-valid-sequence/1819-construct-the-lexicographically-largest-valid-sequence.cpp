class Solution {
public:
    bool backtrack(vector<int>& res, vector<bool>& used, int n, int index) {
        if (index == res.size()) return true;  // Successfully filled sequence

        if (res[index] != 0) return backtrack(res, used, n, index + 1); // Skip filled positions

        for (int i = n; i >= 1; --i) { // Start with the largest number
            if (!used[i]) { 
                if (i == 1) { // 1 only appears once
                    res[index] = 1;
                    used[1] = true;
                    if (backtrack(res, used, n, index + 1)) return true;
                    res[index] = 0;
                    used[1] = false;
                } else {
                    int nextPos = index + i;
                    if (nextPos < res.size() && res[nextPos] == 0) {
                        res[index] = res[nextPos] = i;
                        used[i] = true;

                        if (backtrack(res, used, n, index + 1)) return true;

                        res[index] = res[nextPos] = 0; // Backtrack
                        used[i] = false;
                    }
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);  // Create sequence of size (2n-1)
        vector<bool> used(n + 1, false); // Track used numbers

        backtrack(res, used, n, 0);
        return res;
    }
};