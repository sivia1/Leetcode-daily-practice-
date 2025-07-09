class Solution {
public:
//to check the validity if two strings are anangrams or not.. 
// 1) We need to see if their sizes are equal or not
// 2) We need to count the freq of each letter of string s and simultaneously decrement the freq of each letter of t from the same hashmap where we store the freq of each letter
//then we traverse through the hashmap and see if for every letter the freq = 0 if it is then return true other false; 
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<int, int> freq;
        for(int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for(auto it : freq) {
            if(it.second != 0) {
                return false;
            }
        }
        return true;
    }
};