class Solution {
public:
    vector<string> dict;

    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        dict.resize(26);
        for(auto word: replacements)
            dict[word[0][0]-'A'] = word[1];
        return solve(text);
    }

    string solve(string text) {
        int i=0;
        string result="";
        while(i<text.length()){
            if(text[i]=='%'){
                if(dict[text[i+1]-'A'].find('%')!=std::string::npos){
                    dict[text[i+1]-'A'] = solve(dict[text[i+1]-'A']);
                }
                result += dict[text[i+1]-'A'];
                i+=2;
            } else
                result += text[i];
            i++;
        }
        return result;
    }
};