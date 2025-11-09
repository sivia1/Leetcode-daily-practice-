class Solution {
    //Brute force--> Parse through the input string and process each character one by one
    //Ignore the leading white space and keep moving the index till a non white space character is found
    //if it is a sign, process the sign
    //if it is a digit --> build the digit
    //clamp the string to fit into 32-bit signed integer format
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        while(i < n && s[i] == ' ') {
            i++;
        }

        int sign = 1;
        if(i < n && s[i] == '-') {
            sign = -1;
            i++;
        } else if(i < n && s[i] == '+') {
            i++;
        }

        //build the number
        long long result = 0;
        while(i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            i++;

            if(result * sign >= INT_MAX) return INT_MAX;
            if(result * sign <= INT_MIN) return INT_MIN;
        }
        return result * sign;
    }

//gnore leading whitespaces by advancing the index until a non-space character is found.
// Check for an optional sign ('+' or '-'), and record it.
// Process digit characters one by one and build the number.
// Stop parsing when a non-digit character is encountered.
// Clamp the result within the range [-231, 231 - 1] to stay within 32-bit signed integer limits.
};