#include<iostream>
#include"createRandomArr.h"
using namespace std;
#define MAX_ELEMENT_IN_ARRAY 10
vector<int> countingSort(vector<int> Nums) {
	vector<int> countArr(MAX_ELEMENT_IN_ARRAY+1, 0);
	for (int i = 0; i < Nums.size(); i++) {
		++countArr[Nums[i]];
	}
	for (int i = 1; i < countArr.size(); i++) {
		countArr[i] += countArr[i - 1];
	}
	vector<int> res(Nums.size(), 0);
	for (int i = 0; i < Nums.size(); i++) {
		res[countArr[Nums[i]]-1] = Nums[i];
		--countArr[Nums[i]];
	}
	return res;
}
int main() {
	vector<int> a = generate_random_array(1000);
	a=countingSort(a);
	cout << isSorted(a) << endl;
	vector<int> b = generate_sorted_array(1000);
	b=countingSort(b);
	cout << isSorted(b) << endl;
	vector<int> c = generate_sorted_reverse_array(1000);
	c=countingSort(c);
	cout << isSorted(c) << endl;
}