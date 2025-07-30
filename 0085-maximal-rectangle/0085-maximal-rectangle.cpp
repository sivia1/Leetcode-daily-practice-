class Solution {
public:
//to find a bigger rectangle filled with 1s you gotta find small rectangles 
//precompute 
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size(), cols = matrix[0].size();
        int maxArea = 0;
        
        // DP arrays for each row
        vector<int> heights(cols, 0);  // Height of consecutive 1's ending here
        vector<int> left(cols, 0);     // Left boundary of rectangle ending here
        vector<int> right(cols, cols); // Right boundary of rectangle ending here
        
        for (int i = 0; i < rows; i++) {
            // Update heights
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Update left boundaries
            int curLeft = 0; // Current left boundary for 1's
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curLeft);
                } else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            
            // Update right boundaries
            int curRight = cols; // Current right boundary for 1's
            for (int j = cols - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                } else {
                    right[j] = cols;
                    curRight = j;
                }
            }
            
            // Calculate max area for current row
            for (int j = 0; j < cols; j++) {
                int area = heights[j] * (right[j] - left[j]);
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};