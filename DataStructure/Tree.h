#pragma once

extern const int MaxSize;

//①双亲表示法
template<typename T>
class PTree {
public:
	PTNode node[MaxSize];
	int n;	//结点数
};
//结点
template<typename T>
class PTNode {
public:
	int parent;
protected:
	T data
};

//②孩子表示法
template<typename T>
class CTree {
public:
	CTBox<T> node[MaxSize];
	int n, r;
};
template<typename T>
class CTBox {
public:
	CTNode* firstchild;
	CTBox* parent;	//增设指向父节点的指针
protected:
	T data;
};
class CTNode {
public:
	int child;
	CTNode* next;
};

//③孩子兄弟表示法（二叉树表示法）
template<typename T>
class CSTree {
public:
	CSTree<T>* firstchild;
	CSTree<T>* nextsibling;
	CSTree<T>* parent;	//增加一个指向父节点的指针

	CSTree();
	CSTree(T data);
protected:
	T data;
};
//构造函数
template<typename T>
CSTree<T>::CSTree() {
	this->data = 0;
	this->firstchild = nullptr;
	this->nextsibling = nullptr;
}
template<typename T>
CSTree<T>::CSTree(T data) {
	this->data = data;
	this->firstchild = nullptr;
	this->nextsibling = nullptr;
}
