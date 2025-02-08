class DetectSquares {
private:
    unordered_map<long, int> ptsCount;
    vector<vector<int>> pts;
    
    long getKey(int x, int y) {
        return(static_cast<long>(x) << 32) | static_cast<long>(y);
    }
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        long key = getKey(point[0], point[1]);
        ptsCount[key]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];

        for(const auto& pt : pts) {
            int x = pt[0], y = pt[1];
            if (abs(py - y) != abs(px - x) || x == px || y == py) {
                continue;
            }
            res += ptsCount[getKey(x, py)] * ptsCount[getKey(px, y)];
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */