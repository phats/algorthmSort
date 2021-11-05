#include<iostream>
#include"createRandomArr.h"
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void bubbleSort(vector<int>& Nums) {
	int left = 0;
	int right = Nums.size() - 1;
	int stop = 0;
	while (left < right) {
		//MAX NUMBER IN RIGHT
		for (int i = left; i < right; i++) {
			if (Nums[i] > Nums[i + 1]) {
				swap(Nums[i], Nums[i + 1]);
				stop = i;
			}
		}
		right = stop;
		//MIN NUMBER IN LEFT
		for (int i = right; i > left; i--) {
			if (Nums[i] < Nums[i - 1]) {
				swap(Nums[i], Nums[i - 1]);
				stop = i;
			}
		}
		left = stop;
	}
}
int main() {
	vector<int> a = generate_random_array(1000);
	bubbleSort(a);
	cout << isSorted(a) << endl;
	vector<int> b = generate_sorted_array(1000);
	bubbleSort(b);
	cout << isSorted(b) << endl;
	vector<int> c = generate_sorted_reverse_array(1000);
	bubbleSort(c);
	cout << isSorted(c) << endl;
	vector<int> d = generate_near_sorted_array(1000);
	bubbleSort(d);
	cout << isSorted(d) << endl;
}