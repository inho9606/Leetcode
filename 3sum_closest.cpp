// https://leetcode.com/problems/3sum-closest/submissions/
// I. Compare three elements and its distance. Mke the second item standard.
// II. If the sum of three elements are grater or more less than target, it means getting farther from the target.
// time: O(n^2) space: O(1)
// Runtime: 20 ms, faster than 46.09% of C++ online submissions for 3Sum Closest.
// Memory Usage: 9.8 MB, less than 68.79% of C++ online submissions for 3Sum Closest.
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int answer, dist=INT_MAX, i, j, k;
		sort(nums.begin(), nums.end());
		for(i=0; i<nums.size(); i++) {
			j=0; k=nums.size()-1;
			while(j<i && i<k) {
				if(abs(target-(nums[i]+nums[j]+nums[k])) < dist) { answer = nums[i]+nums[j]+nums[k]; dist = abs(target-(nums[i]+nums[j]+nums[k])); }
				if(nums[i]+nums[j]+nums[k] == target) return target;
				else if(nums[i]+nums[j]+nums[k] < target) j++;
				else k--;
			}
		}
		return answer;
	}
};