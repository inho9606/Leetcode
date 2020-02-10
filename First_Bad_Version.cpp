// https://leetcode.com/problems/first-bad-version/submissions/
// Binary Search solution. Divide n by 2 until the one is not a bad product. And Check the next half of the normal product between limited areas..
// time: O(logn) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
// Memory Usage: 8.2 MB, less than 66.67% of C++ online submissions for First Bad Version.

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		long long first=1, last=n, mid;
		while(first <= last) {
			mid = (first+last)/2;
			if(isBadVersion(mid) == 1) {
				if(mid == 1 || isBadVersion(mid-1) == 0) break;
				else last = mid-1;
			}
			else first = mid+1;
		}
		return mid;
	}
};