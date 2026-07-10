class Solution {
public:
//optimal solution:
//A connected component is a maximal group of nodes where every node can reach every other node.
// Imagine

// Queries

// (1,3)

// (1,2)

// (2,3)

// (3,1)

// (2,1)

// Every single query is making DFS rediscover

// 1
// ↓
// 2
// ↓
// 3

// again and again.

// That is wasted work.

//How do we find components without DFS?
//this works only because nums is sorted

//If adjacent elements have a gap larger than maxDiff, then NO edge can ever cross that gap.

//every time we see

// nums[i]-nums[i-1] > maxDiff

// a new connected component starts.
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        //what we can do is
        //scan array once
        //build components IDs
        // Answer each query in O(1)
        vector<int> component(n);
        component[0] = 0;
        for(int i = 1; i < n; i++) {
            if(abs(nums[i] - nums[i-1]) <= maxDiff) {
                component[i] = component[i-1];
            }
            else if (abs(nums[i] - nums[i-1]) > maxDiff) {
                component[i] = component[i-1] + 1;
            }
        }
        vector<bool> ans;
        for(auto query : queries) {
            int u = query[0];
            int v = query[1];

            ans.push_back(component[u] == component[v]);

        }
        return ans;

    }
};