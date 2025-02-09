class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> freq;
        long long n = nums.size();
        long long goodPairs = 0;

        for(int i = 0; i < n; i++) {
            int key = i - nums[i];
            goodPairs += freq[key];
            freq[key]++;
        }

        long long totalPairs = (1LL * n * (n-1)) / 2;
        long long badPairs = totalPairs - goodPairs;

        return badPairs;
    }
};