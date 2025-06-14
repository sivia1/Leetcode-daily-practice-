class KthLargest {
//approach :
    //builind a live ranking system that takes input and displays the kth largest element
    //keeps track of the kth highest score
    //updates ranking every time a new student submits score

    //USE MIN-HEAP
    //Only the top K largest elements matter
    //Among these elements, smallest one is our Kth Largest
    //A min-Heap of size k gives us smallest element at top
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int key;
public:
    KthLargest(int k, vector<int>& nums) {
        key = k;
        //Add all numbers to heap
        for(int num : nums) {
            minHeap.push(num);

            //keep only k largest elements
            if(minHeap.size() > key) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        //keep only k largest elements
        if(minHeap.size() > key) {
            minHeap.pop();
        }
        //top of minHeap is the kth largest
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */