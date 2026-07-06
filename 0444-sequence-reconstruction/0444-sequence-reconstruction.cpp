class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();

        // Graph and indegree array
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);

        // To check whether every number appears in sequences
        vector<bool> seen(n + 1, false);

        // Prevent duplicate edges
        unordered_set<long long> edges;

        // Build graph
        for (auto &seq : sequences) {

            // Mark all numbers that appear
            for (int x : seq)
                seen[x] = true;

            // Create edges between adjacent elements
            for (int i = 1; i < seq.size(); i++) {

                int u = seq[i - 1];
                int v = seq[i];

                long long key = 1LL * u * (n + 1) + v;

                // Ignore duplicate edges
                if (edges.count(key))
                    continue;

                edges.insert(key);

                graph[u].push_back(v);
                indegree[v]++;
            }
        }

        // Every number in nums must appear
        for (int x : nums) {
            if (!seen[x])
                return false;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int index = 0;

        while (!q.empty()) {

            // More than one choice -> multiple topological orders
            if (q.size() > 1)
                return false;

            int node = q.front();
            q.pop();

            // Order must exactly match nums
            if (nums[index] != node)
                return false;

            index++;

            for (int nei : graph[node]) {
                indegree[nei]--;

                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // All nodes must be processed
        return index == n;
    }
};