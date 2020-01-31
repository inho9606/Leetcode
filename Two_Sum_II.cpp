// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/
// time: O(logn) memory: O1)
// ���ĵǾ� �ִ� �迭�� ���������� ���� �� ���� ������ �̷��. ���� �־��� ������ �� �� ���� ���� �������� �ش� ���� target���� ũ�� �� �� �� �� ū ���� ������ ���� ���̰�, target���� ������ �� �� �� �� ���� ���� ���� �������� �� �� ���� ���� target�� ������ �����.
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> answer(2);
		int i=0, j=numbers.size()-1;
		while(numbers[i]+numbers[j] != target) {
			if(numbers[i]+numbers[j] > target) j--;
			else i++;
		}
		answer[0] = i+1;
		answer[1] = j+1;
		return answer;
	}
};