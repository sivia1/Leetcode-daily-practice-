class Solution {
public:
//to use fewest boxes, always use biggest boxes

// Calculate totalApples: Sum up all the numbers in the apple array. Prioritize Boxes: Sort the capacity array in descending order (largest to smallest).Fill Boxes: Iterate through the sorted capacities:Pick the largest box.Subtract its capacity from totalApples. Increase box counter by 1.Check if totalApples is <= 0. If yes, stop.

    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());

        int count = 0;
        for(int i = 0; i < capacity.size(); i++) {
            totalApples -= capacity[i];
            count += 1;
            if(totalApples <= 0) {
                break;
            }
        }
        return count;
    }
};