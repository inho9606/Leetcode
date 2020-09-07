// https://leetcode.com/problems/logger-rate-limiter/submissions/
// I. To record used string with timestamp, use map datastructure.
// II. Store the string and timestamp in map. If the string is already n map, which means the string is printed before, then compare the new timestamp and the previous stamp. If the difference is greatre than or equal to 10, then it can be printed again. Otherwise, can't.
// time: O(logn) space: O(n)
// Runtime: 144 ms, faster than 94.04% of C++ online submissions for Logger Rate Limiter.
// Memory Usage: 32.5 MB, less than 98.39% of C++ online submissions for Logger Rate Limiter.
class Logger {
public:
	/** Initialize your data structure here. */
	unordered_map<string,int> m;
	Logger() {
	}
    
	/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, string message) {
		auto ptr = m.find(message);
		if(ptr == m.end() || ptr->second <= timestamp-10) {
			m[message] = timestamp;
			return 1;
		}
		return 0;
	}
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */