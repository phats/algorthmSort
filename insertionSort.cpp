#include"createRandomArr.h"
#include<iostream>
 
using namespace std;
void insertionSort(vector<int>& Nums){
	for (int i = 1; i < Nums.size(); i++) {
		int pos = i - 1;
		int temp = Nums[i];
		while (pos >= 0 && temp < Nums[pos]) {
			Nums[pos + 1] = Nums[pos];
			--pos;
		}
		Nums[pos + 1] = temp;
	}
}
int binarySearch(vector<int> Nums, int pos, int i, int j) {
	int middle = (i + j) / 2;
	if (i==0 && j==0) {
		return 0;
	}
	else if (i > j) {
		return pos;
	}
	if (Nums[middle] >= Nums[pos] && Nums[pos] >= Nums[middle - 1]) {
		return middle;
	}
	else if (Nums[middle] >= Nums[pos]) {
		return binarySearch(Nums, pos, i, middle-1);
	}
	else {
		return binarySearch(Nums, pos, middle+1, j);
	}
}
void shellSort(vector<int>& Nums) {
	int gap = Nums.size() / 2;
	while (gap > 0) {
		for (int i = 0; i + gap < Nums.size(); i++) {
			if (Nums[i] > Nums[i + gap]) {
				swap(Nums[i], Nums[i + gap]);
				i = max(-1, i - gap-1);
			}
		}
		gap /= 2;
	}
}
int main() {
	vector<int> a = generate_random_array(1000);
	insertionSort(a);
	cout << isSorted(a) << endl;
	vector<int> b = generate_sorted_array(1000);
	insertionSort(b);
	cout << isSorted(b) << endl;
	vector<int> c = generate_sorted_reverse_array(1000);
	insertionSort(c);
	cout << isSorted(c) << endl;
	vector<int> d = generate_near_sorted_array(1000);
	insertionSort(d);
	cout << isSorted(d) << endl;
	vector<int> e = generate_random_array(1000);
	shellSort(e);
	cout << isSorted(e) << endl;
}