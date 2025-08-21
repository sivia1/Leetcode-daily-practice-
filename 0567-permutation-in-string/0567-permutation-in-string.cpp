class Solution {
public:
//approach --> don't generate strings... permutation is different ordering of the character but count is gonna be the same... so I can utilise the window size of string 1 and scan through the string 2 to keep count of characters and whenever the s1count == s2count , I'll return true because it is a valid permuation in the string
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false; //edge case

        //counting arrays
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        //knowing your target search
        for(auto charac : s1) {
            s1Count[charac - 'a']++;
        }

        //setting up the window size and initialising the window

        for(int i = 0; i < s1.size(); i++) {
            s2Count[s2[i] - 'a']++;
        }

        int windowSize = s1.size();
        //don't miss checking out on the last so go i <= s2.size() not i < s2.size()
        for(int i = windowSize; i <= s2.size(); i++) {
            //check current window
            if(s1Count == s2Count) return true;
            //slide the window
            if(i < s2.size()) {
                s2Count[s2[i] - 'a']++; // add new character
                s2Count[s2[i - windowSize] - 'a']--; // removing the old character
            }
        }
        return false;
    }
};