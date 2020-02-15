// https://leetcode.com/problems/intersection-of-two-arrays/submissions/
// using two sets.
// time: O(nlogn) space: O(n)
// Runtime: 8 ms, faster than 77.56% of C++ online submissions for Intersection of Two Arrays.
// Memory Usage: 9.8 MB, less than 10.00% of C++ online submissions for Intersection of Two Arrays.

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> answer;
		set<int> a, b;
		for(int i=0; i<nums1.size(); i++)
			a.insert(nums1[i]);
		for(int i=0; i<nums2.size(); i++)
			b.insert(nums2[i]);
		if(a.size() < b.size()) {
			for(set<int>::iterator it=a.begin(); it != a.end(); it++) {
				if(b.count(*it) == 1)
					answer.push_back(*it);
			}
		}
		else {
			for(set<int>::iterator it=b.begin(); it != b.end(); it++) {
				if(a.count(*it) == 1)
					answer.push_back(*it);
			}
		}
		return answer;
	}
};