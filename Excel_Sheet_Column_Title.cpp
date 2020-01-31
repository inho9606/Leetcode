// https://leetcode.com/problems/excel-sheet-column-title/submissions/
// time: O(n/26) space: O(n/26)
// 주어진 정수를 26진수로 바꾼다. 나머지가 1이면 A, 25면 Y, 0이면 Z이다. 나머지가 0일 때 26으로 나누면 몫이 1이 되어 불필요한 문자를 삽입할 수 있으므로, 나머지가 0일 때는 Z를 추가하고 i-1을 26으로 나누도록 하여 불필요한 문자의 삽입을 막는다.
class Solution {
public:
	string convertToTitle(int n) {
		stack<char> temp;
		string answer = "";
		for(int i=n; i>0; i/=26) {
			if(i%26==0) { temp.push('Z'); i -= 1; }
			else temp.push(64+(i%26));
		}
		while(temp.empty() == 0) {
			answer += temp.top();
			temp.pop();
		}
		return answer;
	}
};