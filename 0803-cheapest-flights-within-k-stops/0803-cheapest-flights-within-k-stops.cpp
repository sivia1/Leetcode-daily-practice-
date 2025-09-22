class Solution {
public:
//"I'll use Bellman-Ford algorithm because:
        // 1. We need shortest path with EXACTLY k+1 edges (k stops)
        // 2. Bellman-Ford finds shortest path with AT MOST i edges in i-th iteration
        // 3. After k+1 iterations, we'll have answer for at most k stops"
        
        // KEY INSIGHT TO MENTION:
        // "k stops means k+1 edges in the path. Bellman-Ford relaxes edges,
        // and after i iterations, we have shortest paths using at most i edges.
        
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //initialisation
        //cost to reach source is 0
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // "We'll do k+1 iterations. Each iteration allows us to use one more edge.
        // The key is to use a TEMP array - this ensures we only use distances 
        // from the PREVIOUS iteration, not the current one."
        
        // Main Bellman-Ford loop: k+1 iterations for k stops
        for(int i = 0; i <= k; i++) {
            vector<int> temp = dist;

            for(auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if(dist[from] != INT_MAX) {
                    //minimize, do not overwrite
                    temp[to] = min(temp[to], dist[from] + price);
                }
            }
            dist = temp;

        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};