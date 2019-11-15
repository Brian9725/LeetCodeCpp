#include<iostream>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		while (num / 10 != 0) {
			int temp = num, sum = 0;
			while (temp != 0) {
				sum += temp % 10;
				temp /= 10;
			}
			num = sum;
		}
		return num;
	}
};