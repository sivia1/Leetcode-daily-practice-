class Solution {
public:
    string answerString(string word, int numFriends) {
        int l = 0, len = word.size() - (numFriends - 1);
        vector<int> list;
        if(numFriends == 1) {
            return word;
        }
        for(int i = 0; i < word.size(); i++) {
            if(word[i] < l) {
                continue;
            }
            if(l == word[i]) {
                list.push_back(i);
            } else {
                l = word[i];
                list.clear();
                list.push_back(i);
            }
        }
        vector<string> ans;
        for(int i = 0; i < list.size(); i++) {
            string t = word.substr(list[i], (word.size() - list[i]) < len ? word.size() - list[i] : len);
             ans.push_back(t);
        }
        sort(ans.begin(), ans.end());
        return ans.back();
    }
};