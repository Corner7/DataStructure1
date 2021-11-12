#pragma once
#include<iostream>
using namespace std;
extern const int MaxSize;

template <typename T>
class queue {
public:
	queue();
	void push(T x);
	void pop();
	void pop(T &x);
	T getfront();
	T getrear();
	bool isempty();
private:
	T data[MaxSize];
	int m_front;
	int m_rear;
};

//循环队列
template<typename T>
queue<T>::queue() {
	m_front = 0;
	m_rear = 0;
}

template<typename T>
void queue<T>::push(T x) {
	if ((m_rear + 1) % MaxSize == m_front) {
		cout << "队满" << endl;
		return;
	}
	data[m_rear] = x;
	m_rear = (m_rear + 1) % MaxSize;
}

template<typename T>
void queue<T>::pop() {
	if (this->isempty()) {
		cout << "队空" << endl;
		return;
	}
	m_front = (m_front + 1) % MaxSize;
}

template<typename T>
void queue<T>::pop(T &x) {
	if (this->isempty()) {
		cout << "队空" << endl;
		return;
	}
	x = data[m_front];
	m_front = (m_front + 1) % MaxSize;
}

template<typename T>
T queue<T>::getfront() {
	if (this->isempty()) {
		cout << "队空" << endl;
		exit(-1);
	}
	return data[m_front];
}

template<typename T>
T queue<T>::getrear() {
	if (this->isempty()) {
		cout << "队空" << endl;
		exit(-1);
	}
	return data[(m_rear + MaxSize - 1) % MaxSize];
}

template<typename T>
bool queue<T>::isempty() {
	if (m_rear == m_front)
		return true;
	else
		return false;
}