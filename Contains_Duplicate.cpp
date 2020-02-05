// https://leetcode.com/problems/contains-duplicate/submissions/
// 정렬 후 같은 수가 연속적이면 트루 반환, 그런 게 없으면 폴스. set을 사용해서 count 함수 사용했으나 정렬하는 것보다 속도 느림. count도 logn이고 탐색 시간 n 해서 nlogn 나올거같은데 느린 이유는 무엇??
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