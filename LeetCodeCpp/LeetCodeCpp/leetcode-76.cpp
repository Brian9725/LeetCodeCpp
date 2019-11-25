#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int lenS = s.size(), lenT = t.size();
		int cnt[256] = { 0 };
		//统计出t中每个字符的数量
		for (int i = 0; i < lenT; i++) {
			cnt[t[i]]++;
		}
		int len = 0, minLength = s.size();
		string res = "";
		for (int left = 0, right = 0; right < s.size(); right++) {
			cnt[s[right]]--;
			//如果cnt[s[right]]>=0，说明s[right]在t中，len表示s[left..right]中含有的t中字符的个数
			if (cnt[s[right]] >= 0) {
				len++;
			}
			//len==lenT时说明s[left..right]中已经包含了所有t中的字符，尝试去掉一些字符
			while (len == lenT) {
				if (right - left + 1 <= minLength) {
					minLength = right - left + 1;
					res = s.substr(left, right - left + 1);
				}
				cnt[s[left]]++;
				if (cnt[s[left]] > 0) {
					len--;
				}
				left++;
			}
		}
		return res;
	}
};