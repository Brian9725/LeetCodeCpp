#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
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

	//KMP算法
	int strStr(string haystack, string needle) {
		int lenH = haystack.size(), lenN = needle.size();
		if (lenN == 0)
			return 0;
		if (lenH < lenN)
			return -1;
		int result = -1, i = 0, j = 0;
		vector<int> next = getNext(needle);
		while (i < lenH && j < lenN) {
			if (j == -1 || haystack[i] == needle[j]) {
				i++; j++;
			}
			else {
				j = next[j];
			}
		}
		if (j == lenN)
			result = i - j;
		return result;
	}
};