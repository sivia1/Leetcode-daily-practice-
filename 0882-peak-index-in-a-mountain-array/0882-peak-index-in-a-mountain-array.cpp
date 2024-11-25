class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n-1;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(arr[mid] > arr[mid+1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};