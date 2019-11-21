#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	struct cmp {
		bool operator()(int&x, int&y) {
			return y < x;
		}
	};

	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end(), cmp());
		int result = 0;
		for (int i = 1; i <= (int)citations.size(); i++) {
			if (citations[i - 1] >= i)
				result = i;
			else
				break;
		}
		return result;
	}
};