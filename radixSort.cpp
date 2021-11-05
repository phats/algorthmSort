#include<iostream>
#include"createRandomArr.h"
#include<cmath>
using namespace std;
#define MAX_ELEMENT_IN_ARRAY 9
int getMaxNumDigit(vector<int> Nums) {
	int maxDigit = 0;
	for (int i = 0; i < Nums.size(); i++) {
		int count = 0;
		while (Nums[i]) {
			++count;
			maxDigit = max(maxDigit, count);
			Nums[i] /= 10;
		}
	}
	return maxDigit;
}
void countingSort(vector<int>& Nums,int exp) {
	vector<int> countArr(MAX_ELEMENT_IN_ARRAY + 1, 0);
	for (int i = 0; i < Nums.size(); i++) {
		++countArr[(Nums[i]/exp)%10];
	}
	for (int i = 1; i < countArr.size(); i++) {
		countArr[i] += countArr[i - 1];
	}
	vector<int> res(Nums.size(), 0);
	for (int i = Nums.size()-1; i >=0; i--) {
		res[countArr[(Nums[i] / exp) % 10] - 1] = Nums[i];
		--countArr[(Nums[i] / exp) % 10];
	}
	for (int i = 0; i < Nums.size(); i++) {
		Nums[i] = res[i];
	}
}
 void radixSort(vector<int>& Nums) {
	 int maxDigit = getMaxNumDigit(Nums);
	 for (int i = 1; i <= pow(10, maxDigit); i *= 10) {
		countingSort(Nums, i);
	 }
}
 void printArray(vector<int> a) {
	 for (int i = 0; i < a.size(); i++) {
		 cout << " " << a[i];
	 }
 }
 int main() {
	 vector<int> a = generate_random_array(8);
	 radixSort(a);
	 cout << isSorted(a) << endl;
	 vector<int> b = generate_sorted_array(1000);
	 radixSort(b);
	 cout << isSorted(b) << endl;
	 vector<int> c = generate_sorted_reverse_array(1000);
	 radixSort(c);
	 cout << isSorted(c) << endl;
 }