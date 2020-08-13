// https://leetcode.com/problems/divisor-game/submissions/
// I. Basically Think about if I can win or not with given N.
// II. When N == 1, I lose. N==2: win, N==3: lose, N==4: win, N==5: lose, N==6:w win... which means if I got the even number, then I win. Or I lose.
// III. It's possible since We can make odd number by subtracting 1 from even number, and there are only odd numbers that can be divided from odd number. That's why making odd number is key to win.
// time: O(1) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divisor Game.
// Memory Usage: 5.9 MB, less than 76.14% of C++ online submissions for Divisor Game.
class Solution {
public:
	bool divisorGame(int N) {
		if(N%2 == 0) return 1;
		return 0;
	}
};

/* DP solution from most voted on discuss board
class Solution {
public:
int dp[1001] = {};
bool divisorGame(int N, bool res = false) {
if (dp[N] != 0) return dp[N] == 1;
for (auto i = 1; !res && i <= N / 2; ++i) {
if (N % i == 0) res = !divisorGame(N - i);
}
dp[N] = res ? 1 : -1;
return res;
}
};
*/