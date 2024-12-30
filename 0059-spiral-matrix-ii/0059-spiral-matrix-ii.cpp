class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int left = 0, right = n;
        int top = 0, bottom = n;
        int num = 1, maxNum = n * n;

        while(num <= maxNum) {
            //move left to right
            for(int i = left; i < right && num <= maxNum; i++) {
                matrix[top][i] = num++;
            }
            top++;
            //move top to bottom
            for(int i = top; i < bottom && num <= maxNum; i++) {
                matrix[i][right-1] = num++;
            }
            right--;
            //move right to left
            for(int i = right - 1; i >= left && num <= maxNum; i--) {
                matrix[bottom-1][i] = num++;
            }
            bottom--;
            for(int i = bottom - 1; i >= top && num <= maxNum; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
        return matrix;
    }
};