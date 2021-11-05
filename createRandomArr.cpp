
#include"createRandomArr.h"

#define MAX_ELEMENT_IN_ARRAY 10
vector<int> generate_random_array(int n)
{
	vector<int> a;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<unsigned long long> dis(0, MAX_ELEMENT_IN_ARRAY);

	for (int i = 0; i < n; i++)
		a.push_back(dis(gen));
	return a;
}
vector<int> generate_sorted_array(int n)
{
	vector<int> a;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<unsigned long long> dis(0, MAX_ELEMENT_IN_ARRAY);

	for (int i = 0; i < n; i++)
		a.push_back(dis(gen));
	sort(a.begin(),a.end());
	return a;
}
vector<int> generate_sorted_reverse_array(int n)
{
	vector<int> a;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<unsigned long long> dis(0, MAX_ELEMENT_IN_ARRAY);

	for (int i = 0; i < n; i++)
		a.push_back(dis(gen));
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	return a;
}
vector<int> generate_near_sorted_array(int n) {
	vector<int> a;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<unsigned long long> dis(0, MAX_ELEMENT_IN_ARRAY);

	for (int i = 0; i < n; i++)
		a.push_back(dis(gen));
	sort(a.begin(),a.end());
	for (int i = 0; i < n; i += 1000) {
		a[i] = 271199;
	}
	return a;
}
bool isSorted(vector<int> a) {
	for (int i = 0; i < a.size()-1; i++) {
		if (a[i + 1] < a[i]) return false;
	}
	return true;
}