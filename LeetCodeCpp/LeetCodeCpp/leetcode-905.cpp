#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int len = A.size(), head = 0, tail = len - 1;
		vector<int> result(len, 0);
		for (int i = 0; i < len; i++) {
			if (A[i] % 2 == 0)
				result[head++] = A[i];
			else
				result[tail--] = A[i];
		}
		return result;
	}
};