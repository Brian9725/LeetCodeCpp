#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int len = s.size(), head = 0, tail = len - 1;
		while (head < tail) {
			while (head < len && !(s[head] >= '0' && s[head] <= '9') && !(s[head] >= 'A' && s[head] <= 'Z') && !(s[head] >= 'a' && s[head] <= 'z')) 
				head++;
			//防止下标出界
			if (head == len)
				break;
			if (s[head] >= 'a' && s[head] <= 'z') 
				s[head] -= 32;
			while (tail > 0 && !(s[tail] >= '0' && s[tail] <= '9') && !(s[tail] >= 'A' && s[tail] <= 'Z') && !(s[tail] >= 'a' && s[tail] <= 'z')) 
				tail--;
			//防止下标出界
			if (tail == 0)
				break;
			if (s[tail] >= 'a' && s[tail] <= 'z') 
				s[tail] -= 32;
			if (head >= tail)
				break;
			if (s[head] != s[tail])
				return false;
			head++; tail--;
		}
		return true;
	}
};