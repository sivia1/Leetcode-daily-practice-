class Solution {
    //need to know How many rooms? Heap stores end times
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int rooms = 1;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if(!minHeap.empty() && minHeap.top() <= start) {
                minHeap.pop();
            }
            minHeap.push(end);
        }
        return minHeap.size();
    }
};