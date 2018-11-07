class Logger {
    unordered_map<string, int> last_print;
public:
    /** Initialize your data structure here. */
    Logger() = default;
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (last_print.count(message) && last_print[message] + 10 > timestamp) {
            return false;
        }
        last_print[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
