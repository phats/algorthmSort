#include"createRandomArr.h"
#include <iostream>
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void createHeap(vector<int>& nums, int left, int right) {
	int i = left;
	while (2 * i+1 <right) {
		if (nums[i] > nums[2 * i]) {
			swap(nums[i], nums[2 * i]);
			i /= 2;
		}
		else if (nums[i] > nums[2 * i + 1]) {
			swap(nums[i], nums[2 * i + 1]);
			i = (i - 1) / 2;
		}
		else {
			++i;
		}
	}
}
vector<int> heapSort(vector<int> nums) {
	vector<int> res;
	while(nums.size()>=1){
		createHeap(nums, 0, nums.size());
		swap(nums[0], nums[nums.size() - 1]);
		res.push_back(nums[nums.size() - 1]);
		nums.pop_back();
	}
	return res;
}
int main() {
	vector<int> a = generate_random_array(1000);
	a=heapSort(a);
	cout << isSorted(a) << endl;
	vector<int> b = generate_sorted_array(1000);
	b = heapSort(b);
	cout << isSorted(b) << endl;
	vector<int> c = generate_sorted_reverse_array(1000);
	c = heapSort(c);
	cout << isSorted(c) << endl;
	vector<int> d = generate_near_sorted_array(1000);
	d = heapSort(d);
	cout << isSorted(d) << endl;
}