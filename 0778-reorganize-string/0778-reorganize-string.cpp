class Solution {
public:
//idea : organize the charcs into 2 groups : even and odd indices
//Fill all the even indices first then fill the odd , this way we ensure no adjacent characs are same within the groups
//count the frequency of each character in string s using a hashmap
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        //Step 2: Find the character with the maximum frequency
        char maxChar = ' ';
        int maxCount = 0;
        for (auto &[ch, count] : freq) {
            if (count > maxCount) {
                maxCount = count;
                maxChar = ch;
            }
        }

        // Step 3: Check if it's possible to rearrange the string
        if (maxCount > (s.length() + 1) / 2) {
            return ""; // Not possible to rearrange
        }

        // Step 4: Create a result string and place the most frequent character first
        string result(s.length(), ' ');
        int index = 0;

        // Place the most frequent character at even indices
        while (freq[maxChar] > 0) {
            result[index] = maxChar;
            index += 2;
            freq[maxChar]--;
        }

        // Step 5: Place the remaining characters
        for (auto &[ch, count] : freq) {
            while (count > 0) {
                // If we reach the end of even indices, switch to odd indices
                if (index >= s.length()) {
                    index = 1;
                }
                result[index] = ch;
                index += 2;
                count--;
            }
        }

        return result;
    }
};