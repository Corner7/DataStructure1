#pragma once

using namespace std;

extern const int MaxSize;

class Graph;//图

template<typename T> class MGraph;//邻接矩阵
class DMGraph;//有向邻接矩阵
class AlGraph;//邻接表
class DAlGraph;//有向邻接表

class Graph {};

template<typename T>
class MGraph :public Graph {
public:
	T data;
};
