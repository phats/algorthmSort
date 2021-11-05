#include"createRandomArr.h"
#include<iostream>
using namespace std;
void quickSort(vector<int>& Nums) {
	vector<int> l1;
	vector<int> l2;
	int pivot = Nums[Nums.size()-1];
	for (int i = 0; i < Nums.size() - 1; i++) {
		if (Nums[i] < pivot) l1.push_back(Nums[i]);
		else {
			l2.push_back(Nums[i]);
		}
	}
	if (l1.size() != 0) {
		quickSort(l1);
	}
	if (l2.size() != 0) {
		quickSort(l2);
	}
	for (int i = 0; i < l1.size(); i++) {
		Nums[i] = l1[i];
	}
	Nums[l1.size()]=pivot;
	for (int j = 0; j < l2.size(); j++) {
		Nums[j + l1.size() + 1] = l2[j];
	}
}
int main() {
	vector<int> a = generate_random_array(10);
	quickSort(a);
	cout << isSorted(a) << endl;
	vector<int> b = generate_sorted_array(1000);
	quickSort(b);
	cout << isSorted(b) << endl;
	vector<int> c = generate_sorted_reverse_array(1000);
	quickSort(c);
	cout << isSorted(c) << endl;
	vector<int> d = generate_near_sorted_array(1000);
	quickSort(d);
	cout << isSorted(d) << endl;
}