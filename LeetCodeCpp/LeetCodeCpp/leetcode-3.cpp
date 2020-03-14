#include<iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		/*
		kΪ��ʶ������ʶ��i���ַ��Ƿ���s[i-2-num,i-1]�г��ֹ�
		numΪ�Ե�ǰ�ַ���β��������ظ��Ӵ��ĳ���
		*/
		int k, result = 0, num, len = s.size();
		for (int i = 0; i < len; i++) {
			k = 0;
			if (i == 0) {
				result = num = 1;
				continue;
			}
			for (int j = i - 1; j > i - 1 - num; j--) {
				//�����i���ַ����ֹ��������numֵ
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
			//�����i���ַ��Ƿ���s[i-2-num,i-1]��û���ֹ����num��1
			num++;
			if (num > result) 
				result = num;
		}
		return result;
	}

	/*��һ�ַ���
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) return 0;
		//a[x]��ʾx�����ֵ�λ��
		int a[128] = { -1 };
		for (int i = 0; i < 128; i++) a[i] = -1;
		//max��ʾ��ǰ���ֵ��curr��ʾ�Ե�i���ַ���β������Ӵ���ʼλ�ã�
		int max = 0, curr = 0, len = s.size();
		for (int i = 0; i < len; i++) {
			//��s[i]��curr֮����ֹ�ʱ���ִ�λ������Ϊ��ǰ�ַ����ֵ����λ��
			if (a[s[i]] >= curr) curr = a[s[i]] + 1;
			if (i - curr + 1> max) max = i - curr + 1;
			a[s[i]] = i;
		}
		return max;
	}
	*/
};