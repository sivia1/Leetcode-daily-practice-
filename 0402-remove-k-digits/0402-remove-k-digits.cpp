class Solution {
public:
//can't change the order of digits and no leading zeroes
//brute force --> TRY all possible combinations and find the min number among them
//exponential TC

//OPTIMAL THINKING-->
//To form the smallest number --> we want left digits to be smaller than the digits on their right
//While traversing, remove digits that are larger than the current digit, because keeping a smaller digit earlier will make the number smaller.
    string removeKdigits(string num, int k) {
        string result = "";

        //remove larger digits from the end of result
        for(char digit : num) {
            while(!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        //if k > 0, then remove from the end
        while(k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        //remove leading zeros
        int start = 0;
        while(start < result.size() && result[start] == '0') {
            start++;
        }
        result = result.substr(start);

        //if empty string return "0"
        return result.empty() ? "0" : result;
    }
};