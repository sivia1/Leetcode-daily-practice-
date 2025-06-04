class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> freq;
        for(auto& ch : num) {
            int digit = ch - '0';
            freq[digit]++;
        }

        for(int i = 0; i < num.size(); i++) {
            int expected = num[i] - '0'; // expected frequency
            int actual = freq[i]; //actual frequency
            if(expected != actual) {
                return false;
            }
        }
        return true;
    }
};