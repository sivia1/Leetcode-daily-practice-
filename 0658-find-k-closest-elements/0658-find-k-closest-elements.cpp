class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //insert the difference for every number with x into a diff array

        vector<pair<int, int>> diff;
        for(int num : arr) {
            diff.push_back({abs(num - x), num});
        }
        sort(diff.begin(), diff.end(), [](pair <int, int>& a, pair <int, int>& b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(diff[i].second);
        }
        sort(result.begin(), result.end());
        return result;
    }
};