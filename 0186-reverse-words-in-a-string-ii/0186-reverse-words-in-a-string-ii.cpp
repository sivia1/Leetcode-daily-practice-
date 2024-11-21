class Solution {
public:
//plan 
//enter the word inside a vector till you encounter a space, maybe also use a deque instead of a stack 
//output is in the form of a vector of characters 
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int start = 0;

        for(int end = 0; end < n; end++) {
            if(s[end] == ' ' || end == n-1) {
                reverse(s.begin() + start, s.begin() + (end == n - 1 ? end + 1 : end));
                start = end+1;
            }
        }
    }
};