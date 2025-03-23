class Solution {
public:
//maximum of a minimum --> hinting towards binary search
//best way to maximize the minimum magnetic force is to spread out the balls as much as possible
//sorting would be benefecial here
//perform binary search on the possible values of minimum force
//smallest possible force is 1 and largest possible force is pos[n-1] - pos[0]
    bool canPlaceBalls(vector<int>& position, int m, int minForce) {
        int count = 1;
        int lastPos = position[0];
        for(int i = 0; i < position.size(); i++) {
            if(position[i] - lastPos >= minForce) {
                count++;
                lastPos = position[i];
            }
            if(count >= m) {
                return true;
            } 
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int low = 1, high = position.back() - position.front();
        int result = 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canPlaceBalls(position, m, mid)) {
                result = mid;
                low = mid+1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};