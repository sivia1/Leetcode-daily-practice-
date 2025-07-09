bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++; //freq counting O(n)
        }

        vector<pair<int, int>> store(freq.begin(), freq.end()); //converting map to vector O(n)
        sort(store.begin(), store.end(), comp); //sorting O(n log n)

        vector<int> result;
        for(int i = 0; i < k; i++) { //extracting top k O(k) in the worst case O(n)
            result.push_back(store[i].first);
        }
        return result;
    }
    //extra space O(n) --> hashmap, Vector pof pairs O(n)
    //TC --> O(n + n + n log n + k) ~ O(n log n)
    //SC --> O(n)
};