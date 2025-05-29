class Solution {
public:
//heap; priority queue
//use map to store freq of each word
//if any words have same freq, sort it by lexicographical order
//otherwise sort it from highest occurring to lowest occuring--> max Heap
//pqs are max-Heap by default but here i need to define a custom comparator min-heap of size k to maintain k frequent words
//That way, the smallest item (in terms of frequency or lex order) can be popped when a better candidate appears.

//Need to define a custom comp that 
    //i)sorts by frequency descending 
    //ii) sort by lexicographical ascending if frequency is same
//in the heap:
//We actually reverse the comparison to make it a min-heap, so:
    //If a.freq < b.freq, a comes first (lower freq).
    //If a.freq == b.freq, we reverse the lex order, so
    //lexicographically larger goes first.
//This way, when size exceeds k, we pop the least useful one.

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto& f : words) {
            freq[f]++;
        }

        //custom comp for min-Heap
        auto comp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if(a.second == b.second) {
                return a.first < b.first; //reverse lex order
            }
            return a.second > b.second; //lower freq first
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> minHeap(comp);

        for(auto& entry : freq) {
            minHeap.push({entry.first, entry.second});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<string> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};