// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/
// time: O(logn) memory: O1)
// 정렬되어 있는 배열을 순차적으로 더한 값 역시 정렬을 이룬다. 따라서 주어진 정렬의 양 끝 값의 합을 기준으로 해당 값이 target보다 크면 양 끝 수 중 큰 값인 오른쪽 값을 줄이고, target보다 작으면 두 값 중 더 작은 왼쪽 값을 증가시켜 양 끝 값의 합을 target에 가깝게 만든다.
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