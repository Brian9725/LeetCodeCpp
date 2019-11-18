#include<iostream>
using namespace std;

class Solution {
public:
	int computeHappy(int n) {
		int res = 0;
		while (n) {
			res += (n % 10)*(n % 10);
			n /= 10;
		}
		return res;
	}

	bool isHappy(int n) {
		//����Ƿ�ѭ��������ʹ�ÿ���ָ�룬�������ܲ���Ȧ
		int temp1 = computeHappy(n), temp2 = computeHappy(computeHappy(n));
		while (1) {
			if (temp1 == 1)
				return true;
			if (temp1 == temp2)
				return false;
			temp1 = computeHappy(temp1);
			temp2 = computeHappy(computeHappy(temp2));
		}
		return true;
	}
};