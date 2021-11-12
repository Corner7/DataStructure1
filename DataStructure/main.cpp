#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"

using namespace std;

const int MaxSize = 50;

int main() {

	//��������������
	/*
	BinaryTree<char>* bt = new BinaryTree<char>('A');
	BinaryTree<char>* p1 = new BinaryTree<char>('B');
	BinaryTree<char>* p2 = new BinaryTree<char>('C');
	BinaryTree<char>* p3 = new BinaryTree<char>('D');
	BinaryTree<char>* p4 = new BinaryTree<char>('E');
	BinaryTree<char>* p5 = new BinaryTree<char>('F');
	BinaryTree<char>* p6 = new BinaryTree<char>('G');
	bt->lchild = p1;
	bt->rchild = p2;
	p1->lchild = p3;
	p1->rchild = p4;
	p2->lchild = p5;
	p2->rchild = p6;

	bt->PreOrder();
	bt->InOrder();
	bt->PostOrder();
	bt->LevelOrder();
	cout << "���������";
	bt->PreOrder0();
	cout << endl << "���������";
	bt->InOrder0();
	cout << endl << "���������";
	bt->PostOrder0();
	cout << endl;
	*/
	

	//�������ɶ���������
	/*
	char A[] = { 'A','B','D','E','C','F','G' };
	char B[] = { 'D','B','E','A','F','C','G' };
	char C[] = { 'D','E','B','F','G','C','A' };
	char D[] = { 'A','B','C','D','E','F','G' };
	BinaryTree<char>* tr1 = Pre_In_BuildBT(A, B, 0, 6, 0, 6);
	tr1->PreOrder();
	BinaryTree<char>* tr2 = Post_In_BuildBT(C, B, 0, 6, 0, 6);
	tr2->InOrder();
	BinaryTree<char>* tr3 = level_in_BuildBT(D, B, 0, 6, 6);
	tr3->PostOrder();
	*/

	//��������������
	/*
	ThreadTree<char>* tt = new ThreadTree<char>('A');
	ThreadTree<char>* t1 = new ThreadTree<char>('B');
	ThreadTree<char>* t2 = new ThreadTree<char>('C');
	ThreadTree<char>* t3 = new ThreadTree<char>('D');
	ThreadTree<char>* t4 = new ThreadTree<char>('E');
	ThreadTree<char>* t5 = new ThreadTree<char>('F');
	ThreadTree<char>* t6 = new ThreadTree<char>('G');
	tt->lchild = t1;
	tt->rchild = t2;
	t1->lchild = t3;
	t1->rchild = t4;
	t2->lchild = t5;
	t2->rchild = t6;
	tt->BuildInThread();
	cout << "   �ĺ�̽���ǣ�" <<t5->rchild->getdata()<< endl;
	*/

	//������������
	/*
	int weight[] = { 2,4,5,7 };		//������p180
	HuffmanTree<int>* ht;
	ht = BuildHuffmanTree(weight, 4);
	cout << ht->getdata() << endl;
	*/

	//��������������
	
	int A[] = { 12,92,0,70,25,44,89,27,23,50 };
	BinarySearchTree<int> *bts = BTS_Build(A,10);
	bts->Search(25);	//�ɹ�
	bts->Search(30);	//ʧ��
	bts->findMax();
	bts->findMin();
	//bts->InOrder();	//������ô���
	bts->showBigger(45);



	return 0;
}
