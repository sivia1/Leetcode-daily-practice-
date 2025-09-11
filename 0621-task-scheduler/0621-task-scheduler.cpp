class Solution {
public:
//approach --> Count task frequencies
// Find maximum frequency and count of tasks with max frequency
// Use formula: (max_freq - 1) × (n + 1) + max_count
// Take max with total task count
    int leastInterval(vector<char>& tasks, int n) {
        //count freq of each task
        unordered_map<char, int> freq;
        for(char task : tasks) {
            freq[task]++;
        }

        //count max freq
        int maxFreq = 0;
        for(auto& pair : freq) {
            maxFreq = max(maxFreq, pair.second);
        }

        //count how many tasks have the max freq
        int maxCount = 0;
        for(auto& pair : freq) {
            if(pair.second == maxFreq) {
                maxCount++;
            }
        }
        //Calculate minimum intervals using the formula
        // (max_freq - 1) * (n + 1) + max_count
        int result = (maxFreq - 1) * (n+1) + maxCount;

        //The answer cannot be less than total number of tasks
        return max(result, (int)tasks.size());
    }

    //TC --> O(n)
    //O(1) since we have at most 26 different task types
};