class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lower.empty()) {
            lower.push(num);
            return;
        }
        if(lower.size() > higher.size()) {
            if(lower.top() > num) {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            } else {
                higher.push(num);
            }
        } else {
            if(num > higher.top()) {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            } else{
                lower.push(num);
            }
        }
    }
    
    double findMedian() {
        double result = 0.0;
        if(lower.size() == higher.size()) {
            result = lower.top() + (higher.top() - lower.top()) / 2.0;
        } else {
            if(lower.size() > higher.size()) {
                result = lower.top();
            } else {
                result = higher.top();
            }
        }
        return result;
    }
private:
    priority_queue<int> lower; //max Heap
    priority_queue<int, vector<int>, greater<int>> higher; //min Heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */