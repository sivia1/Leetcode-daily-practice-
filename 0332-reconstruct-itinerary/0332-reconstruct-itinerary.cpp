class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;
        for(auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [src, dests] : adj) {
            sort(dests.begin(), dests.end());
        }

        vector<string> res;
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void dfs(const string& src, unordered_map<string, deque<string>>& adj, vector<string>& res) {
        while (!adj[src].empty()) {
            string next = adj[src].front();
            adj[src].pop_front();
            dfs(next, adj, res);
        }
        res.push_back(src);
    }
};