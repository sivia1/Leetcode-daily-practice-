class Solution {
public:
//Idea : Iterate over each word from the words string and check if it starts with pref. 
//To do this, compare the pref.length let's say k characters of each word with pref. If they match I'll increment the counter and at the end return counter. 
    int prefixCount(vector<string>& words, string pref) {
        int k = pref.size();
        int count = 0;
        for(string& word : words) {
            if(word.substr(0, k) == pref) {
                count++;
            }
        }
        return count;
    }
};