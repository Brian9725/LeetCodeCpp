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
				//��next[j-1]����Ϊk����Ϊ��һ���н�j++����ʱj-1������ȷ���±�
				next.push_back(k);
			}
			else {
				//������(��aaab)���㷨ʱ�临�Ӷ�ΪO(n*n)
				k = next[k];
			}
		}
		return next;
	}

	//KMP�㷨
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