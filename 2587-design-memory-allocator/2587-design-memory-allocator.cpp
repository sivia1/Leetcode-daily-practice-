class Allocator {
    //approach -->  simulate the memory array:

// Use an array where memory[i] stores the ID (0 = free)
// Allocate: Scan left-to-right to find consecutive free slots
// Free: Scan entire array and free matching IDs
private:
    vector<int> memory; //0 means free, otherwise stores mID
public:
    Allocator(int n) {
        memory.resize(n, 0); //initialize all as free
    }
    
    int allocate(int size, int mID) {
        int n = memory.size();
        //find leftmost block of 'size' consecutive free units
        for(int i = 0; i <= n - size; i++) {
            bool canAllocate = true;
            //check if we have 'size' consecutive free units starting at i
            for(int j = i; j < i+size; j++) {
                if(memory[j] != 0) {
                    canAllocate = false;
                    break;
                }
            }
            //If found, allocate and return starting index
            if(canAllocate) {
                for(int j = i; j < i+size; j++) {
                    memory[j] = mID;
                }
                return i;
            }
        }
        return -1; //no suitable block found
    }
    
    int freeMemory(int mID) {
        int count = 0;
        //Free all memory units with given mID
        for(int i = 0; i < memory.size(); i++) {
            if(memory[i] == mID) {
                memory[i] = 0;
                count++;
            }
        }
        return count;
    }
    //space -- > o(n)
    //allocate --> o(n * size)
    //freeMemory--> o(n)
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */