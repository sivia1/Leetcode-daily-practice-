class Solution {
private:
    string toLower(const string& s) {
        string result = s;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
    //generate vowel pattern
    string getVowelPattern(const string& s) {
        string pattern = s;
        for (char& c : pattern) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                c = '*';
            }
        }
        return toLower(pattern);
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactMatch;
        unordered_map<string, string> caseInsensitiveMatch;
        unordered_map<string, string> vowelMatch;

        for(const string& word : wordlist) {
            exactMatch.insert(word);
            
            // 2. Store for case-insensitive matching (first occurrence wins)
            string lowerWord = toLower(word);
            if (caseInsensitiveMatch.find(lowerWord) == caseInsensitiveMatch.end()) {
                caseInsensitiveMatch[lowerWord] = word;
            }
            
            // 3. Store for vowel pattern matching (first occurrence wins)
            string pattern = getVowelPattern(word);
            if (vowelMatch.find(pattern) == vowelMatch.end()) {
                vowelMatch[pattern] = word;
            }
        }
        
        vector<string> result;
        
        for (const string& query : queries) {
            // Check precedence: exact > case-insensitive > vowel pattern
            
            // 1. Exact match (case-sensitive)
            if (exactMatch.count(query)) {
                result.push_back(query);
                continue;
            }
            
            // 2. Case-insensitive match
            string lowerQuery = toLower(query);
            if (caseInsensitiveMatch.count(lowerQuery)) {
                result.push_back(caseInsensitiveMatch[lowerQuery]);
                continue;
            }
            
            // 3. Vowel pattern match
            string queryPattern = getVowelPattern(query);
            if (vowelMatch.count(queryPattern)) {
                result.push_back(vowelMatch[queryPattern]);
                continue;
            }
            
            // 4. No match found
            result.push_back("");
        }
        
        return result;
    }
};