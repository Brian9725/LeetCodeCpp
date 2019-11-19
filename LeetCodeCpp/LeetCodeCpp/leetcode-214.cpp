#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//求needle的next数组
	vector<int> getNext(string needle) {
		vector<int> next;
		int len = needle.size();
		if (len == 0)
			return next;
		next.push_back(-1);
		int j = 1, k = next[0];
		while (j < len) {
			if (k == -1 || needle[j - 1] == needle[k]) {
				j++; k++;
				//将next[j-1]设置为k，因为上一步中将j++，此时j-1才是正确的下标
				next.push_back(k);
			}
			else {
				//最坏情况下(如aaab)，算法时间复杂度为O(n*n)
				k = next[k];
			}
		}
		return next;
	}

	//找到起始处的最大回文串，将其后面的字符逆序加到s前面即可
	string shortestPalindrome(string s) {
		int len = s.size();
		if (len < 2)
			return s;
		string rev = "";
		for (int i = len - 1; i >= 0; i--)
			rev += s[i];
		int i = 0, j = 0;
		vector<int> next = getNext(s);
		while (i < len && j < len) {
			if (j == -1 || rev[i] == s[j]) {
				i++; j++;
			}
			else {
				j = next[j];
			}
		}
		//用s去匹配rev，最后一次能匹配到的位置就是开头处的最大回文串长度
		if (j == len)
			return s;
		string result = "";
		for (int i = len - 1; i >= j; i--)
			result += s[i];
		result += s;
		return result;
	}
};