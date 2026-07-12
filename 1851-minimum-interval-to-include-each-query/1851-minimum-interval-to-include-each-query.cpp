class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> q;

        for(int i=0;i<queries.size();i++)
            q.push_back({queries[i],i});

        sort(q.begin(), q.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int i = 0;

        vector<int> ans(queries.size());

        for(auto &[query,idx] : q){

            while(i<intervals.size() &&
                intervals[i][0] <= query){

                int l = intervals[i][0];
                int r = intervals[i][1];

                pq.push({r-l+1,r});

                i++;
            }

            while(!pq.empty() &&
                pq.top().second < query){

                pq.pop();
            }

        if(pq.empty())
            ans[idx]=-1;
        else
            ans[idx]=pq.top().first;
        }
        return ans;
    }
};