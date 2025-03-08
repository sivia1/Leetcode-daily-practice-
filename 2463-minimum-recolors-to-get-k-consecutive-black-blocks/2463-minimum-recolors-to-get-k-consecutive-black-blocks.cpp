class Solution {
public:
//using sliding wondow 
//intialise a window of size k starting at index 0 and count the number of W's
//slide the wondow across the string
//remove the left most character 'W' from the count
//Add the next character into the count if it is 'W
//Keep track of the min number of W's in any window of size k
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int wCount = 0, minCount = INT_MAX;

        //count whites in the first window
        for(int i = 0; i < k; i++) {
            if(blocks[i] == 'W') {
                wCount++;
            }
        }
        minCount = wCount;
        //Slide the wondow
        for(int i = k; i < n; i++) {
            if(blocks[i] == 'W') {
                //add the element
                wCount++;
            }
            if(blocks[i - k] == 'W') {
                wCount--;
            }
            minCount = min(minCount, wCount); //update min
        }
        return minCount;
    }
};