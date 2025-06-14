class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int mid = (n - 1) / 2;  // Last index of smaller half
        
        // Fill odd positions (1,3,5...) with larger half (in reverse order)
        int i = 1;
        for (int j = n - 1; j > mid; j--) {
            nums[i] = sorted[j];
            i += 2;
        }
        
        // Fill even positions (0,2,4...) with smaller half (in reverse order)  
        i = 0;
        for (int j = mid; j >= 0; j--) {
            nums[i] = sorted[j];
            i += 2;
        }
    }
};