#pragma once
#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

//�ٶ�����
template<typename T>
class BinaryTree {
public:
	BinaryTree<T>* lchild;
	BinaryTree<T>* rchild;

	BinaryTree();
	BinaryTree(T data);

	void visit();
	T getdata();
	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder();
	void PreOrder0();
	void InOrder0();
	void PostOrder0();

	//void setlchild(BinaryTree<T>* p);
	//void setrchild(BinaryTree<T>* p);

	//BinaryTree<T> *Pre_In_BuildBT(T pre[], T in[], int pre1, int pre2, int in1, int in2);
	//BinaryTree<T> *Post_In_BuildBT(T post[], T in[], int post1, int post2, int in1, int in2);
	//BinaryTree<T>* level_in_BuildBT(T level[], T in[], int in1, int in2, int n);

protected:
	T data;

};
//���캯��
template<typename T>
BinaryTree<T>::BinaryTree() {
	this->data = 0;
	this->lchild = nullptr;
	this->rchild = nullptr;
}
template<typename T>
BinaryTree<T>::BinaryTree(T data) {
	this->data = data;
	this->lchild = nullptr;
	this->rchild = nullptr;
}

//Ҫ����<<������� ֻҪT�����Ϳ���ʹ��<<,�Ϳ��ԣ�ģ��ֻ��ʵ�����Ż����
template <typename T>
void BinaryTree<T>::visit() {
	if(this!=nullptr)
		cout << " " << this->data << " ";
}

template<typename T>
T BinaryTree<T>::getdata() {
	if(this!=nullptr)
		return this->data;
	exit(-1);
}

//ǰ�����
template<typename T>
void BinaryTree<T>::PreOrder() {
	cout << "ǰ�������";
	stack<BinaryTree<T>*> S;
	BinaryTree<T>* p = this;
	while (p != nullptr || !S.isempty()) {
		if (p!=nullptr) {
			p->visit();
			S.push(p);
			p = p->lchild;
		}
		else {
			S.pop(p);
			p = p -> rchild;
		}
	}
	cout << endl;
}

//�������
template<typename T>
void BinaryTree<T>::InOrder() {
	cout << "���������";
	stack<BinaryTree<T>*> S;
	BinaryTree<T>* p = this;
	while (p!=nullptr||!S.isempty()) {
		if (p!=nullptr) {
			S.push(p);
			p = p->lchild;
		}
		else {
			S.pop(p);
			p->visit();
			p = p->rchild;
		}
	}
	cout << endl;
}

//�������
template<typename T>
void BinaryTree<T>::PostOrder() {
	cout << "���������";
	stack<BinaryTree<T>*> S;
	BinaryTree<T>* p = this; 
	BinaryTree<T>* r = nullptr;
	while (p!=nullptr||!S.isempty()) {
		if (p!=nullptr) {
			S.push(p);
			p = p->lchild;
		}
		else {
			p = S.gettop();
			if (p->rchild != nullptr && p->rchild != r)
				p = p->rchild;
			else {
				S.pop(p);
				p->visit();
				r = p;
				p = nullptr;
			}
		}
	}
	cout << endl;
}

//�������
template<typename T>
void BinaryTree<T>::LevelOrder() {
	cout << "���������";
	queue<BinaryTree<T>*> Q;
	BinaryTree<T>* p=this;
	Q.push(p);
	while (!Q.isempty()) {
		Q.pop(p);
		p->visit();
		if (p->lchild != nullptr)
			Q.push(p->lchild);
		if (p->rchild != nullptr)
			Q.push(p->rchild);
	}
	cout << endl;
}

//�ݹ�����ֱ���
template<typename T>
void BinaryTree<T>::PreOrder0() {
	if (this!=nullptr) {
		this->visit();
		this->lchild->PreOrder0();
		this->rchild->PreOrder0();
	}
}
template<typename T>
void BinaryTree<T>::InOrder0() {
	if (this!=nullptr) {
		this->lchild->InOrder0();
		this->visit();
		this->rchild->InOrder0();
	}
}
template<typename T>
void BinaryTree<T>::PostOrder0() {
	if (this!=nullptr) {
		this->lchild->PostOrder0();
		this->rchild->PostOrder0();
		this->visit();
	}
}

//�������Һ���
/*
template<typename T>
void BinaryTree<T>::setlchild(BinaryTree<T>* p) {
	this->lchild = p;
}

template<typename T>
void BinaryTree<T>::setrchild(BinaryTree<T>* p) {
	this->rchild = p;
}
*/

