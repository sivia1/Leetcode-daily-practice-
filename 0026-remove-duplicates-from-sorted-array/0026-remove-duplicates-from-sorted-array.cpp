class Solution {
    //use a set to store the unique elements. clear the array. store unique elements in the array return array size
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> store;
        for(int num : nums) {
            store.insert(num);
        }
        nums.clear();

        for(int num : store) {
            nums.push_back(num);
        }
        return nums.size();
    }
};