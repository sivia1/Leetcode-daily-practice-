class Solution {
public:
//approach --> "I'll parse through the string, check for parentheses, maybe use a stack, or just count open '('."
//You’ll traverse from left to right.

// Keep a counter open = 0.

// For each character:

// If it’s a letter, always keep it.

// If it’s '(', increment open and keep it.

// If it’s ')':

// If open > 0, that means there’s a matching '(', so you can keep this ')' and decrement open.

// Else (open == 0), it means there’s no matching '(' → skip this ')'.
    string minRemoveToMakeValid(string s) {
        string noExtraClosing = invalidClosing(s);
        string valid = invalidOpening(noExtraClosing);
        return valid;
    }

    string invalidClosing(const string& s) {
        int n = s.size();
        int open = 0;
        string result;
        for(int i = 0; i < n; i++) {
            if(isalpha(s[i])) {
                result.push_back(s[i]); //always keep letters
            }
            else if(s[i] == '(') {
                open++;
                result.push_back(s[i]); //keep it and count it
            } else if(s[i] == ')') {
                if(open > 0) {
                    open--;
                    result.push_back(s[i]);
                }
            }
        }
        return result;
    }

    string invalidOpening(const string& s) {
        int n = s.size();
        string result;
        int close = 0;

        for(int i = n-1; i >= 0; i--) {
            if(isalpha(s[i])) {
                result.push_back(s[i]);
            }
            else if(s[i] == ')') {
                close++;
                result.push_back(s[i]);
            } else if (s[i] == '(') {
                if(close > 0) {
                    close--;
                    result.push_back(s[i]);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

    //The first pass skips unmatched ')' by not appending them.

// The second pass skips unmatched '(' in reverse order.

// The final valid string has all parentheses balanced.
};