#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int nums1Size = nums1.size(), nums2Size = nums2.size();
		//�����һ������Ϊ�գ�ֱ�ӷ�����һ���������λ��
		if (nums2Size == 0) {
			nums2Size = nums1Size; nums2 = nums1; nums1Size = 0;
		}
		if (nums1Size == 0) {
			if (nums2Size % 2 == 1)
				return nums2[nums2Size / 2];
			return (nums2[nums2Size / 2] + nums2[nums2Size / 2 - 1]) / 2.0;
		}
		//�����һ�����鳤��Ϊ1
		if (nums1Size == 1 || nums2Size == 1) {
			if (nums1Size == 1) {
				//����������鳤�Ⱦ�Ϊ1����������Ԫ�ص�ƽ��������
				if (nums2Size == 1)
					return (nums1[0] + nums2[0]) / 2.0;
				//����nums1��nums2��ʹ�ó���Ϊ1��������nums2
				vector<int> nums3 = nums1; nums1 = nums2; nums2 = nums3;
				int tmp = nums1Size; nums1Size = nums2Size; nums2Size = tmp;
			}
			//���nums1����Ϊ���������ܳ���Ϊż��
			if (nums1Size % 2 == 1) {
				if (nums2[0] <= nums1[nums1Size / 2 - 1])
					return (nums1[nums1Size / 2] + nums1[nums1Size / 2 - 1]) / 2.0;
				else if (nums2[0] >= nums1[nums1Size / 2 + 1])
					return (nums1[nums1Size / 2] + nums1[nums1Size / 2 + 1]) / 2.0;
				else
					return (nums1[nums1Size / 2] + nums2[0]) / 2.0;
			}
			//���nums1����Ϊż�������ܳ���Ϊ����
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
			//temp1��temp2��ʾnum1��num2����ȥ���ĳ���
			int temp1 = 0, temp2 = 0, len1 = tail1 - head1 + 1, len2 = tail2 - head2 + 1;
			//mid1Ϊnums1[head1,tail1]����λ����mid2Ϊnums2[head2,tail2]����λ��
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
			//���nums1[head1,tail1]����λ����nums2[head2,tail2]����ȣ�����Ҳ��Ȼ����������Ĺ�����λ��
			if (mid1 == mid2)
				return mid1;
			//ֻ��ȥ����С���Ǹ�����
			if (temp2 < temp1)
				temp1 = temp2;
			if (mid1 > mid2) {
				tail1 -= temp1; head2 += temp1;
			}
			else {
				head1 += temp1; tail2 -= temp1;
			}
		}
		//��ʱ��������һ������ֻʣ������Ԫ��
		if (tail1 - head1 == 1) {
			//����������鶼ֻʣ������Ԫ��
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
			//���ֻ��num1ʣ������Ԫ�أ����佻������ʱ��head1����tail1-1��ʾ
			vector<int> nums3 = nums1; nums1 = nums2; nums2 = nums3;
			head1 = head2; head2 = tail1 - 1;
			tail1 = tail2; tail2 = head2 + 1;
		}
		//��ʱnum1Ԫ�ظ�������2��num2Ԫ�ظ�������2
		int len = tail1 - head1 + 1;
		//���nums1����Ϊ���������ܳ���Ϊ����
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
		//���nums1����Ϊż�������ܳ���Ϊż��
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