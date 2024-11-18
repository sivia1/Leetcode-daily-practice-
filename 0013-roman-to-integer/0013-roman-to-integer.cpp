class Solution {
public:
    int romanToInt(string s) {
        map<char, int> values{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        int i = 0;

        while(i < s.size()) {
            char currSymbol = s[i];
            int currValue = values[currSymbol];
            int nextValue = 0;
            //if a next value exists

            if(i + 1 < s.size()) {
                char nextSymbol = s[i+1];
                nextValue = values[nextSymbol];
            }
            if(currValue < nextValue) {
                sum += (nextValue - currValue);
                i += 2;
            }
            //else this is NOT the subtractive case

            else {
                sum += currValue;
                i += 1;
            }
        }
        return sum;
    }
};