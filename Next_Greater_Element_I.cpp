// https://leetcode.com/problems/next-greater-element-i/submissions/
// I. Find the num1's number in nums2.
// II. From the number in nums2, find the greater number.
// time: O(n^2), space: O(1)
// Runtime: 8 ms, faster than 98.19% of C++ online submissions for Next Greater Element I.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Next Greater Element I.
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> answer(nums1.size());
		int j=0;
		for(int i=0; i<nums1.size(); i++) {
			for(j=0; j<nums2.size(); j++) {
				if(nums2[j] == nums1[i]) break;
			}
			for(; j<nums2.size(); j++) {
				if(nums2[j] > nums1[i]) {
					answer[i] = nums2[j];
					break;
				}
				else if(j==nums2.size()-1) answer[i] = -1;
			}
		}
		return answer;
	}
};