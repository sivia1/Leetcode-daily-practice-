class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freqV;
        unordered_map<char, int> freqC;
        for(char c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                freqV[c]++;
            }
            else {
                freqC[c]++;
            }
        }
        int maxCV = 0;
        for(auto&[ch, cnt] : freqV) {
            maxCV = max(cnt, maxCV);
        }
        int maxCC = 0;
        for(auto&[ch, cnt] : freqC) {
            maxCC = max(cnt, maxCC);
        }
        return maxCV+maxCC;
    }
};