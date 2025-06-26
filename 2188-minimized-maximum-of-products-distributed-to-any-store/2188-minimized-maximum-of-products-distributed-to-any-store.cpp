class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());

        while(left <= right) {
            int mid = left + (right - left)/2;

            long long store = 0;
            for(int qty : quantities) {
                store += (qty - 1)/ mid + 1;
            }
            if(store <= n) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};