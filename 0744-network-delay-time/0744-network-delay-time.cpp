class Solution {
public:
//implememnt shortest path, dijsktra
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //creating an adj list
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto& edge : times) {
            int src = edge[0];
            int dest = edge[1];
            int time = edge[2];

            graph[src].push_back({dest, time});
        }

        //initialise distances and priority_queue
        //use pq(min heap) to  always process the closest nodes first
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0; //dist to source is 0

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        //dijsktra algo
        //dist[i] = shortest distance from source k to node i
        // Initially: dist[k] = 0, all others = ∞
        // As algorithm progresses, we discover shorter paths and update these values
        while(!pq.empty()) {
            auto[currDist, u] = pq.top();

            //I'm popping the minimum distance node because Dijkstra's greedy approach ensures this gives us the optimal path.
            pq.pop();
            // Skip if we've already found a better path
            if(currDist > dist[u]) continue;

            //dist[u] = How far is node u from our starting point k?
            //dist[v] = How far is node v from our starting point k?
            for(auto& [v, weight] : graph[u]) {
                int newDist = dist[u] + weight;

                if(newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
        //Find the maximum distance (time for last node to receive signal)
        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) {
                return -1;
            }
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }

    //Time --> (E log V), SPACE --> o(e+v)
};