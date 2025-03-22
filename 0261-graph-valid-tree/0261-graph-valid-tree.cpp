class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) {
            return false;
        }

        vector<vector<int>> adjacencyList(n);
        for(auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> seen;
        stack<int> st;
        st.push(0);
        seen.insert(0);

        while(!st.empty()) {
            int node = st.top();
            st.pop();

            for(auto neighbour : adjacencyList[node]) {
                if(seen.find(neighbour) != seen.end()) {
                    continue;
                }
                seen.insert(neighbour);
                st.push(neighbour);
            }
        }
        return seen.size() == n;
    }
};