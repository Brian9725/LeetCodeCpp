#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		int len = A.size(), idx0 = 0, idx1 = 1;
		vector<int> result(len, 0);
		for (int i = 0; i < len; i++) {
			if (A[i] % 2 == 0) {
				result[idx0] = A[i];
				idx0 += 2;
			}
			else {
				result[idx1] = A[i];
				idx1 += 2;
			}
		}
		return result;
	}
};