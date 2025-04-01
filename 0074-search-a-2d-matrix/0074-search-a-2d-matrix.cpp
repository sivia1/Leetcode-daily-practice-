class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0, high = n*m-1;
        while(low <= high) {
            int midPos = low + (high - low)/2;
            int element = matrix[midPos/n][midPos%n];
            if(element == target) {
                return true;
            }else if (element < target) {
                low = midPos + 1;
            } else {
                high = midPos - 1;
            }
        }
        return false;
    }
};