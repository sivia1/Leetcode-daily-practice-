class Solution {
public:
//perform binary search on answer
//MAXIMIZE MINIMUM GAP"
//SORT + GREEDY CHECK
//MIN-MAX OPTIMIZATION --> CAN WE ACHIEVE X?
//SPREAD OUT SELECTION
//maximize the minimum"
// "k distinct elements"
// "smallest difference"
// "optimal selection"
    int maximumTastiness(vector<int>& price, int k) {

        sort(price.begin(), price.end());

        int n = price.size();
        int left = 0, right = price.back() - price[0];
        int result = 0;

        while(left <= right) {
            int mid = left + (right - left)/2;

            if(canAchieveTastiness(price, k, mid)) {
                result = mid;
                left = mid+1;
            } else {
                right = mid-1;

            }
        }
        return result;
    }

    bool canAchieveTastiness(vector<int>& price, int k, int minDiff) {
        // Check if we can select k candies with minimum difference >= minDiff
        // Uses greedy approach: pick candies as far apart as possible

        int count = 1;
        int lastPicked = price[0];

        for(int i = 1; i < price.size(); i++) {
            if(price[i] - lastPicked >= minDiff) {
                count++;
                lastPicked = price[i];
                if(count == k) {
                    return true;
                }
            }
        }
        return count >= k;
    }
};