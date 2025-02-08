class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            if(s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        int n = s.size();

        //Generate all partitions using bit masking
        for(int mask = 0; mask < (1 << (n-1)); mask++) {
            vector<string> currPartitioning;
            string temp = "";
            bool valid = true;

            for(int i = 0; i < n; i++) {
                temp += s[i];

                if((mask >> i) & 1 || i == n-1) {
                    if(isPalindrome(temp)) {
                        currPartitioning.push_back(temp);
                        temp = "";
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid) {
                result.push_back(currPartitioning);
            }
        }
        return result;
    }
};