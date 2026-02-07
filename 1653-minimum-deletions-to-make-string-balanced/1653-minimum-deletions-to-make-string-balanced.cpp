class Solution {
public:
// the definition of "balanced", all a's come before all b's 
    int minimumDeletions(string s) {
        int n = s.size();
        //compute a's from suffix
        //compute b's from left 
        //treat every i as the midpoint and calc the cost of split
        vector<int> countA(n+1, 0);

        for(int i = n-1; i >= 0; i--) {
            countA[i] = countA[i+1];
            if(s[i] == 'a') {
                countA[i] = countA[i+1] + 1;
            }
        }
        //count of A's data is stored

        int minDel = INT_MAX;
        int countB = 0;

        for(int i = 0; i <= n; i++) {
            //count cost of split here
            //everything before i should be all a's
            int cost = countB + countA[i];
            minDel = min(minDel, cost);
            //from position i should be all b's
            if(i < n && s[i] == 'b') {
                countB++;
            }
        }

        return minDel;
    }
};