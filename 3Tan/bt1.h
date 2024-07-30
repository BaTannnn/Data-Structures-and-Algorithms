#pragma once
#include <iostream>
using namespace std;
struct DS {
	int *a;
	int capacity;
	int size;
	DS(int cap=100) {
		a = new int [cap];
		size = 0;
		capacity = cap;
	}
	void Insert(int n) {
		for (int i = size; i < size + n; i++) {
			cout << "Nhap phan tu a[" << i << "]="; cin >> a[i];
		}
		size += n;
	}
	void XuatDS() {
		for (int i = 0; i < size; i++) {
			cout << a[i] << " ";
		}
	}
	void swap(int &a,int &b) {
		int temp = a;
		a = b;
		b = temp;
	}
	void InsertionSort(){
		for (int i = 1; i < size; i++) {
			int x = a[i];
			int j = i - 1;
			while (i >= 0 && a[j] < x) {
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = x;
		}
	}
	void SelectionSort() {
		for (int i = 0; i < size-1; i++) {
			int min_pos = i;
			for (int j = i + 1; j < size; j++) {
				if (a[j] < a[min_pos]) {
					min_pos = j;
				}
			}
			swap(a[i], a[min_pos]);
		}
	}
	void InterchangeSort() {
		for (int i = 0; i < size-1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (a[j] > a[i]) {
					swap(a[i], a[j]);
				}
			}
		}
	}
	void BubbleSort() {
		for (int i = 0; i < size-1; i++) {
			for (int j = size - 1; j > i; j--) {
				swap(a[j - 1], a[j]);
			}
		}
	}
	int Search(int x) {
		for (int i = 0; i < size; i++) {
			if (a[i] == x)
				return i;
		}
		return -1;
	}
	int BinarySearch(int x, int left, int right) {
		if (left >= right) {
			return -1;
		}
		else {
			int mid = (left + right) / 2;
			if (a[mid] == x) {
				return mid;
			}
			if (a[mid] > x) {
				BinarySearch(x, mid + 1, right);
			}
			else {
				BinarySearch(x, left, mid - 1);
			}
		}
	}
};
