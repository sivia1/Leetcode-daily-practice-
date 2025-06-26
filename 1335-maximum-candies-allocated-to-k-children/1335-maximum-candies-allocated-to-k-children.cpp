class Solution {
public:
//problem statement--> given k candies per child, how many children can we satisfy from each pile
//How many children can get mid candies
//Maximize children served
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
            //how many piles of size mid can be created?
            for(int candy : candies) {
                pilesCount += candy / mid; //need floor not ceil
            }
            if(pilesCount >= k) {
                //can create k piles of size mid
                result = mid; //valid answer
                left = mid+1; //try for a larger size
            } else {
                //can't create k piles of size mid
                right = mid-1; // try lesser size
            }
        } 
        return result;
    }
};