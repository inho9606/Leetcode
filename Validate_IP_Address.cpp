// https://leetcode.com/problems/validate-ip-address/submissions/
// Just Brute Force..
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Validate IP Address.
// Memory Usage: 6.2 MB, less than 96.83% of C++ online submissions for Validate IP Address.
class Solution {
public:
	bool is_ipv4(string ip) {
		int n=0, dots=0;
		for(int i=0; i<ip.size(); i++) {
			if(ip[i] >= '0' && ip[i] <= '9') {
				if(n==0 && i>0 && ip[i-1] == '0') return 0;
				n *= 10;
				n += ip[i]-48;
				if(n>255) return 0;
			}
			else if(ip[i] == '.') {
				dots += 1;
				if(i==0 || i == ip.size()-1 || ip[i-1] == '.' || dots>3) return 0;
				n=0;
			}
			else return 0;
		}
		if(dots<3) return 0;
		return 1;
	}
	bool is_ipv6(string ip) {
		int b=0, c=0;
		for(int i=0; i<ip.size(); i++) {
			if(ip[i] == ':') {
				c += 1;
				if(i==0 || i == ip.size()-1 || ip[i-1] == ':' || c > 7) return 0;
				b = 0;
			}
			else if((ip[i] >= '0' && ip[i] <= '9') || (ip[i] >= 'a' && ip[i] <= 'f') || (ip[i] >= 'A' && ip[i] <= 'F')) {
				b += 1;
				if(b>4) return 0;
			}
			else return 0;
		}
		if(c<7) return 0;
		return 1;
	}
	string validIPAddress(string IP) {
		if(is_ipv4(IP) == 1) return "IPv4";
		if(is_ipv6(IP) == 1) return "IPv6";
		return "Neither";
	}
};