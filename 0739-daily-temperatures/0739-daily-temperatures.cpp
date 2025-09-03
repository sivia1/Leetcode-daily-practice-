class Solution {
public:
//approach --> For each day, I need to find the next warmer day. Instead of checking forward from each day (which would be O(n²)), I can use a stack to track days waiting for warmer temperatures

//I iterate through each day and maintain a stack of indices representing days waiting for warmer weather
//Before processing the current day, I check if today's temperature can 'resolve' any waiting days
//While the stack isn't empty AND today is warmer than the day at stack's top
//Pop that day and calculate: current_day - waiting_day. 
//Then I push today's index onto the stack since it's now waiting for a warmer day
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;

        for(int currDay = 0; currDay < n; currDay++) {
            int currTemp = temperatures[currDay];
            while(!st.empty() && temperatures[st.top()] < currTemp) {
                int prevDay = st.top();
                st.pop();
                answer[prevDay] = currDay - prevDay;
            }
            st.push(currDay);
        }
        return answer;
    }
    //Time: O(n) - each index pushed and popped at most once
    //Space: O(n) - stack can hold all indices in worst case
};