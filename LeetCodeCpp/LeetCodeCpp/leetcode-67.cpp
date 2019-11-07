#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		//将长数字分给a，短数字分给b
		if (a.size() < b.size()) {
			string c = a; a = b; b = c;
		}
		int lenA = a.size(), lenB = b.size();
		//flag和tempC表示进位
		bool flag = false;
		int tempA = 0, tempB = 0, tempC = 0, sum = 0;
		for (int i = 1; i <= lenB; i++) {
			//从末尾开始每次选取a和b的一个数字赋给tempA和tempB
			char chA = a[lenA - i];
			char chB = b[lenB - i];
			tempA = (chA == '0') ? 0 : 1;
			tempB = (chB == '0') ? 0 : 1;
			tempC = (flag) ? 1 : 0;
			sum = tempA + tempB + tempC;
			if (sum == 0) {
				a[lenA - i] = '0'; flag = false;
			}
			if (sum == 1) {
				a[lenA - i] = '1'; flag = false;
			}
			if (sum == 2) {
				a[lenA - i] = '0'; flag = true;
			}
			if (sum == 3) {
				a[lenA - i] = '1'; flag = true;
			}
		}
		//处理长度多出来的数
		for (int i = lenB + 1; i <= lenA; i++) {
			char chA = a[lenA - i];
			tempA = (chA == '0') ? 0 : 1;
			tempC = (flag) ? 1 : 0;
			sum = tempA + tempC;
			if (sum == 0) {
				a[lenA - i] = '0'; flag = false;
			}
			if (sum == 1) {
				a[lenA - i] = '1'; flag = false;
			}
			if (sum == 2) {
				a[lenA - i] = '0'; flag = true;
			}
		}
		if (flag) 
			a = "1" + a;
		return a;
	}
};