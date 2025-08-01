class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;

        //Loop through every possible characters
        for(char targetChar = 'A'; targetChar <= 'Z'; targetChar++) {
            //try making the entire substring into A, B till Z
            //For each target character, we find the longest possible string

            int left = 0;
            int changesNeeded = 0;

            //left and right define our window boundaries
            //changesNeeded counts how many characters in the current Window are not target characters
            //Expand window
            for(int right = 0; right < s.size(); right++) {
                if(s[right] != targetChar) {
                    changesNeeded++;
                }

                //As we expand the window by moving right, we count the characters that need changing
                //Shrink the Window when needed

                while(changesNeeded > k) {
                    if(s[left] != targetChar) {
                        changesNeeded--;
                    }
                    left++;
                }
                //if we need more than k changes, we shrink from the left till its valid again
                int currLen = right - left + 1;
                maxLength = max(maxLength, currLen);

                //After each expansion we check if this is the longest valid window we have seen
            }
        }
        return maxLength;
    }
};