#include<iostream>
#include"createRandomArr.h"
using namespace std;
void merge(vector<int>& Nums, int left, int mid, int right) {
	vector<int> res;
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right) {
		if (Nums[i] < Nums[j]) {
			res.push_back(Nums[i]);
			++i;
		}
		else {
			res.push_back(Nums[j]);
			++j;
		}
	}
	while (i <= mid) {
		res.push_back(Nums[i]);
		++i;
	}
	while (j <= right) {
		res.push_back(Nums[j]);
		++j;
	}
	for (int k = left; k <= right; k++) {
		Nums[k] = res[k - left];
	}
}
void mergeSort(vector<int>& Nums, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(Nums, left, mid);
		mergeSort(Nums, mid + 1, right);
		merge(Nums, left, mid, right);
	}
}
int main() {
	vector<int> a = generate_random_array(1000);
	mergeSort(a,0,a.size()-1);
	cout << isSorted(a) << endl;
	vector<int> b = generate_sorted_array(1000);
	mergeSort(b, 0, b.size() - 1);
	cout << isSorted(b) << endl;
	vector<int> c = generate_sorted_reverse_array(1000);
	mergeSort(c, 0, c.size() - 1);
	cout << isSorted(c) << endl;
	vector<int> d = generate_near_sorted_array(1000);
	mergeSort(d, 0, d.size() - 1);
	cout << isSorted(d) << endl;
}