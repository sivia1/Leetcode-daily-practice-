class Solution {
public:
    int countVowelSubstrings(string word) {
       int res = 0;
        for(int i=0; i<word.size(); i++){
            unordered_set<char> set;
            for(int j=i; j<word.size(); j++){
                if(!isVowel(word[j])) break;
                set.insert(word[j]);
                if(set.size() == 5) res++;
            }
        }
        return res;
    } 
	
	bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); 
    }
};