//����+���򹹽�������,����Ԫ����
template<typename T>
BinaryTree<T>* Pre_In_BuildBT(T pre[], T in[], int pre1, int pre2, int in1, int in2) {
	BinaryTree<T>* root = new BinaryTree<T>(pre[pre1]);
	int i;
	for (i = in1; in[i] != root->getdata(); i++);
	int llen = i - in1;
	int rlen = in2 - i;
	if (llen)
		root->lchild = Pre_In_BuildBT(pre, in, pre1 + 1, pre1 + llen, in1, i - 1);
	else
		root->lchild = nullptr;
	if (rlen)
		root->rchild = Pre_In_BuildBT(pre, in, pre2 - rlen + 1, pre2, i + 1, in2);
	else
		root->rchild = nullptr;
	return root;
}
//����+���򹹽�������
template<typename T>
BinaryTree<T>* Post_In_BuildBT(T post[], T in[], int post1, int post2, int in1, int in2) {
	BinaryTree<T>* root = new BinaryTree<T>(post[post2]);
	int i;
	for (i = in1; in[i] != root->getdata(); i++);
	int llen = i - in1;
	int rlen = in2 - i;
	if (llen)
		root->lchild = Post_In_BuildBT(post, in, post1, post1 + llen - 1, in1, i - 1);
	else
		root->lchild = nullptr;
	if (rlen)
		root->rchild = Post_In_BuildBT(post, in, post2 - rlen, post2 - 1, i + 1, in2);
	else
		root->rchild = nullptr;
	return root;
}

//����+���򹹽�������,ע������仯
template<class T>
BinaryTree<T>* level_in_BuildBT(T level[], T in[], int in1, int in2, int n) {
	if (in1 > in2)
		return nullptr;
	int i, j;
	bool find;
	for (i = 0; i <= n; i++) {
		find = false;
		for (j = in1; j <= in2; j++) {
			if (level[i] == in[j]) {
				find = true;
				break;
			}
		}
		if (find)
			break;
	}
	BinaryTree<T>* root = new BinaryTree<T>(level[i]);
	root->lchild = level_in_BuildBT(level, in, in1, j - 1, n);
	root->rchild = level_in_BuildBT(level, in, j + 1, in2, n);
	return root;
}

//������������,�̳��Զ�����
//ע�⣺1.�̳�ʱ������ȫ�������Ա�����˹��캯��������������
//2.ͬ�����أ������������ĺ���ֻҪ������һ�������أ����������� 
//3.����µĳ�Ա
//�����private��Ա�̳к���ֱ��ʹ�ã����ǿ���ͨ�����ü̳��Ի���Ľӿں�����ʹ��
template<typename T>
class ThreadTree :public BinaryTree<T> {
public:
	ThreadTree<T>* lchild;	//ע�⣬ָ���������������ͬ
	ThreadTree<T>* rchild;

	using BinaryTree<T>::data;

	ThreadTree();
	ThreadTree(T data);
	ThreadTree<T>* InThread();
	void BuildInThread();

protected:
	//tag=0,ָ���ӣ�tag=1��ָ��ǰ�������
	int ltag;
	int rtag;

};

//�������������캯��
//ע�⣬ģ�������������ʽ���ã�Ҫ��this���߼��޶�������ͨ������Ҫ��ģ����̳�ģ���࣬���࿴�������ࣩ
template<typename T>
ThreadTree<T>::ThreadTree() {
	BinaryTree<T>::data = 0;
	this->lchild = nullptr;
	this->rchild = nullptr;
	this->ltag = 0;
	this->rtag = 0;
}
template<typename T>
ThreadTree<T>::ThreadTree(T data) {
	this->data = data;
	this->lchild = nullptr;
	this->rchild = nullptr;
	this->ltag = 0;
	this->rtag = 0;
}

//���������������Ĺ���
//ǰ��ͺ����أ�
template<typename T>
ThreadTree<T>* ThreadTree<T>::InThread() {
	ThreadTree<T>* p = this;
	static ThreadTree<T>* pre = nullptr;	//��̬�ֲ�������ȫ���������ֲ��ɼ�
	if (p!=nullptr) {
		p->lchild->InThread();
		if (p->lchild==nullptr) {
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre!=nullptr&&pre->rchild==nullptr) {
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		p->rchild->InThread();
	}
	return pre;
}
template<typename T>
void ThreadTree<T>::BuildInThread() {
	if (this != nullptr) {
		ThreadTree<T>* pre = this->InThread();
		pre->rchild = nullptr;
		pre->rtag = 1;		
	}
}



//�۹�������
template<typename T>
class HuffmanTree :public BinaryTree<T> {
public:
	HuffmanTree();
	HuffmanTree(T data);

//	friend HuffmanTree<T>* BuildHuffmanTree(T weight[], int n);

	HuffmanTree<T>* lchild;
	HuffmanTree<T>* rchild;
};
//���캯��
template<typename T>
HuffmanTree<T>::HuffmanTree() {
	this->data = 0;
	this->lchild = nullptr;
	this->rchild = nullptr;
}
template<typename T>
HuffmanTree<T>::HuffmanTree(T weight) {
	this->data = weight;
	this->lchild = nullptr;
	this->rchild = nullptr;
}

template<typename T>
HuffmanTree<T>* BuildHuffmanTree(T weight[],int n) {
	HuffmanTree<T>** Node=new HuffmanTree<T>*[n];	//��̬����
	for (int i = 0; i < n; i++) {	//�����������
		HuffmanTree<T>* p = new HuffmanTree<T>(weight[i]);
		Node[i] = p;
	}
	int k1 = -1, k2 = -1;	//���������С�������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {	//ѡ����һ����С��
			if (Node[j] == nullptr)
				continue;
			if (k1 == -1 || Node[k1] == nullptr || Node[k1]->getdata() > Node[j]->getdata())
				k1 = j;
		}
		for (int j = 0; j < n; j++) {	//ѡ���ڶ�����С��
			if (Node[j] == nullptr || k1 == j)
				continue;
			if (k2 == -1 || Node[k2] == nullptr || Node[k2]->getdata() > Node[j]->getdata())
				k2 = j;
		}
		if (Node[k2]==nullptr) {	//�ڶ������ûѡ����û�и������ˣ��������
			HuffmanTree<T>* r = Node[k1];
			return r;
		}
		HuffmanTree<T>* t = new HuffmanTree<T>(Node[k1]->getdata() + Node[k2]->getdata());
		t->lchild = Node[k1];
		t->rchild = Node[k2];
		Node[k1] = t;	//�½ڵ����������
		Node[k2] = nullptr;
	}
}

