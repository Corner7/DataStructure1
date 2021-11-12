#pragma once
#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

//①二叉树
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
//构造函数
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

//要重载<<运算符吗？ 只要T的类型可以使用<<,就可以，模板只有实例化才会编译
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

//前序遍历
template<typename T>
void BinaryTree<T>::PreOrder() {
	cout << "前序遍历：";
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

//中序遍历
template<typename T>
void BinaryTree<T>::InOrder() {
	cout << "中序遍历：";
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

//后序遍历
template<typename T>
void BinaryTree<T>::PostOrder() {
	cout << "后序遍历：";
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

//层序遍历
template<typename T>
void BinaryTree<T>::LevelOrder() {
	cout << "层序遍历：";
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

//递归的三种遍历
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

//设置左右孩子
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

//先序+中序构建二叉树,非友元函数
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
//后序+中序构建二叉树
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

//层序+中序构建二叉树,注意参数变化
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

//②线索二叉树,继承自二叉树
//注意：1.继承时会吸收全部基类成员（除了构造函数和析构函数）
//2.同名隐藏，基类哈派生类的函数只要函数名一样即隐藏，不构成重载 
//3.添加新的成员
//基类的private成员继承后不能直接使用，但是可以通过调用继承自基类的接口函数来使用
template<typename T>
class ThreadTree :public BinaryTree<T> {
public:
	ThreadTree<T>* lchild;	//注意，指针类型与二叉树不同
	ThreadTree<T>* rchild;

	using BinaryTree<T>::data;

	ThreadTree();
	ThreadTree(T data);
	ThreadTree<T>* InThread();
	void BuildInThread();

protected:
	//tag=0,指向孩子；tag=1，指向前驱、后继
	int ltag;
	int rtag;

};

//线索二叉树构造函数
//注意，模板派生类必须显式调用，要用this或者加限定符，普通类则不需要（模板类继承模板类，子类看不到父类）
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

//中序线索二叉树的构建
//前序和后序呢？
template<typename T>
ThreadTree<T>* ThreadTree<T>::InThread() {
	ThreadTree<T>* p = this;
	static ThreadTree<T>* pre = nullptr;	//静态局部变量，全局寿命，局部可见
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



//③哈夫曼树
template<typename T>
class HuffmanTree :public BinaryTree<T> {
public:
	HuffmanTree();
	HuffmanTree(T data);

//	friend HuffmanTree<T>* BuildHuffmanTree(T weight[], int n);

	HuffmanTree<T>* lchild;
	HuffmanTree<T>* rchild;
};
//构造函数
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
	HuffmanTree<T>** Node=new HuffmanTree<T>*[n];	//动态数组
	for (int i = 0; i < n; i++) {	//建立结点数组
		HuffmanTree<T>* p = new HuffmanTree<T>(weight[i]);
		Node[i] = p;
	}
	int k1 = -1, k2 = -1;	//标记两个最小结点的序号
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {	//选出第一个最小的
			if (Node[j] == nullptr)
				continue;
			if (k1 == -1 || Node[k1] == nullptr || Node[k1]->getdata() > Node[j]->getdata())
				k1 = j;
		}
		for (int j = 0; j < n; j++) {	//选出第二个最小的
			if (Node[j] == nullptr || k1 == j)
				continue;
			if (k2 == -1 || Node[k2] == nullptr || Node[k2]->getdata() > Node[j]->getdata())
				k2 = j;
		}
		if (Node[k2]==nullptr) {	//第二个结点没选，即没有更多结点了，则构造完成
			HuffmanTree<T>* r = Node[k1];
			return r;
		}
		HuffmanTree<T>* t = new HuffmanTree<T>(Node[k1]->getdata() + Node[k2]->getdata());
		t->lchild = Node[k1];
		t->rchild = Node[k2];
		Node[k1] = t;	//新节点加入结点数组
		Node[k2] = nullptr;
	}
}

//④二叉排序树
template<typename T>
class BinarySearchTree :public BinaryTree<T> {
public:
	BinarySearchTree();
	BinarySearchTree(T key);
	BinarySearchTree<T>* lchild;
	BinarySearchTree<T>* rchild;

	bool Insert(T k);
	//bool Delete(T k);	//怎么写，思考一下
	BinarySearchTree<T>* Search(T key);
	BinarySearchTree<T>* findMax();
	BinarySearchTree<T>* findMin();
	void showBigger(T key);
};
//构造函数
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

//插入，递归
template<typename T>
bool BinarySearchTree<T>::Insert(T key) {
	if (this == nullptr) {	//this为空，则找不到this的Insert函数，故插入失败
		cout << "空指针，插入失败" << endl;
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
//构建二叉搜索树,依次插入结点
template<typename T>
BinarySearchTree<T>* BTS_Build(T A[],int n) {
	BinarySearchTree<T>* root = new BinarySearchTree<T>(A[0]);
	for (int i = 1; i < n; i++)
		root->Insert(A[i]);
	return root;
}	
//查找，非递归
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
		cout << "查找成功" << endl;
	else
		cout << "查找失败" << endl;
	return p;
}
//找最大最小结点
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

//输出比大于k的结点（其实就是中序遍历）
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