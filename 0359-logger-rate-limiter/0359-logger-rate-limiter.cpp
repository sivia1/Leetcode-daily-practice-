class Logger {
    //question: Design a logging system that restricts printing the same message within a 10-second window. If a message appears again within 10 seconds, should be ignored
    //it is possible that several messages arrive roughly at the same time
private:
    unordered_map<string, int> msgDict;

public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(msgDict.find(message) == msgDict.end() || timestamp - msgDict[message] >= 10) {
            msgDict[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */