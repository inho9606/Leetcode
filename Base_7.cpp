// https://leetcode.com/problems/base-7/submissions/
// I. Store given number n mod 7 to stack.
// II. Divide n by 7. And repeat I, and II until it becomes 0.
// III. Add elements in stack to string answer.
// time: O(logn) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Base 7.
// Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Base 7.
class Solution {
public:
	string convertToBase7(int num) {
		string answer = "";
		for(int i=num; i!=0; i/=7)
			answer = to_string(abs(i%7)) + answer;
		if(num < 0) answer = "-" + answer;
		else if(num == 0) answer = "0";
		return answer;
	}
};

/*
* Original Version with stack, space: O(logn)
class Solution {
public:
	string convertToBase7(int num) {
		string answer = "0";
		stack<int> st;
		for(int i=num; i!=0; i/=7)
			st.push(abs(i%7));
		if(num < 0) answer = "-";
		else if(num > 0) answer = "";
		while(st.empty() == 0) {
			answer += to_string(st.top());
			st.pop();
		}
		return answer;
	}
};
*/