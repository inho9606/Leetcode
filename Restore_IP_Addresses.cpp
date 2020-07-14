// https://leetcode.com/problems/restore-ip-addresses/submissions/
// I. From the first in the given string s, read one through three numbers.
// II. Convert the string to integer, and check if it is over 255 or zero. If so, it should be stopped because ip address cannot have numbers greater than 255 and numbers leading zero except 0.
// III. Add substring to the IP address for valid part of address, and move pointer to read next part.
// IV. For all IP Addresses, remove the last character, ".".
// time: O(n) space: O(n)
// Runtime: 4 ms, faster than 78.69% of C++ online submissions for Restore IP Addresses.
// Memory Usage: 6.5 MB, less than 93.95% of C++ online submissions for Restore IP Addresses.
class Solution {
public:
	void restore(vector<string>& result, string& s, int i, int num, string ip) {
		if(num == 4) {
			if(i == s.size()) result.push_back(ip);
			return;
		}
		if(i >= s.size()) return;
		int t=0;
		for(int j=i; j<s.size() && j<i+3; j++) {
			t *= 10;
			t += (s[j] -48);
			if(t > 255) break;
			restore(result, s, j+1, num+1, ip + s.substr(i, j-i+1) + ".");
			if(t==0 && s[j] == 48) break;
		}
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> answer;
		restore(answer, s, 0, 0, "");
		for(int i=0; i<answer.size(); i++)
			answer[i].pop_back();
		return answer;
	}
};