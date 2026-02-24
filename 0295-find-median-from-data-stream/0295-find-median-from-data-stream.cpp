class MedianFinder {
    vector<int> data;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto pos = lower_bound(data.begin(), data.end(), num);
        data.insert(pos, num);
    }
    
    double findMedian() {
        int n = data.size();
        if(n % 2 == 1) {
            return data[n / 2];
        } else {
            return (data[n/2 - 1] + data[n/2]) / 2.0;
        }
    }

    //lower_bound finds the correct sorted position in O(log n)
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */