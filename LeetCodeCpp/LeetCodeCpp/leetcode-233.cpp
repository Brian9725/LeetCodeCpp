#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		long long result = 0, left = 0, right = 0, val = 0, base = 1;
		while (n > 0) {
			/*
			��n=213��ʮλ��=1������1�Ĵ���Ϊ��2pow(10,1)+3+1=24��
			��n=203��ʮλ��<1������1�Ĵ���Ϊ��2pow(10,1)=20��
			��n=253��ʮλ��>1������1�Ĵ���Ϊ��(2+1)*pow(10,1)=30��
			*/
			left = n / 10;
			right += val * base / 10;
			val = n % 10;
			if (val == 1) 
				result += left * base + right + 1;
			else if (val > 1) 
				result += (left + 1) * base;
			else
				result += left * base;
			base *= 10; n = left;
		}
		return result;
	}
};