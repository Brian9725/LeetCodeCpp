#include<iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		//int�ķ�Χ������10λ������ʹ��һ��������Ա�������λ���ϵ�����
		int num[10], cnt = 0;
		if (x < 0)
			return false;
		while (x) {
			num[cnt++] = x % 10;
			x /= 10;
		}
		for (int i = 0; i < cnt / 2; i++)
			if (num[i] != num[cnt - 1 - i])
				return false;
		return true;
	}
};