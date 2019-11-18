#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	//"96 e5"不合法，即合法数字只有首尾可以存在空格
	bool isNumber(string s) {
		int len = s.size(), idx = 0;
		//跳过首部空格
		while (idx < len && s[idx] == ' ') {
			idx++;
		}
		if (s[idx] == '+' || s[idx] == '-')
			idx++;
		//统计数字个数和小数点个数
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
			//统计数字个数
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
		//跳过尾部空格
		while (idx < len && s[idx] == ' ') {
			idx++;
		}
		if (idx == len)
			return true;
		else
			return false;
	}
};