// https://leetcode.com/problems/bulls-and-cows/submissions/
// Count numbers in guess and secret from zero to nine. Plus one to match if the value and index of guess and secret, otherwise count the number of each containers. And plus the more less disappeared one between guess and secret on the same number.
// time: O(n) space: O(1)
// Runtime: 4 ms, faster than 93.32% of C++ online submissions for Bulls and Cows.
// Memory Usage: 9 MB, less than 76.92% of C++ online submissions for Bulls and Cows.


class Solution {
public:
	string getHint(string secret, string guess) {
		string answer;
		int match=0, again=0;
		vector<int> secret_count(10, 0), guess_count(10, 0);
		for(int i=0; i<guess.size(); i++) {
			if(guess[i] == secret[i]) match++;
			else {
				secret_count[secret[i]-48] += 1;
				guess_count[guess[i]-48] += 1;
			}
		}
		for(int i=0; i<10; i++) {
			if(secret_count[i] - guess_count[i] < 0) again += secret_count[i];
			else again += guess_count[i];
		}
		answer = to_string(match) + "A" + to_string(again) + "B";
		return answer;
	}
};

/** O(n^2) solution with brute forth
class Solution {
public:
	string getHint(string secret, string guess) {
	string answer = "";
		int match=0, again=0;
		for(int i=0; i<guess.size(); i++) {
			if(guess[i] == secret[i]) {
				match += 1;
				guess[i] = ' ';
				secret[i] = ' ';
			}
		}
		for(int i=0; i<guess.size(); i++) {
			for(int j=0; j<secret.size(); j++) {
				if(guess[i] == secret[j] && guess[i] != ' ') {
					again += 1;
					guess[i] = ' ';
					secret[j] = ' ';
					break;
				}
			}
		}
		answer = to_string(match) + "A" + to_string(again) + "B";
		return answer;
	}
};
**/