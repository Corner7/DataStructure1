#pragma once

using namespace std;

extern const int MaxSize;

class Graph;//ͼ

template<typename T> class MGraph;//�ڽӾ���
class DMGraph;//�����ڽӾ���
class AlGraph;//�ڽӱ�
class DAlGraph;//�����ڽӱ�

class Graph {};

template<typename T>
class MGraph :public Graph {
public:
	T data;
};
