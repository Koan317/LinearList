#include<iostream>
#include"SeqList.h"

int main() {
	SeqList<int> s1(10);
	s1.input();
	s1.output();
	SeqList<int> s2(4);
	void* tempptr = &s2;
	cout << "qwer " << sizeof(tempptr) << endl;
	s2 = s1;
	cout << "qwer " << sizeof(tempptr) << endl;
	s2.output();
	s1.sort();
	s1.output();
}