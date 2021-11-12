#pragma once
#include<iostream>
using namespace std;
extern const int MaxSize;
//enum bool{false,true};

template<typename T>
class stack {
public:
	stack();
	void push(T x);
	void pop();
	void pop(T& x);
	T gettop();
	bool isempty();
private:
	T data[MaxSize];
	int m_top;
};

template<typename T>
stack<T>::stack() {
	m_top = -1;
}

template<typename T>
void stack<T>::push(T x) {
	if (m_top == MaxSize - 1) {
		cout << "Õ»Âú£¡" << endl;
		return;
	}
	data[++m_top] = x;
}

template<typename T>
void stack<T>::pop() {
	if (m_top == -1) {
		cout << "Õ»¿Õ£¡" << endl;
		return;
	}
	m_top--;
}

template<typename T>
void stack<T>::pop(T &x) {
	if (m_top == -1) {
		cout << "Õ»¿Õ£¡" << endl;
		return;
	}
	x=data[m_top];
	m_top--;
}

template<typename T>
T stack<T>::gettop() {
	if (m_top == -1) {
		cout << "Õ»¿Õ£¡" << endl;
		exit(-1);
	}
	return data[m_top];
}

template<typename T>
bool stack<T>::isempty() {
	if (m_top == -1)
		return true;
	else
		return false;
}