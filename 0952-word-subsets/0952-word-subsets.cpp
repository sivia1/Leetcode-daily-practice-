class Solution {
public:
//A string a in words1 is universal if every string in words2 is a subset of a.

//Find all strings in word1 that are universal with respect to all strings in words 2

//You must check if each string in words1 satisfies the subset condition for all strings in words2. This could be computationally expensive if done naively.

//The key is to efficiently check whether a string in words1 satisfies all strings in words2. Instead of comparing each string in words2 with each string in words1 (which is slow), we can precompute the maximum frequency requirement for each character in words2.

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        //precompute the maximum frequency requirements from words2
        vector<int> maxFreq(26, 0);
        for(const string& word : words2) {
            vector<int> freq(26, 0);
            for(char c : word) {
                freq[c - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        vector<string> result;
        for(const string& word : words1) {
            vector<int> freq(26, 0);
            for(char c : word) {
                freq[c - 'a']++;
            }
            bool isUniversal = true;
            for(int i = 0; i < 26; i++) {
                if(freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal) {
                result.push_back(word);
            }
        }
        return result;

    }
};