#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		vector<int> num(citations.size() + 1, 0);
		for (int i = 0; i < citations.size(); i++) {
			if (citations[i] > citations.size())
				citations[i] = citations.size();
			num[citations[i]]++;
		}
		int result = 0;
		for (int i = citations.size(); i >= 0; i--) {
			if (num[i] + result < i)
				result += num[i];
			else
				return i;
		}
		return 0;
	}

	/*ÅÅÐò
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
	*/
};