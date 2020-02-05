// https://leetcode.com/problems/contains-duplicate/submissions/
// ���� �� ���� ���� �������̸� Ʈ�� ��ȯ, �׷� �� ������ ����. set�� ����ؼ� count �Լ� ��������� �����ϴ� �ͺ��� �ӵ� ����. count�� logn�̰� Ž�� �ð� n �ؼ� nlogn ���ðŰ����� ���� ������ ����??
// time: O(nlogn) space: O(1) speed: faster than 97.1%
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if(nums.size()==0) return 0;
		sort(nums.begin(), nums.end());
		for(int i=0; i<nums.size()-1; i++)
			if(nums[i] == nums[i+1]) return 1;
		return 0;
	}
};