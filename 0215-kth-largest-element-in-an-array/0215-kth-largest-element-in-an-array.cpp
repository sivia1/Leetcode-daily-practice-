class Solution {
public:
//again use a minHeap--> priority queue , maintain the size of the minheap to k size and return the top elemeent
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num : nums) {
            minHeap.push(num);

            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};