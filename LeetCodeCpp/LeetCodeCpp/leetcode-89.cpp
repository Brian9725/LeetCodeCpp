#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	/*Ê¾Àý£º
		000
		001
		011
		010
		 
		110
		111
		101
		100
	*/
	vector<int> grayCode(int n) {
		vector<int> result;
		if (n == 0) {
			result.push_back(0);
			return result;
		}
		result.push_back(0);
		result.push_back(1);
		if (n == 1) 
			return result;
		for (int i = 1; i<n; i++) {
			int len = result.size(), num = 1 << i;
			for (int j = len - 1; j >= 0; j--)
				result.push_back(result[j] + num);
		}
		return result;
	}
};