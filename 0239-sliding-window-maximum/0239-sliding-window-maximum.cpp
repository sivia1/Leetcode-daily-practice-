class Solution {
public:
//using maxHeap --> pop the elements when heap window is greater than i >= k-1, till i <= k-1, maintain highest element and index, so we know when to pop that way we are able to maintain the max element in the heap from each window
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<pair<int, int>> maxHeap;
        vector<int> output;
        for(int i = 0; i < size; i++) {
            maxHeap.push({nums[i], i});
            if(i >= k-1) {
                while(maxHeap.top().second <= i-k) {
                    maxHeap.pop();
                }
                output.push_back(maxHeap.top().first);
            }
        }
        return output;
    }
};