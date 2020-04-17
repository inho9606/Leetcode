// https://leetcode.com/problems/maximum-average-subarray-i/submissions/
// I. Get the first continuous subarray with k length
// II. Subtract the first element of the subaaray from the array, and add the next element.
// time: O(n) space: O(1)
// Runtime: 172 ms, faster than 76.90% of C++ online submissions for Maximum Average Subarray I.
// Memory Usage: 14.6 MB, less than 100.00% of C++ online submissions for Maximum Average Subarray I.
class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double avg, answer;
		int sum=0, i;
		for(i=0; i<k; i++)
			sum += nums[i];
		answer = (double)sum/k;
		for(i=i; i<nums.size(); i++) {
			sum -= nums[i-k];
			sum += nums[i];
			avg = (double)sum/k;
			if(avg > answer) answer = avg;
		}
		return answer;
	}
};