class Twitter {
    int count;
    unordered_map<int, set<int>> followMap;
    unordered_map<int, vector<vector<int>>> tweetMap;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    // looks like a priority queue would be a pretty great idea
    //also need to keep track of time the tweet was posted from the particular tweetID
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare = [] (const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);
        followMap[userId].insert(userId);
        for(int followeeId : followMap[userId]) {
            if(tweetMap.count(followeeId)) {
                const vector<vector<int>>& tweets = tweetMap[followeeId];
                int index = tweets.size() - 1;
                minHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }
        while(!minHeap.empty() && res.size() < 10) {
            vector<int> curr = minHeap.top();
            minHeap.pop();
            res.push_back(curr[1]);
            int index = curr[3];
            if (index > 0) {
                const vector<int>& tweet = tweetMap[curr[2]][index - 1];
                minHeap.push({tweet[0], tweet[1], curr[2], index - 1});
            }
        }
        return res;
    }
    //For the below two functions, we can use the data structure hashmap -> userID --> Hash Set of followee id
    //HashMap --> userId --> list of [count, TweetId]
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */