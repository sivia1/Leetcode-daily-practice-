class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int answer = INT_MIN, sum = 0; 
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
            sum += num;
        }
        for(int num : nums) {
            int outlier = sum - num - num;
            if(mp[outlier] > (outlier == num)) {
                answer = max(answer, outlier);
            }
            
        }
        return answer;
    }
};