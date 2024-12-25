class Solution {
public:
//make an adjacency list
//perform BFS -- layer by layer , stop keeps track of how many layers processed
//numeric_limits<int>::max() -- setting distances to infinity-- a city is unreachable until proven otherwise
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n, numeric_limits<int>::max());
        queue<pair<int, int>> q;
        //current city and cost to reach that city
        q.push({src, 0});
        int stops = 0;

        //stop keeps track of how many layers processed
        while(stops <= k && !q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto[node, distance] = q.front();
                q.pop();
                //for each neighbor of the current city, calculate the total cost to reach the neigh
                //If the new cost is cheaper than the previously recorded cost (dist[neighbor]), update dist            [neighbor] and add the neighbor to the queue.
                for(auto& [neighbor, price] : adj[node]) {
                    if(price + distance >= dist[neighbor]) {
                        continue;
                    }
                    dist[neighbor] = price + distance;
                    q.push({neighbor, dist[neighbor]});
                }
            }
            stops++;
        }
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};