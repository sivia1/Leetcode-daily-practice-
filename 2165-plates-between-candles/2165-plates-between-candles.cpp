class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector <int> platePrefix(n, 0), leftCandle(n, -1), rightCandle(n, -1);
        int plateCount = 0;
        for (int i = 0; i < n; i++) {
            if(s[i] == '*') {
                plateCount++;
            }
            platePrefix[i] = plateCount;
        }
    
        // Step 2: Compute leftCandle array
        int lastCandle = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') lastCandle = i;
            leftCandle[i] = lastCandle;
        }
    
        // Step 3: Compute rightCandle array
        lastCandle = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') lastCandle = i;
            rightCandle[i] = lastCandle;
        }
    
        // Step 4: Process queries using binary search
        vector<int> result;
        for (auto& q : queries) {
            int left = q[0], right = q[1];

            // Find the first candle >= left (rightCandle)
            int lCandle = rightCandle[left];
            // Find the last candle <= right (leftCandle)
            int rCandle = leftCandle[right];

            if (lCandle != -1 && rCandle != -1 && lCandle < rCandle) {
                result.push_back(platePrefix[rCandle] - platePrefix[lCandle]);
            } else {
                result.push_back(0);
            }
        }
        return result;
    }
};