class Solution {
public:
//Person i can see person j if:

// j is to the right of i (i.e., i < j)
// All people between them are shorter than both person i and person j

// The key insight you're missing: it's not just about finding the first taller person. Person i stops seeing further people when there's someone between them who is taller than either person i or the person they're trying to see.
    vector<int> canSeePersonsCount(vector<int>& heights) {
         int n = heights.size();
        vector<int> result(n, 0);
        
        stack<int> st; // monotonic decreasing stack (indices)
        
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            int seenCount = 0;
            
            // Pop all people shorter than current person
            // These people will be blocked by current person for anyone to the left
            while (!st.empty() && heights[st.top()] < heights[i]) {
                st.pop();
                seenCount++;
            }
            
            // If stack is not empty, current person can see the top of stack
            // (first person taller than or equal to current person)
            if (!st.empty()) {
                seenCount++;
            }
            
            result[i] = seenCount;
            st.push(i);
        }
        
        return result;
    }
};