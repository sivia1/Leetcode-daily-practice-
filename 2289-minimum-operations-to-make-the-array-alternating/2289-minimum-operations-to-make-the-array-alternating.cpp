class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> evenFreq, oddFreq;

        // Count frequencies
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                evenFreq[nums[i]]++;
            else
                oddFreq[nums[i]]++;
        }

        // Helper to get top 2 frequent elements
        auto getTop2 = [](unordered_map<int, int>& freq) {
            pair<int, int> first = {0, 0};  // {num, freq}
            pair<int, int> second = {0, 0};
            for (auto& [num, f] : freq) {
                if (f > first.second) {
                    second = first;
                    first = {num, f};
                } else if (f > second.second) {
                    second = {num, f};
                }
            }
            return vector<pair<int, int>>{first, second};
        };

        auto evenTop2 = getTop2(evenFreq);
        auto oddTop2 = getTop2(oddFreq);

        int evenCount = n / 2 + n % 2;
        int oddCount = n / 2;

        // If top values are different → great
        if (evenTop2[0].first != oddTop2[0].first) {
            return (evenCount - evenTop2[0].second) + (oddCount - oddTop2[0].second);
        } else {
            // Try combinations:
            int op1 = (evenCount - evenTop2[0].second) + (oddCount - oddTop2[1].second);
            int op2 = (evenCount - evenTop2[1].second) + (oddCount - oddTop2[0].second);
            return min(op1, op2);
        }
    }
};