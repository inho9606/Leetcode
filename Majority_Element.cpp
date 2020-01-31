// https://leetcode.com/problems/majority-element/submissions/
// time: O(nlogn) space: O(1)
// �־��� �迭�� ������ ��, �տ������� �ݺ��Ǵ� ������ ������ ����. ���ӵ� ���� ������ ���ӵ� ���� Ƚ������ ������ �� ������ ���� ������Ʈ�Ѵ�. O(n)�� �ǰ� �ϴ� ����� �����Ͱ����� �𸣰ڴ�..
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int minimum=0, cnt=0, answer;
		sort(nums.begin(), nums.end());
		for(int i=0; i<nums.size(); i++) {
			if(i==0 || nums[i-1] != nums[i]) {
				if(i > 0 && cnt > minimum) { answer = nums[i-1]; minimum = cnt; }
				cnt = 1;
			}
			else cnt++;
			if(i == nums.size()-1 && cnt > minimum) answer = nums[i];
		}
		return answer;
	}
};