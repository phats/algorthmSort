#include"createRandomArr.h"
#include<iostream>
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void exchangeSort(vector<int>& Nums) {
	for (int i = 0; i < Nums.size()-1; i++) {
		for (int j = i+1; j < Nums.size(); j++) {
			if (Nums[i] > Nums[j]) {
				swap(Nums[i], Nums[j]);
			}
		}
	}
}
int main() {
	vector<int> a = generate_random_array(1000);
	exchangeSort(a);
	cout << isSorted(a) << endl;
	vector<int> b = generate_sorted_array(1000);
	exchangeSort(b);
	cout << isSorted(b) << endl;
	vector<int> c = generate_sorted_reverse_array(1000);
	exchangeSort(c);
	cout << isSorted(c) << endl;
	vector<int> d = generate_near_sorted_array(1000);
	exchangeSort(d);
	cout << isSorted(d) << endl;
}