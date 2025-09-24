class Solution {
public:
//to ensure I don't insert duplicate characters, I use set
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> store(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for(int i = 0; i < nums2.size(); i++) {
            if(store.find(nums2[i]) != store.end()) {
                result.insert(nums2[i]);
            }
        }
        vector<int> output(result.begin(), result.end());
        return output;
    }
};