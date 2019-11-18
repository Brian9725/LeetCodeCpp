#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	//求最大公约数
	long computeGCD(long a, long b) {
		while (b != 0) {
			int temp = a % b; a = b; b = temp;
		}
		return a;
	}

	//计算斜率，外部逻辑保证point1和point2不重合
	string computeK(vector<int>& point1, vector<int>& point2) {
		long x1 = point1[0], y1 = point1[1];
		long x2 = point2[0], y2 = point2[1];
		//单独考虑斜率为0和无穷的情况
		if (x1 == x2)
			return "1/0";
		if (y1 == y2)
			return "0/1";
		long x = x2 - x1, y = y2 - y1, gcd = computeGCD(x, y);
		x /= gcd; y /= gcd;
		return to_string(y) + "/" + to_string(x);
	}

	int maxPoints(vector<vector<int>>& points) {
		int len = points.size();
		if (len < 3)
			return len;
		int res = 2; map<string, int> lineMap;
		//直线上的第一个点只有len种可能
		for (int i = 0; i < len; i++) {
			int tempRes = 1, samePoints = 0; lineMap.clear();
			for (int j = i + 1; j < len; j++) {
				//如果遇到和points[i]重合的点，其必然在该条直线上
				if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
					samePoints++; continue;
				}
				//直线的点斜式方程只需斜率K和一点points[i]即可确定
				string K = computeK(points[i], points[j]);
				if (lineMap.find(K) == lineMap.end()) {
					lineMap[K] = 2;
					tempRes = max(tempRes, 2);
				}
				else {
					lineMap[K]++;
					tempRes = max(tempRes, lineMap[K]);
				}
			}
			res = max(res, tempRes + samePoints);
		}
		return res;
	}
};

int main() {
	vector<vector<int>> points;
	vector<int> p1; p1.push_back(0); p1.push_back(0); points.push_back(p1);
	vector<int> p2; p2.push_back(1); p2.push_back(1); points.push_back(p2);
	vector<int> p3; p3.push_back(0); p3.push_back(0); points.push_back(p3);
	cout << Solution().maxPoints(points);
}