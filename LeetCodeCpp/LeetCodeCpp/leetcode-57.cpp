#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		if (newInterval.size() == 0)
			return intervals;
		vector<vector<int>> result;
		if (intervals.size() == 0) {
			result.push_back(newInterval);
			return result;
		}
		//startIdx表示最后一个终点小于newInterval[0]的区间下标，endIdx表示第一个起点大于newInterval[1]的区间下标
		int len = intervals.size(), low = 0, high = len - 1, startIdx = 0, endIdx = 0;
		//二分查找startIdx
		while (low <= high) {
			startIdx = low + (high - low) / 2;
			if (intervals[startIdx][1] < newInterval[0])
				low = startIdx + 1;
			else
				high = startIdx - 1;
		}
		if (intervals[startIdx][1] >= newInterval[0])
			startIdx--;
		//二分查找endIdx
		low = 0; high = len - 1;
		while (low <= high) {
			endIdx = low + (high - low) / 2;
			if (intervals[endIdx][0] > newInterval[1])
				high = endIdx - 1;
			else
				low = endIdx + 1;
		}
		if (intervals[endIdx][0] <= newInterval[1])
			endIdx++;
		//将所有终点小于newInterval[0]的区间加入result
		for (int i = 0; i <= startIdx; i++)
			result.push_back(intervals[i]);
		//将中间的区间合并起来
		vector<int> tempRes;
		if (startIdx < len - 1)
			tempRes.push_back(min(intervals[startIdx + 1][0], newInterval[0]));
		else
			tempRes.push_back(newInterval[0]);
		if (endIdx > 0)
			tempRes.push_back(max(intervals[endIdx - 1][1], newInterval[1]));
		else
			tempRes.push_back(newInterval[1]);
		result.push_back(tempRes);
		//将所有起点大于newInterval[1]的区间加入result
		for (int i = endIdx; i < len; i++)
			result.push_back(intervals[i]);
		return result;
	}
};