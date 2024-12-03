class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int prev = 0;

        for(int index : spaces) {
            result += s.substr(prev, index - prev) + " ";
            prev = index;
        }
        result += s.substr(prev);
        return result;
    }
};