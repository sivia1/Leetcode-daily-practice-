class Solution {
public:
//Loop through every index i in goal (from 0 to n-1).If goal[i] == s[0]:This is a candidate rotation.Start a nested loop to check if s[j] matches goal[(i + j) % n] for all j.If the nested loop completes without returning false, immediately return true from the main function.If the outer loop completes without finding a matching rotation, then return false. 
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(s.size() != goal.size()) return false;

        for(int i = 0; i < goal.size(); i++) {
            if(goal[i] != s[0]) {
                continue;
            }
            bool match = true;
            for(int j = 0; j < n; j++) {
                if(s[j] != goal[(i+j) % n]) {
                    match = false;
                    break; //mismatch stop checking for i
                }
            }

            if(match) {
                return true;
            }
        }
    return false;
    }
};