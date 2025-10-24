class Solution {
public:
//approach --> I’ll use two pointers — one for the original word and one for the abbreviation string — and traverse both together.

// Whenever I see a letter in the abbreviation, it should match the corresponding character in the word.

// But whenever I see a digit, it represents a number telling me how many characters in the word are being skipped.

// So, I’ll parse that number, make sure it doesn’t start with a zero (since leading zeros are invalid), convert it to an integer, and advance the word pointer by that number.

// At the end, both pointers should have reached the end of their respective strings for the abbreviation to be valid.

// This works in linear time O(n + m) because we only scan both strings once.
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0; // i for word, j for abbr
        int n = word.size(), m = abbr.size();

        while (i < n && j < m) {
            if (isalpha(abbr[j])) {
                // Must match the exact letter
                if (word[i] != abbr[j]) return false;
                i++;
                j++;
            } 
            else if (isdigit(abbr[j])) {
                // Leading zero check
                if (abbr[j] == '0') return false;

                int num = 0;
                while (j < m && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i += num; // skip num characters in the word
            } 
            else {
                // unexpected character (shouldn't happen)
                return false;
            }
        }
        // Both should end together
        return i == n && j == m;
    }
};