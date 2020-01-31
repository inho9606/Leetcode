// https://leetcode.com/problems/excel-sheet-column-title/submissions/
// time: O(n/26) space: O(n/26)
// �־��� ������ 26������ �ٲ۴�. �������� 1�̸� A, 25�� Y, 0�̸� Z�̴�. �������� 0�� �� 26���� ������ ���� 1�� �Ǿ� ���ʿ��� ���ڸ� ������ �� �����Ƿ�, �������� 0�� ���� Z�� �߰��ϰ� i-1�� 26���� �������� �Ͽ� ���ʿ��� ������ ������ ���´�.
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