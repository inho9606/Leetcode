// https://leetcode.com/problems/string-compression/submissions/
// Check if the character is changed or not. If the character is different from the previous one and the previous one has appeared more than one time, the second spot of that character implaces the number of how many it appeared before changed. for the last element, repeat the process one more time after loop.
// time: O(n) space: O(n)
// Runtime: 4 ms, faster than 99.70% of C++ online submissions for String Compression.
// Memory Usage: 9.4 MB, less than 25.00% of C++ online submissions for String Compression.
class Solution {
public:
	int compress(vector<char>& chars) {
		int answer=0, cnt=0, k=0;
		stack<char> st;
		for(int i=0; i<chars.size(); i++) {
			if(i==0) answer++;
			else {
				if(chars[i] != chars[i-1]) {
					if(cnt > 1) {
						for(int j=cnt; j>0; j/=10) st.push((j%10)+48);
						while(st.empty() == 0) {
							chars[answer++] = st.top();
							st.pop();
						}
					}
					chars[answer++] = chars[i];
					cnt = 0;
				}
			}
			cnt++;
		}
		if(cnt > 1) {
			for(int j=cnt; j>0; j/=10) st.push((j%10)+48);
			while(st.empty() == 0) {
				chars[answer++] = st.top();
				st.pop();
			}
		}
		return answer;
	}
};