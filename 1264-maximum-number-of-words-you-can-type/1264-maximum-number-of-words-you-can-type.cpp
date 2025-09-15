class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> brokenDict(brokenLetters.begin(), brokenLetters.end());
        //using istringstream to parse words
        istringstream iss(text);
        string word;
        int count = 0;
        

        while(iss >> word) {
            bool canType = true;
            //check if any letter in the word is broken
            for(char ch : word) {
                if(brokenDict.count(ch)) {
                    canType = false;
                    break;
                }
            }

            if(canType) {
                count++;
            }
        }
        return count;
    }
};