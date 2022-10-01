class Logger {
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (m2t_.find(message) == m2t_.end()) {
            m2t_[message] = timestamp;
            return true;
        } else {
            if (timestamp - m2t_[message] >= 10) {
                m2t_[message] = timestamp;
                return true;
            } else return false;
        }
    }
    
    unordered_map<string, int> m2t_;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */