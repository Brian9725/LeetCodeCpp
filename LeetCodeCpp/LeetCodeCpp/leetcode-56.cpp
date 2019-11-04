#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	static bool cmp(vector<int>&a, vector<int>&b) {
		if (a[0] == b[0])
			return a[1] > b[1];
		return a[0] < b[0];
	}

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int len = intervals.size();
		if (len < 2)
			return intervals;
		//将intervals按起点递增，终点递减排序（VS2015会报错）
		sort(intervals.begin(), intervals.end(), cmp);
		vector<vector<int>> result;
		vector<int> tempRes;
		//tempM为合并后的终点
		int i = 0, tempM = 0;
		while (i < len) {
			tempRes.clear();
			tempRes.push_back(intervals[i][0]);
			tempM = intervals[i][1];
			while (i < len) {
				//如果tempM小于第i个区间的起点，则说明之后的区间无法与之合并
				if (tempM < intervals[i][0])
					break;
				//如果tempM在第i个区间起点和终点之间，则更新tempM的值
				if (tempM < intervals[i][1])
					tempM = intervals[i][1];
				i++;
			}
			tempRes.push_back(tempM);
			result.push_back(tempRes);
		}
		return result;
	}
};