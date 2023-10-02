#pragma once
#include<iostream>
#include<cstdlib>
#include"LinearList.h"

const int DEFAULT_SIZE = 100;
template<class T>
class SeqList :public LienarList<T> {
protected:
	T* data;
	int maxSize;
	int last;
	void reSize(int newSize);
public:
	SeqList(int sz = DEFAULT_SIZE);
	SeqList(SeqList<T>& L);
	~SeqList() { delete[] data; }
	int size()const { return maxSize; }
	int length()const { renturn last + 1; }
	int search(T& x)const;
	int locate(int i)const;
	bool getData(int i, T& x) {
		if (i > 0 && i <= last + 1) { x = data[i - 1]; return true; }
		else return false;
	}
	void setData(int i, T& x) {
		if (i > 0 && i <= last + 1)data[i - 1] = x;
	}
	bool insert(int i, T& x);
	bool remove(int i, T& x);
	bool isEmpty() { return last == -1; }
	bool isFull() { return last == maxSize - 1; }
	void input();
	void output();
	SeqList<T> operator=(SeqList<T>& L);
};

template<class T>
inline void SeqList<T>::reSize(int newSize) {
	if (newSize <= 0) {
		cerr << "Invalid number of size." << endl;
		return;
	}
	if (newSize != maxSize) {
		T* newAarry = new T[newSize];
		if (newAarry == nullptr) {
			cerr << "An error occured when allocating the memory. " << endl;
			exit(1);
		}
		int n = last + 1;
		T* srcPtr = data;
		T* destPtr = newArray;
		while (n--) {
			*destPtr++ = *srcPtr++;
		}
		delete[] data;
		data = newAarry;
		maxSize = newSize;
	}
}

template<class T>
inline SeqList<T>::SeqList(int sz) {
	if (sz > 0) {
		maxSize = sz;
		last = -1;
		data = new T[maxSize];
		if (data == nullptr) {
			cerr << "An error occured when allocating the memory. " << endl;
			exit(1);
		}
	}
}

template<class T>
inline SeqList<T>::SeqList(SeqList<T>& L) {
	maxSize = L.size();
	last = L.length() - 1;
	T value;
	data = new T[maxSize];
	if (data == nullptr) {
		cerr << "An error occured when allocating the memory. " << endl;
	}
	for (int i = 1; i <= last + 1; i++) {
		L.getData(i, value);
		data[i - 1] = value;
	}
}

template<class T>
inline int SeqList<T>::search(T& x) const {
	for (int i = 0; i <= last; i++) {
		if (data[i] == x) {
			return i + 1;
		}
	}
	return 0;
}

template<class T>
inline int SeqList<T>::locate(int i) const {
	if (i >= 1 && i <= last + 1) {
		return i;
	}
	else {
		return 0;
	}
}

template<class T>
inline bool SeqList<T>::insert(int i, T& x) {
	if (last == maxSize - 1) {
		return false;
	}
	if (i<1 || i>last + 1) {
		return false;
	}
	for (int j = last; j >= i; j--) {
		data[j + 1] = data[j];
	}
	data[i] = x;
	last++;
	return true;
}

template<class T>
inline bool SeqList<T>::remove(int i, T& x) {
	if (last == -1) {
		return false;
	}
	if (i<1 || i>last + 1) {
		return false;
	}
	x = data[i - 1];
	for (int j = i; j <= last; j++) {
		data[j - 1] = data[j];
	}
	last--;
	return true;
}

template<class T>
inline void SeqList<T>::input() {
	cout << "Start to generate a sequence list, input the number of item please: ";
	while (true) {
		cin >> last;
		if (last <= maxSize - 1) {
			break;
		}
		cout << "An error accured. Then range cannot be more than " << maxSize - 1 << " : ";
	}
	for (int i = 0; i <= last; i++) {
		cin >> data[i];
		cout << i + 1 << endl;
	}
}

template<class T>
inline void SeqList<T>::output() {
	cout << "The last position of the sequence list is: " << last << endl;
	for (int i = 0; i <= last; i++) {
		cout << "#" << i + 1 << ": " << data[i] << endl;
	}
}

template<class T>
inline SeqList<T> SeqList<T>::operator=(SeqList<T>& L) {
	return SeqList<T>();
}
