#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	//"96 e5"���Ϸ������Ϸ�����ֻ����β���Դ��ڿո�
	bool isNumber(string s) {
		int len = s.size(), idx = 0;
		//�����ײ��ո�
		while (idx < len && s[idx] == ' ') {
			idx++;
		}
		if (s[idx] == '+' || s[idx] == '-')
			idx++;
		//ͳ�����ָ�����С�������
		int numP = 0, numN = 0;
		while (idx < len) {
			if (s[idx] == '.') {
				numP++; idx++;
			}
			else if (s[idx] >= '0' && s[idx] <= '9') {
				numN++; idx++;
			}
			else
				break;
		}
		if (numP > 1 || numN < 1)
			return false;
		if (s[idx] == 'e') {
			idx++;
			if (s[idx] == '+' || s[idx] == '-')
				idx++;
			//ͳ�����ָ���
			numN = 0;
			while (idx < len) {
				if (s[idx] >= '0' && s[idx] <= '9') {
					numN++; idx++;
				}
				else
					break;
			}
			if (numN < 1)
				return false;
		}
		//����β���ո�
		while (idx < len && s[idx] == ' ') {
			idx++;
		}
		if (idx == len)
			return true;
		else
			return false;
	}
};