#include<iostream>
using namespace std;

class Solution {
public:
	double dfsPow(double x, int n) {
		if (n == 1)
			return x;
		double temp = dfsPow(x, n / 2);
		if (n % 2 == 0)
			return temp*temp;
		return temp*temp*x;
	}

	double myPow(double x, int n) {
		if (n == 0)
			return 1.0;
		else if (n == 1)
			return x;
		else if (n == INT_MIN)
			return 1 / (x*dfsPow(x, INT_MAX));
		//flag标记n的正负
		int flag = 1;
		if (n < 0) {
			flag = 0; n = -n;
		}
		if (flag)
			return dfsPow(x, n);
		return 1 / dfsPow(x, n);
	}
};