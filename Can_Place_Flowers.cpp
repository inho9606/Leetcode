// https://leetcode.com/problems/can-place-flowers/submissions/
// Brute Force Solution
// time: O(n) space: O(1)
// Runtime: 12 ms, faster than 96.44% of C++ online submissions for Can Place Flowers.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Can Place Flowers.
class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int i;
		for(i=0; i<flowerbed.size() && n>0; i++) {
			if(i==0) {
				if(i==flowerbed.size()-1 && flowerbed[i] == 0) n--;
				else if(i==flowerbed.size()-1 && flowerbed[i] == 1) continue;
				else if(flowerbed[i] == 0 && flowerbed[i+1] == 0) {
					n -=1;
					flowerbed[i] = 1;
				}
			}
			else if(i==flowerbed.size()-1) {
				if(flowerbed[i-1] == 0 && flowerbed[i] == 0) {
					n -=1;
					flowerbed[i] = 1;
				}
			}
			else {
				if(flowerbed[i+1] == 0 && flowerbed[i-1] == 0 && flowerbed[i] == 0) {
					n--;
					flowerbed[i] = 1;
				}
			}
		}
		if(n>0) return 0;
		return 1;
	}
};