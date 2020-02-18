// https://leetcode.com/problems/convert-a-number-to-hexadecimal/submissions/
// Convert four-bits from the most rightbits in given num into hexadecimal. Use stack to record the converted result for each four bits.
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert a Number to Hexadecimal.
// Memory Usage: 8.3 MB, less than 28.57% of C++ online submissions for Convert a Number to Hexadecimal.
class Solution {
public:
	string toHex(int num) {
		if(num == 0) return "0";
		stack<char> st;
		string answer = "";
		int temp;
		for(int i=0; i<8; i++) {
			temp = (num & 15);
			if(temp < 10) st.push(temp+48);
			else if(temp >= 10) st.push(temp-10+'a');
			num = num >> 4;
		}
		while(st.empty() == 0) {
			if(answer.size() != 0 || st.top() != 48)  answer += st.top();
			st.pop();
		}
		return answer;
	}
};