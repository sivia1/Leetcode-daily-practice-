class Solution {
public:
//problem : Need to construct a VALID sequence of unique digits num of length n + 1 from '1' to '9' based on I and D pattern 
//problem suggests a greedy approach because based on the properties:
//for sequence of 'I' place the smallest possible numbers first in increasing order and each number will be used AT MOST once
// for sequence of 'D' place the smallest largest possible numbers in decreasing order 

    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack<int> st;
        string result = "";

        for(int i = 0; i <= n; i++) {
            st.push(i+1);

            if(i == n || pattern[i] == 'I') {
                while(!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        return result;
    }
};