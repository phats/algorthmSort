#ifndef __CREATERANDOMARR_H__
#define __CREATERANDOMARR_H__

#include <random>
#include<vector>
using namespace std;

vector<int> generate_random_array(int n);
vector<int> generate_sorted_array(int n);
vector<int> generate_sorted_reverse_array(int n);
vector<int> generate_near_sorted_array(int n);
bool isSorted(vector<int> a);

#endif