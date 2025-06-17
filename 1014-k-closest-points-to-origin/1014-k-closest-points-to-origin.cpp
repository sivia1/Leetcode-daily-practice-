class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //max heap to store k closest points
        //we store {distance, point_index} and keep heap size = k
        priority_queue<pair<long long, int>> maxHeap;
        for(int i = 0; i < points.size(); i++) {
            long long dist = (long long) points[i][0] * points[i][0] +
                             (long long) points[i][1] * points[i][1];
            
            maxHeap.push({dist, i});

            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while(!maxHeap.empty()) {
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return result;
    }
};