#include<iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		/*
		k为标识符，标识第i个字符是否在s[i-2-num,i-1]中出现过
		num为以当前字符结尾的最大无重复子串的长度
		*/
		int k, result = 0, num, len = s.size();
		for (int i = 0; i < len; i++) {
			k = 0;
			if (i == 0) {
				result = num = 1;
				continue;
			}
			for (int j = i - 1; j > i - 1 - num; j--) {
				//如果第i个字符出现过，则更新num值
				if (s[i] == s[j]) {
					num = i - j;
					if (num > result) 
						result = num;
					k = 1;
					break;
				}
			}
			if (k) 
				continue;
			//如果第i个字符是否在s[i-2-num,i-1]中没出现过则加num加1
			num++;
			if (num > result) 
				result = num;
		}
		return result;
	}

	/*另一种方法
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) return 0;
		//a[x]表示x最后出现的位置
		int a[128] = { -1 };
		for (int i = 0; i < 128; i++) a[i] = -1;
		//max表示当前最大值，curr表示以第i个字符结尾的最大子串起始位置，
		int max = 0, curr = 0, len = s.size();
		for (int i = 0; i < len; i++) {
			//当s[i]在curr之后出现过时将字串位置设置为当前字符出现的最后位置
			if (a[s[i]] >= curr) curr = a[s[i]] + 1;
			if (i - curr + 1> max) max = i - curr + 1;
			a[s[i]] = i;
		}
		return max;
	}
	*/
};