class Solution {
public:
//both plays optimally
//until and unless there is 0 vowel in the string, alice is ALWAYS guranteed to win 
//if odd number of vowels, then alice can always remove the entire substring containing odd no. of vowels
//if s has even number of vowels, alice removes the odd number of vowels, bob is left to remove only even no. of vowels either 0 or mpre leaving alice with an odd n0. of vowels,
//So in both these cases, alice will win 
    bool doesAliceWin(string s) {
        int totalVowels = 0;
        for(char c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                totalVowels++;
            }
        }
        if(totalVowels == 0) {
            return false;
        }
        return true;
    }
};