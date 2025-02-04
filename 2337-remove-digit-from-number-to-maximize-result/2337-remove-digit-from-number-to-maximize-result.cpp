class Solution {
public:
    string removeDigit(string number, char digit) {
         int indexToRemove = -1;
        
        // Find the first occurrence where removing the digit increases the number
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                // Check if the next digit is larger (greedy choice for max number)
                if (i + 1 < number.size() && number[i] < number[i + 1]) {
                    indexToRemove = i;
                    break;  // Remove the first such occurrence
                }
                indexToRemove = i;  // Keep track of the last occurrence
            }
        }
        
        // Remove the digit at the chosen index
        return number.substr(0, indexToRemove) + number.substr(indexToRemove + 1);
    }
};