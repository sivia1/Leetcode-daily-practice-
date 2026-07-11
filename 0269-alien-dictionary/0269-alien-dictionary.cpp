class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> indegree;

        //Initialize the graph with all unique characters
        for(string word : words) {
            for(char c : word) {
                indegree[c] = 0;
                adjList[c] = vector<char>();
            }
        }
        //Build the graph by comparing adjacent words
        for(int i = 0; i < words.size()-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];

            //Check for invalid case where word1 is a prefix of word2 but longer
            if(word1.size() > word2.size() && word1.substr(0, word2.size()) == word2) {
                return "";
            }
            //Find the first differing character and create an edge
            for(int j = 0; j < min(word1.size(), word2.size()); j++) {
                if(word1[j] != word2[j]) {
                    adjList[word1[j]].push_back(word2[j]);
                    indegree[word2[j]]++;
                    break;
                }
            }
        }
        //Breadth-first search
        string sb = "";
        queue<char> queue;
        for(auto item : indegree) {
            if(item.second == 0) {
                queue.push(item.first);
            }
        }
        while(!queue.empty()) {
            char c = queue.front();
            queue.pop();
            sb += c;
            for(char next : adjList[c]) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    queue.push(next);
                }
            }
        }
        if(sb.size() < indegree.size()) {
            return "";
        }
        return sb;
    }
};