class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = i * 2 - n + 1;
        }
        return arr;
    }
};