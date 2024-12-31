class Solution {
public:
//strings are mutable in cpp use that to advantage
//idea : split the strings by dot and convert them to integer levels and separated by dots
//After splitting both strings, you'll have two vectors (or arrays) of integers representing the version levels.
//If the two vectors have different lengths, pad the shorter one with 0s at the end to equalize their sizes.
//compare levels and return what's asked 

vector<int> stringConvert(const string& version) {
    string temp = version;
    vector<int> levels;
    size_t pos;

    while((pos = temp.find('.')) != string::npos) {
        levels.push_back(stoi(temp.substr(0, pos))); //convert the substring to integer
        temp.erase(0, pos+1); //remove the processed part
    }
    levels.push_back(stoi(temp));
    return levels;
}
    int compareVersion(string version1, string version2) {
        //split versions into levels
        vector<int> v1 = stringConvert(version1);
        vector<int> v2 = stringConvert(version2);


        //equalize them
        while(v1.size() < v2.size()) v1.push_back(0);
        while(v2.size() < v1.size()) v2.push_back(0);

        //compare levels
        for(size_t i = 0; i < v1.size(); i++) {
            if(v1[i] < v2[i]) {
                return -1;
            }
            if(v2[i] < v1[i]) {
                return 1;
            }
        }
        return 0;
    }
};