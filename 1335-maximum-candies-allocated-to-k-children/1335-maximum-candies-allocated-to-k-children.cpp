class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int size = candies.size();
        long long totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }
        if (totalCandies < k) return 0;
        
        int left = 1, right = *max_element(candies.begin(), candies.end());
        int result = 0;

        while(left <= right) {
            long long pilesCount = 0;
            long long mid = left + (right - left) / 2;
            for(int candy : candies) {
                pilesCount += candy / mid;
            }
            if(pilesCount >= k) {
                result = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        } 
        return result;
    }
};