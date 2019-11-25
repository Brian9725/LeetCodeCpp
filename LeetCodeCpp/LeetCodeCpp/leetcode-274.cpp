#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int len = citations.size();
		//num[i]表示引用次数为i的文章有几篇，大于n的按n处理
		vector<int> num(len + 1, 0);
		for (int i = 0; i < len; i++) {
			if (citations[i] > len)
				citations[i] = len;
			num[citations[i]]++;
		}
		int result = 0;
		for (int i = len; i >= 0; i--) {
			if (num[i] + result < i)
				result += num[i];
			else
				return i;
		}
		return 0;
	}

	/*排序
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