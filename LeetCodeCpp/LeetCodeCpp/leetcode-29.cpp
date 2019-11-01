#include<iostream>
using namespace std;

class Solution {
public:
	//������λ�����������
	int divide(int dividend, int divisor) {
		//����߽������ǰ����Ϊ���еĽ���ľ���ֵ���INT_MAX�����
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
		//��ֹdividendתΪ����ʱ���
		if (dividend == INT_MIN) {
			dividend += abs(divisor); result++;
		}
		//��dividend��divisorתΪ��������ǽ��������
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