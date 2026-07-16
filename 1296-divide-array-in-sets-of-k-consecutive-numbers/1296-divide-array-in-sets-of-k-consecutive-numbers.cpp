class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0)
            return false;

        map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        while (!freq.empty()) {
            int start = freq.begin()->first;
            int cnt = freq.begin()->second;

            for (int i = 0; i < k; i++) {
                int num = start + i;

                if (freq[num] < cnt)
                    return false;

                freq[num] -= cnt;

                if (freq[num] == 0)
                    freq.erase(num);
            }
        }

        return true;
    }
};