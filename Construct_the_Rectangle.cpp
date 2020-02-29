// https://leetcode.com/problems/construct-the-rectangle/submissions/
// I. Get square root of area.
// II. From the root, find the closest number that can be divided by area. We should find the less number than the rootnumber because usually the bigger number from root than can be dividied is father than the smaller one. (i.e. area=23, root of area = 4...., distance from root = 23-4 = 19, 4-1=3)
// III. The first element should be the larger than the other one.
// time: O(logn) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Construct the Rectangle.
// Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Construct the Rectangle.

class Solution {
public:
	vector<int> constructRectangle(int area) {
		vector<int> answer(2);
		int i;
		for(i=sqrt(area); area%i != 0; i--) ;
		answer[0] = area/i;
		answer[1] = i;
		return answer;
	}
};