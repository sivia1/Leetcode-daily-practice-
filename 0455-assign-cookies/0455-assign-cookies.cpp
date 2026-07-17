class Solution {
public:
//if cookie size is > student's greed size, then only we can satisfy the child. 
//we have to maximise the number of children we can satisfy with cookies so we are going to sort the cookies and the greed, so that we can efficiently assign the cookies to the greed factors
//How can we efficiently assign the cookies to children.. the cookie size has to be >= greed[i]. And if we sort both the greed and size arrays we can efficiently assign the smallest available cookie satisfying each student's greed. 
//use two pointers, one for greed, one for cookie
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int satisfied = 0;

        int i = 0, j = 0; //j is for cookie, i is for greed
        int n = g.size(), m = s.size();

        while(i < n && j < m) {
            if(s[j] >= g[i]) {
                satisfied++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return satisfied;
    }
};