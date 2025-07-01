class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //maintain prefix array P[0] = 1, and suffix array S[n-1] = 1 that stores the Prefix and Suffix products
        int n = nums.size();
        vector<int> P(n), S(n), res(n);
        P[0] = 1;

        for(int i = 1; i < n; i++) {
            P[i] = P[i-1] * nums[i-1];
        }
        S[n-1] = 1;
        for(int j = n-2; j >= 0; j--) {
            S[j] = S[j+1] * nums[j+1];
        }

        for(int i = 0; i < n; i++) {
            res[i] = P[i] * S[i];
        }
        return res;
    }
    //Dry Run first example 
   // P[] = [1, 1, 2, 6]
   //P[0] = 1 INITIALISED
   //P[1] = P[0] * nums[0] = 1 x 1 = 1
   //P[2] = P[1] * nums[1] = 1 x 2 = 2
   //p[3] = P[2] * nums[2] = 2 x 3 = 6
   //S[] = [24, 12, 4, 1] --> start from end 
   //S[3] = 1 INITIALISED
   //S[2] = S[3] * nums[3] = 1 x 4 = 4
   //S[1] = S[2] * nums[2] = 4 x 3 = 12 
   //S[0] = S[1] * nums[1] = 12 x 2 = 24

   // res[i] = P[i] x S[i] = [24, 12, 8, 6]
};