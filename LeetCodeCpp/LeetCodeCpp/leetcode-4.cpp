#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int nums1Size = nums1.size(), nums2Size = nums2.size();
		//如果有一个数组为空，直接返回另一个数组的中位数
		if (nums2Size == 0) {
			nums2Size = nums1Size; nums2 = nums1; nums1Size = 0;
		}
		if (nums1Size == 0) {
			if (nums2Size % 2 == 1)
				return nums2[nums2Size / 2];
			return (nums2[nums2Size / 2] + nums2[nums2Size / 2 - 1]) / 2.0;
		}
		//如果有一个数组长度为1
		if (nums1Size == 1 || nums2Size == 1) {
			if (nums1Size == 1) {
				//如果两个数组长度均为1，返回两个元素的平均数即可
				if (nums2Size == 1)
					return (nums1[0] + nums2[0]) / 2.0;
				//交换nums1和nums2，使得长度为1的数组是nums2
				vector<int> nums3 = nums1; nums1 = nums2; nums2 = nums3;
				int tmp = nums1Size; nums1Size = nums2Size; nums2Size = tmp;
			}
			//如果nums1长度为奇数，即总长度为偶数
			if (nums1Size % 2 == 1) {
				if (nums2[0] <= nums1[nums1Size / 2 - 1])
					return (nums1[nums1Size / 2] + nums1[nums1Size / 2 - 1]) / 2.0;
				else if (nums2[0] >= nums1[nums1Size / 2 + 1])
					return (nums1[nums1Size / 2] + nums1[nums1Size / 2 + 1]) / 2.0;
				else
					return (nums1[nums1Size / 2] + nums2[0]) / 2.0;
			}
			//如果nums1长度为偶数，即总长度为奇数
			else {
				if (nums2[0] <= nums1[nums1Size / 2 - 1])
					return nums1[nums1Size / 2 - 1];
				else if (nums2[0] >= nums1[nums1Size / 2])
					return nums1[nums1Size / 2];
				else
					return nums2[0];
			}
		}
		int head1 = 0, head2 = 0, tail1 = nums1Size - 1, tail2 = nums2Size - 1;
		while (tail1 - head1 != 1 && tail2 - head2 != 1) {
			//temp1和temp2表示num1和num2可以去掉的长度
			int temp1 = 0, temp2 = 0, len1 = tail1 - head1 + 1, len2 = tail2 - head2 + 1;
			//mid1为nums1[head1,tail1]的中位数，mid2为nums2[head2,tail2]的中位数
			double mid1 = 0, mid2 = 0;
			if (len1 % 2 == 1) {
				mid1 = nums1[len1 / 2 + head1];
				temp1 = len1 / 2;
			}
			else {
				mid1 = (nums1[len1 / 2 + head1] + nums1[len1 / 2 + head1 - 1]) / 2.0;
				temp1 = len1 / 2 - 1;
			}
			if (len2 % 2 == 1) {
				mid2 = nums2[len2 / 2 + head2];
				temp2 = len2 / 2;
			}
			else {
				mid2 = (nums2[len2 / 2 + head2] + nums2[len2 / 2 + head2 - 1]) / 2.0;
				temp2 = len2 / 2 - 1;
			}
			//如果nums1[head1,tail1]的中位数和nums2[head2,tail2]的相等，那其也必然是两个数组的公共中位数
			if (mid1 == mid2)
				return mid1;
			//只能去掉较小的那个长度
			if (temp2 < temp1)
				temp1 = temp2;
			if (mid1 > mid2) {
				tail1 -= temp1; head2 += temp1;
			}
			else {
				head1 += temp1; tail2 -= temp1;
			}
		}
		//此时，至少有一个数组只剩下两个元素
		if (tail1 - head1 == 1) {
			//如果两个数组都只剩下两个元素
			if (tail2 - head2 == 1) {
				int temp1, temp2;
				if (nums1[head1] > nums2[head2])
					temp1 = nums1[head1];
				else
					temp1 = nums2[head2];
				if (nums1[tail1] > nums2[tail2])
					temp2 = nums2[tail2];
				else
					temp2 = nums1[tail1];
				return (temp1 + temp2) / 2.0;
			}
			//如果只是num1剩下两个元素，将其交换；此时，head1可由tail1-1表示
			vector<int> nums3 = nums1; nums1 = nums2; nums2 = nums3;
			head1 = head2; head2 = tail1 - 1;
			tail1 = tail2; tail2 = head2 + 1;
		}
		//此时num1元素个数大于2，num2元素个数等于2
		int len = tail1 - head1 + 1;
		//如果nums1长度为奇数，即总长度为奇数
		if (len % 2 == 1) {
			if (nums2[head2] >= nums1[len / 2 + head1 + 1])
				return nums1[len / 2 + head1 + 1];
			else if (nums2[tail2] <= nums1[len / 2 + head1 - 1])
				return nums1[len / 2 + head1 - 1];
			else if (nums2[tail2] >= nums1[len / 2 + head1 - 1] && nums2[tail2] <= nums1[len / 2 + head1])
				return nums2[tail2];
			else if (nums2[head2] >= nums1[len / 2 + head1] && nums2[head2] <= nums1[len / 2 + head1 + 1])
				return nums2[head2];
			else
				return nums1[len / 2 + head1];
		}
		//如果nums1长度为偶数，即总长度为偶数
		else {
			if (nums2[head2] >= nums1[len / 2 + head1 + 1])
				return (nums1[len / 2 + head1] + nums1[len / 2 + head1 + 1]) / 2.0;
			else if (nums2[tail2] <= nums1[len / 2 + head1 - 2])
				return (nums1[len / 2 + head1 - 2] + nums1[len / 2 + head1 - 1]) / 2.0;
			else if (nums2[head2] <= nums1[len / 2 + head1 - 1] && nums2[tail2] >= nums1[len / 2 + head1])
				return (nums1[len / 2 + head1 - 1] + nums1[len / 2 + head1]) / 2.0;
			else if (nums2[head2] >= nums1[len / 2 + head1 - 1] && nums2[tail2] <= nums1[len / 2 + head1])
				return (nums2[head2] + nums2[tail2]) / 2.0;
			else if (nums2[head2] <= nums1[len / 2 + head1 - 1] && nums2[tail2] >= nums1[len / 2 + head1 - 2] && nums2[tail2] <= nums1[len / 2 + head1])
				return (nums1[len / 2 + head1 - 1] + nums2[tail2]) / 2.0;
			else
				return (nums1[len / 2 + head1] + nums2[head2]) / 2.0;
		}
	}
};