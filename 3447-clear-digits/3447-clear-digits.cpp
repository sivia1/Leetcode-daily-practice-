class Solution {
public:
//Understanding of the problem:
//Find the first digit from the left
//Remove that digit and remove the closest non digit character to its left
//Repeat until all digits are gone
//it is possible to delete all digits
//can use a stack to pop the non digit characters
    string clearDigits(string s) {
        stack<char>st;

        for(char ch : s) {
            if(isdigit(ch)) {
                if(!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(ch);
            }
        }

        string result;
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};