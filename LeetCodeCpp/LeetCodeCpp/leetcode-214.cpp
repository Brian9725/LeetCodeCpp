#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//��needle��next����
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

	//�ҵ���ʼ���������Ĵ������������ַ�����ӵ�sǰ�漴��
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
		//��sȥƥ��rev�����һ����ƥ�䵽��λ�þ��ǿ�ͷ���������Ĵ�����
		if (j == len)
			return s;
		string result = "";
		for (int i = len - 1; i >= j; i--)
			result += s[i];
		result += s;
		return result;
	}
};