class Solution {
public:
//idea : GOAL - Maximize the min total sweetness on the piece that you'll eat
// Binary Search on Minimum Sweetness
//Min Possible Sweetness --> 1
//Max Possible Sweetness -> Sum(Sweetness) / (k+1)

//Find the threshold value x 
    bool canDivide(vector<int>& sweetness, int k, int minSweetness) {
        int pieces = 0, currSweetness = 0;
        for(int sweet : sweetness) {
            currSweetness += sweet;
            if(currSweetness >= minSweetness) {
                pieces++;
                currSweetness = 0;
            }
        }
        return pieces >= (k+1);
    }
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int low = 1, high = accumulate(sweetness.begin(), sweetness.end(), 0) / (k+1);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canDivide(sweetness,k, mid)) {
                low = mid + 1;//increase sweetness 
            } else {
                high = mid - 1; // decrease minsweetness
            }
        }
        return high;
    }
};