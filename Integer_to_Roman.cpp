// https://leetcode.com/problems/integer-to-roman/submissions/
// Almost Simulation method

// Runtime: 8 ms, faster than 89.01% of C++ online submissions for Integer to Roman.
// Memory Usage: 9.4 MB, less than 19.87% of C++ online submissions for Integer to Roman.
class Solution {
public:
	string intToRoman(int num) {
		string answer = "";
		stack<string> st;
		int t=num, d=10, r;
		while(t>0) {
			r = t%d;
			if(r == 0) d*=10;
			else if(r == 4) {
				st.push("IV");
				d*=10;
			}
			else if(r == 9) {
				st.push("IX");
				d*=10;
			}
			else if(r == 40) {
				st.push("XL");
				d*=10;
			}
			else if(r == 90) {
				st.push("XC");
				d*=10;
			}
			else if(r == 400) {
				st.push("CD");
				d*=10;
			}
			else if(r == 900) {
				st.push("CM");
				d*=10;
			}
			else {
					if(r == 5) { st.push("V"); r = 5; }
					else if(r < 10) { st.push("I"); r = 1; }
					else if(r == 50) { st.push("L"); r = 50; }
					else if(r < 100) { st.push("X"); r = 10; }
					else if(r == 500) { st.push("D"); r = 500; }
					else if(r < 1000) { st.push("C"); r = 100; }
					else { st.push("M"); r = 1000; }
			}
			t -= r;
		}
		while(st.empty() == 0) {
			answer += st.top();
			st.pop();
		}
		return answer;
	}
};