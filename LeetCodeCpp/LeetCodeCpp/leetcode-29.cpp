#include<iostream>
using namespace std;

class Solution {
public:
	//采用移位减法代替除法
	int divide(int dividend, int divisor) {
		//处理边界情况，前两个为仅有的结果的绝对值溢出INT_MAX的情况
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		if (dividend == INT_MIN && divisor == 1)
			return INT_MIN;
		if (divisor == INT_MIN) {
			if (dividend == INT_MIN)
				return 1;
			else
				return 0;
		}
		int result = 0;
		bool isP = true;
		//防止dividend转为正数时溢出
		if (dividend == INT_MIN) {
			dividend += abs(divisor); result++;
		}
		//将dividend和divisor转为正数并标记结果的正负
		if (dividend <= 0) {
			dividend = -dividend; isP = !isP;
		}
		if (divisor < 0) {
			divisor = -divisor; isP = !isP;
		}
		for (int i = 31; i >= 0; i--) {
			if ((dividend >> i) >= divisor) {
				result += 1 << i;
				dividend -= divisor << i;
			}
		}
		return isP ? result : -result;
	}
};