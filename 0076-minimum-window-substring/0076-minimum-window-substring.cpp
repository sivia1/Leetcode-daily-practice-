class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() == 0 || s.size() == 0) return "";
        //to know the target string
        unordered_map<char, int> tcount;
        for(int i = 0; i < t.size(); i++) {
            tcount[t[i]]++;
        }
        // for two pointers
        int left = 0, right = 0;
        int valid = 0;

        unordered_map<char, int> window;
        int start = 0, len = INT_MAX;

        //sliding the window to build the window
        while(right < s.size()) {
            char r = s[right];
            right++;

            if(tcount.count(r)) {
                window[r]++;
                if(window[r] == tcount[r]) {
                    valid++;
                }
            }
            

            while(valid == tcount.size()) { //window contains all required chars
                //update minimum window if current is smaller
                if(right - left < len) {
                    start = left;
                    len = right - left;
                }
                //remove character at left pointer
                char l = s[left];
                left++;
                //update window counts
                if(tcount.count(l)) {
                    if(window[l] == tcount[l]) {
                        valid--; //can remove this character
                    }
                    window[l]--;
                }
            }

        }
        //return result
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};