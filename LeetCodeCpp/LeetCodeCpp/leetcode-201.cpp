#include<iostream>
using namespace std;

class Solution {
public:
	//计算x二进制表示中最高位的1
	int cmp(int x) {
		if (x == 0) return -1;
		int res = 30;
		while (x) {
			int temp = 1 << res;
			if (x / temp != 0) return res;
			x %= temp; res--;
		}
		return res;
	}

	int rangeBitwiseAnd(int m, int n) {
		int res = 0, tempM = cmp(m), tempN = cmp(n);
		while (tempM == tempN && tempM != -1) {
			res += 1 << tempM;
			m %= 1 << tempM; n %= 1 << tempN;
			tempM = cmp(m); tempN = cmp(n);
		}
		return res;
	}
};