class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int n = s.length();
        // 1. Initialize and populate the boolean array (shouldBold)
        // True means the character at that index must be bolded.
        // The size is n, initialized to false.
        std::vector<bool> shouldBold(n, false);

        // Find all occurrences of all words in s
        for (const std::string& word : words) {
            int wordLen = word.length();
        
            // Check every possible start index in s
            for (int i = 0; i <= n - wordLen; ++i) {
                // Check if the substring of s matches the current word
                // s.substr(i, wordLen) extracts the substring starting at i of length wordLen
                if (s.substr(i, wordLen) == word) {
                    // Mark all indices covered by this match as true
                    for (int j = 0; j < wordLen; ++j) {
                        shouldBold[i + j] = true;
                    }
                }
            }
        }

        // 2. Construct the result string by inserting tags
        string result = "";
        for (int i = 0; i < n; ++i) {
        
            // A. Check for the START of a bold segment (insert <b>)
            // Condition: Current char must be bolded AND (it's the first char 
            // OR the previous char was NOT bolded).
            // This handles merging consecutive segments.
            if (shouldBold[i] && (i == 0 || !shouldBold[i - 1])) {
                result += "<b>";
            }
        
            // B. Append the current character
            result += s[i];

            // C. Check for the END of a bold segment (insert </b>)
            // Condition: Current char must be bolded AND (it's the last char 
            // OR the next char is NOT bolded).
            // This also handles merging consecutive segments.
            if (shouldBold[i] && (i == n - 1 || !shouldBold[i + 1])) {
                result += "</b>";
            }
        }
        return result;
    }
};