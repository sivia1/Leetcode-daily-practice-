class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> candies(n, 1);
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1]+1;
            }
        }
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                if((candies[i+1]+1) > candies[i]) {
                    candies[i] = candies[i+1]+1;
                }
            }
        }
        int total = 0;
        for(int candy : candies) {
            total += candy;
        }
        return total;
    }
    //The one line you should remember
// Left pass: "If I'm bigger than my left neighbour, I need one more candy than them."
// Right pass: "If I'm bigger than my right neighbour, I may need more candies, but never reduce what the left pass already gave me."
//"When an element has constraints from both directions, satisfy one direction at a time."

// That's exactly what Candy does.

// Left constraint → Left-to-right pass
// Right constraint → Right-to-left pass
};