//�ܶ���������
template<typename T>
class BinarySearchTree :public BinaryTree<T> {
public:
	BinarySearchTree();
	BinarySearchTree(T key);
	BinarySearchTree<T>* lchild;
	BinarySearchTree<T>* rchild;

	bool Insert(T k);
	//bool Delete(T k);	//��ôд��˼��һ��
	BinarySearchTree<T>* Search(T key);
	BinarySearchTree<T>* findMax();
	BinarySearchTree<T>* findMin();
	void showBigger(T key);
};
//���캯��
template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
	this->data = 0;
	this->lchild = nullptr;
	this->rchild = nullptr;
}
template<typename T>
BinarySearchTree<T>::BinarySearchTree(T data) {
	this->data = data;
	this->lchild = nullptr;
	this->rchild = nullptr;
}

//���룬�ݹ�
template<typename T>
bool BinarySearchTree<T>::Insert(T key) {
	if (this == nullptr) {	//thisΪ�գ����Ҳ���this��Insert�������ʲ���ʧ��
		cout << "��ָ�룬����ʧ��" << endl;
		return false;
	}
	else if (key == this->getdata())
		return false;
	else if (key < this->getdata()) {
		if (this->lchild == nullptr) {
			BinarySearchTree<T>* node = new BinarySearchTree<T>(key);
			this->lchild = node;
		}
		else
			return this->lchild->Insert(key);
	}
	else {
		if (this->rchild == nullptr) {
			BinarySearchTree<T>* node = new BinarySearchTree<T>(key);
			this->rchild = node;
		}
		else
			return this->rchild->Insert(key);
	}
}
//��������������,���β�����
template<typename T>
BinarySearchTree<T>* BTS_Build(T A[],int n) {
	BinarySearchTree<T>* root = new BinarySearchTree<T>(A[0]);
	for (int i = 1; i < n; i++)
		root->Insert(A[i]);
	return root;
}	
//���ң��ǵݹ�
template<typename T>
BinarySearchTree<T>* BinarySearchTree<T>::Search(T key) {
	BinarySearchTree<T>* p = this;
	while (p!=nullptr&&p->getdata()!=key) {
		if (key < p->getdata())
			p = p->lchild;
		else
			p = p->rchild;
	}
	if (p != nullptr)
		cout << "���ҳɹ�" << endl;
	else
		cout << "����ʧ��" << endl;
	return p;
}
//�������С���
template<typename T>
BinarySearchTree<T>* BinarySearchTree<T>::findMax() {
	BinarySearchTree<T>* p = this;
	while (p->rchild != nullptr)
		p = p->rchild;
	cout << "MAX = " << p->getdata() << endl;
	return p;
}
template<typename T>
BinarySearchTree<T>* BinarySearchTree<T>::findMin() {
	BinarySearchTree<T>* p = this;
	while (p->lchild != nullptr)
		p = p->lchild;
	cout << "MIN = " << p->getdata() << endl;
	return p;
}

//����ȴ���k�Ľ�㣨��ʵ�������������
template<typename T>
void BinarySearchTree<T>::showBigger(T key) {
	stack<BinarySearchTree<T>*> S;
	BinarySearchTree<T>* p = this;
	while (p!=nullptr||!S.isempty()) {
		if (p!=nullptr) {
			S.push(p);
			p = p->lchild;
		}
		else {
			S.pop(p);
			if (key < p->getdata())
				cout << " " << p->getdata() << " ";
			p = p->rchild;
		}
	}
}