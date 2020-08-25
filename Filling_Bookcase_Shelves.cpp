// https://leetcode.com/problems/filling-bookcase-shelves/submissions/
// I. Initialize dp array, which means the sum of shelves' hight.
// II. The new shelf's hight is the sum of previous total shelf hight + current shelf hight. ;;
// i권의 책이 있을 때 처음에는 i개의 선반이 있다고 가정한다. 그리고 dp[i]가 의미하는 것은 i번째 책을 선반에 꽂았을 때 선반 높이의 합이다. 즉, 초기 dp는 모든 책의 높이 합이다.
// i번째 책 높이를 결정할 때, i번째의 책부터 i-1, i-2, ...의 방향으로 책을 한 권씩 합친다. 즉, 높이는 i번째 책, i-1번째 책,... 의 책 중 가장 큰 높이의 책이 된다. 책을 몇 권 선택할지는 책의 가로 길이인 books[i][0] 의 합이 shelf_width 보다 작을 때까지이다. 가로의 길이가 주어진 제한 범위를 초과하면 그 묶음이 선반 하나가 되고, dp에서 해당 선반의 높이는 이전 선반의 높이 합 + 현재 선반의 높이가 된다.
// time: O(n^2) space: O(n)
// Runtime: 8 ms, faster than 97.19% of C++ online submissions for Filling Bookcase Shelves.
// Memory Usage: 8.3 MB, less than 75.34% of C++ online submissions for Filling Bookcase Shelves.
class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
		int w, h;
		vector<int> dp(books.size()+1);
		dp[0] = 0;
		for(int i=0; i<books.size(); i++) {
			dp[i+1] = dp[i]+books[i][1];
			w = 0; h = 0;
			for(int j=i; j>=0; j--) {
				w += books[j][0];
				if(w<=shelf_width) {
					if(books[j][1] > h) h = books[j][1];
					if(dp[j]+h < dp[i+1]) dp[i+1] = dp[j]+h;
				}
				else break;
			}
		}
		return dp[books.size()];
	}
};