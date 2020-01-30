// https://leetcode.com/problems/single-number/submissions/
// time: O(n) space: O(1) Xor 연산자 사용
// time: O(nlogn) space: O(1) 정렬 사용

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int answer=0;
		for(int i=0; i<nums.size(); i++)
			answer ^= nums[i];
//		answer = 0;
//		sort(nums.begin(), nums.end());
//		for(int i=0; i<nums.size()-1; i+=2)
//			if(nums[i] != nums[i+1]) return nums[i];
//		if(answer==0) answer = nums[nums.size()-1];
		return answer;
	}
};