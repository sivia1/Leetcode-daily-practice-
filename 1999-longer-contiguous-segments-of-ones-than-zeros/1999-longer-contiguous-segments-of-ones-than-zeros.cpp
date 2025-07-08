class Solution {
public:
    bool checkZeroOnes(string s) {
        int cnt1 = 0, max1 = 0;
        int cnt2 = 0, max0 = 0;
        for(char c : s) {
            if(c == '1') {
                cnt1++; //count the number of current ones
                cnt2 = 0; //reset count of zeros to 0
                max1 = max(max1, cnt1);
            } else {
                cnt2++; //count the number of current 0s
                cnt1 = 0; //reset count of 1s to 0
                max0 = max(max0, cnt2); 
            }
        }
        return max1 > max0; //take the max of both
    }
};