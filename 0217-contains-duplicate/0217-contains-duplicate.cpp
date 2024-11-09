class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //use an unordered_Set and check if the element already exists in the set before inserting, 
        //if it does return true else insert and then return false

        unordered_set<int> seen;
        for(int num : nums) {
            if(seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};