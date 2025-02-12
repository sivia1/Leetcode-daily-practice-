class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> digSumMap;
        int maxSum = -1;

        for(int num : nums) {
            int s = digitSum(num);
            digSumMap[s].push(num);
        }

        for(auto& [sum, pq] : digSumMap) {
            if(pq.size() > 1) {
                int max1 = pq.top();
                pq.pop();
                int max2 = pq.top();
                pq.pop();

                maxSum = max(maxSum, max1 + max2);
            }
        }
        return maxSum;
    }
};