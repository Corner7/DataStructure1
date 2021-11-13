#pragma once

extern const int MaxSize;

//��˫�ױ�ʾ��
template<typename T>
class PTree {
public:
	PTNode node[MaxSize];
	int n;	//�����
};
//���
template<typename T>
class PTNode {
public:
	int parent;
protected:
	T data
};

//�ں��ӱ�ʾ��
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
	CTBox* parent;	//����ָ�򸸽ڵ��ָ��
protected:
	T data;
};
class CTNode {
public:
	int child;
	CTNode* next;
};

//�ۺ����ֵܱ�ʾ������������ʾ����
template<typename T>
class CSTree {
public:
	CSTree<T>* firstchild;
	CSTree<T>* nextsibling;
	CSTree<T>* parent;	//����һ��ָ�򸸽ڵ��ָ��

	CSTree();
	CSTree(T data);
protected:
	T data;
};
//���캯��
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
