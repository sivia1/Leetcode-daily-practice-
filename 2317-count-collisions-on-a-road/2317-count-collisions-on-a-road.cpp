class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n-1;
        //skip leading L's
        while(left < n && directions[left] == 'L') {
            left++;
        }
        //skip trailing R's
        while(right >= 0 && directions[right] == 'R') {
            right--;
        }
        int collisions = 0;

        for(int i = left; i <= right; i++) {
            //each contribute to 1 collision
            if(directions[i] != 'S') {
                collisions++;
            }
        }
        return collisions;
    }
};