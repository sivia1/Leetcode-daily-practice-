//LRU Cache has two functions
//put function that stores key value pairs, meaning the data structure is similar to hashmap. And it is easy enough add a new key-value pair or update existing ones using hashmap in O(1) best/average TC


//Now the tricky part is the hashmap is limited to a size of capacity meaning, when the hashmap exceeds this capacity, we cannot arbitrarily remove a key--> we need to remove the least recently used one and we also need to know the second lru 

//so we need to know the order in which keys have been used 

//So, we have two functions:
//get method --> returns the value if key exists in the cache otherwise returns -1
//put(key, value) --> inserts or updates the key-value pair. If cache exceeds capacity it removes the least recently used.

//WE NEED 2 THINGS:
//Fast Lookup --> to check if a key exists and retrieve its value--> HashMap is great for that
//Track usage order--> so we can remove the lru item when the cache is full

//Thinking of implementing a queue : key at the front is lru and key at the back is mru:

//I am thinking of doing that using a singly linked list to keep track of the usage, inserting new elements at the head(mru) and removing the tail(lru). But a singly LL makes it hard to remove a node in O(1) time. because we need to know the previous node and since we don't have prev pointers we need to traverse from the head of the list to the the previous node which takes O(N) and not O(1). but if we switch to a doubly linked list, each node keeps prev and next pointer so :
//we can move any node to the front in O(1) time and removal of the LRU node from the tail also takes O(1) time

//[head] <-> [LRU] <-> [....] <-> [MRU] <-> [tail]
class Node {
public:
    int k;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int value) {
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) { //if key is found then update its position since it is recently used
            remove(cache[key]); //remove the key from the current's position
            insert(cache[key]); //insert it at the tail, most recently used
            return cache[key]->val; //return the value associated with the key
        }
        return -1;

    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) { //check if the key already exists
            remove(cache[key]); //remove 
            delete(cache[key]); //delete to avoid memory leaks
        }

        //create a new node with the given key and value
        cache[key] = new Node(key, value);
        insert(cache[key]);

        if(cache.size() > cap) {
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->k);

            delete(lru);
        } 
    }

private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    //remove function
    void remove(Node* node) { //parameter node
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        Node* prev = tail->prev;
        Node* next = tail;

        prev->next = node;
        node->prev = prev;

        node->next = next;
        next->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */