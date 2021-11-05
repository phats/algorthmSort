#include"createRandomArr.h"
#include<iostream>

using namespace std;
int findMin(vector<int> Nums, int low, int high) {
	if (low == high) {
		return Nums[low];
	}
	if (Nums[low] <= findMin(Nums, low + 1, high)) {
		return Nums[low];
	}
	else {
		return findMin(Nums, low + 1, high);
	}
}
void selectionSort(vector<int>& Nums) {
	for (int i = 0; i < Nums.size(); i++) {
		Nums[i] = findMin(Nums, i, Nums.size() - 1);
	}
}
int main() {
	vector<int> a = generate_random_array(10);
	selectionSort(a);
	cout << isSorted(a) << endl;
	vector<int> b = generate_sorted_array(10);
	selectionSort(b);
	cout << isSorted(b) << endl;
	vector<int> c = generate_sorted_reverse_array(10);
	selectionSort(c);
	cout << isSorted(c) << endl;
	vector<int> d = generate_near_sorted_array(10);
	selectionSort(d);
	cout << isSorted(d) << endl;
}