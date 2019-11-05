#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		long long result = 0, left = 0, right = 0, val = 0, base = 1;
		while (n > 0) {
			/*
			若n=213，十位数=1，出现1的次数为：2pow(10,1)+3+1=24次
			若n=203，十位数<1，出现1的次数为：2pow(10,1)=20次
			若n=253，十位数>1，出现1的次数为：(2+1)*pow(10,1)=30次
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