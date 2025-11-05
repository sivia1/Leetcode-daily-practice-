class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> counts;
        
        // Iterate through all S*S possible relative positions (r, c)
        for (int r = 0; r < sideLength; ++r) {
            for (int c = 0; c < sideLength; ++c) {
                
                // Calculate the number of rows 'i' such that i % sideLength == r
                // Formula: floor((H - 1 - r) / S) + 1
                // Using integer division for floor:
                int row_count = (height - 1 - r) / sideLength + 1;
                
                // Calculate the number of columns 'j' such that j % sideLength == c
                // Formula: floor((W - 1 - c) / S) + 1
                int col_count = (width - 1 - c) / sideLength + 1;
                
                // Total cells for this relative position (r, c)
                counts.push_back(row_count * col_count);
            }
        }
        
        // 2. Greedy Selection
        // We can only choose 'maxOnes' relative positions to fill with '1's.
        // To maximize the total count, we must choose the positions that occur most frequently.
        
        // Sort the counts in descending order (largest first)
        sort(counts.begin(), counts.end(), greater<int>());
        
        long long answer = 0; // Use long long for the sum to prevent potential overflow
        
        // Sum the top 'maxOnes' counts
        int limit = std::min((int)counts.size(), maxOnes);
        
        for (int i = 0; i < limit; ++i) {
            answer += counts[i];
        }
        
        // The problem asks for 'int' return type, so cast the result back.
        // Note: For large constraints, the sum might exceed 2^31-1, but based on typical constraints 
        // for "int" return, this should be safe. Keeping the calculation in long long is safer.
        return (int)answer;
    }
};