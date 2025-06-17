class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDist = INT_MAX;
        int result = -1;

        for(int i = 0; i < points.size(); i++) {
            int px = points[i][0];
            int py = points[i][1];

            if(px == x || py == y) {
                int distance = abs(x-px) + abs(y-py);

                if (distance < minDist) {
                    minDist = distance;
                    result = i;
                }
            }
        }
        return result;
    }
};