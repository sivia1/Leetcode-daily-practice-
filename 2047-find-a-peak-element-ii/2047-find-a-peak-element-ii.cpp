class Solution {
public:
//idea : reduce the 2D problem to 1D
//row = idx//n, col = idx%n
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int top = 0, bottom = n-1;
        while(top <= bottom) {
            int maxRow = 0;
            int midCol = top + (bottom - top)/2;
            for(int row = 0; row < m; row++) {
                if(mat[row][midCol] >= mat[maxRow][midCol]) {
                    maxRow = row;
                }
            }

            bool leftBig = midCol > 0 && mat[maxRow][midCol - 1] > mat[maxRow][midCol];
            bool rightBig = midCol < n-1 && mat[maxRow][midCol+1] > mat[maxRow][midCol]; 

            if(!leftBig && !rightBig) {
                return vector<int>{maxRow, midCol};
            } else if(rightBig) {
                top = midCol + 1;
            } else {
                bottom = midCol-1;
            }
        }
        return vector<int>{-1, -1};
    }
};