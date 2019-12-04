#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//判断x是否为自除数
	bool isSelfDiv(int x) {
		int num = x;
		while (num) {
			int temp = num % 10;
			if (temp == 0 || x%temp != 0) return false;
			num /= 10;
		}
		return true;
	}

	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;
		for (int i = left; i <= right; ++i) {
			if (isSelfDiv(i)) res.push_back(i);
		}
		return res;
	}
};