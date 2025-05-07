#pragma once
#include <iostream>
using namespace std;
template <typename T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool &found, int &location) {
	found = false;//?
	while (first <= last) {//?
		int middle = (first + last) / 2;
		if (a[middle] == key) {
			found = true;
			location = middle;
			return;
		}
		else if (a[middle] < key) {
			first = middle + 1;
			continue;
		}
		else if (a[middle]>key){
			last = middle - 1;
			continue;
		}
	}
}
//const T a[]?
template <typename T>
void RecBinarySearch(const T a[], int first, int last, T key, bool &found, int &location) {
	found = false;//???????????
	if (last>=first) {
		int middle = (first + last) / 2;
		if (a[middle] == key) {
			found = true;
			location = middle;
			return;
		}
		else if (a[middle] > key)
			RecBinarySearch(a, first, middle - 1, key, found, location);
		else
			RecBinarySearch(a, middle + 1, last, key, found, location);
	}
}
