#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		int res = 0;
		vector<bool> flag(n, true);
		for (int i = 2; i < n; ++i) {
			if (flag[i]) {
				res++;
				for (int j = 2 * i; j < n; j += i) 
					flag[j] = false;
			}
		}
		return res;
	}
};