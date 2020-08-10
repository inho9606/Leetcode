// https://leetcode.com/problems/product-of-array-except-self/
// Mock Interview
// Failed to solve without division..
// time: O(n) space: O(1)
// Spent 32 mins
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> answer(nums.size());
		int cnt, n=1, zeros=0;
		for(int i=0; i<nums.size(); i++) {
			if(nums[i] != 0) n *= nums[i];
			else zeros+=1;
		}
		for(int i=0; i<nums.size(); i++) {
			if(zeros>1 || (zeros==1 && nums[i] != 0)) {
				answer[i] = 0;
				continue;
			}
			else if(zeros==1 && nums[i] == 0) {
				answer[i] = n;
				continue;
			}
			answer[i] = n/nums[i];
		}
		return answer;
	}
};

/*
* Most Voted Code on discuss board
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> answer(nums.size(), 1);
		int s=1, e=1;
		for(int i=0; i<nums.size(); i++) {
			answer[i] *= s;
			s *= nums[i];
			answer[nums.size()-1-i] *= e;
			e *= nums[nums.size()-1-i];
		}
		return answer;
	}
};
*/