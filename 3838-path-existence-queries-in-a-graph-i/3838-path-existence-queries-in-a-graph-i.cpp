class Solution {
public:
//APPROACH : Nums is already sorted, if 2 nodes are connected, their difference will atmost be maxDiff, so we can group together the connected nodes while traversing once.

//1. Create Group Array--> Traverse the nums array, if diff b/w adjacent numbers is > maxDiff it means they belong to diff groups else same group

//2. Processing queries for each query[u,v] check if they belong to same group and push to answer vector, if u == v then TRUE else FALSE
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> group(n, 0);
        int currGroup = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i-1] > maxDiff) {
                currGroup++;
            }
            group[i] = currGroup;
        }

        vector<bool> answer;
        for(auto& query : queries) {
            int u = query[0];
            int v = query[1];
            answer.push_back(group[u] == group[v]);
        }
        return answer;
    }
};