#pragma once
#include <iostream>
using namespace std;

const int MaxSize = 100;

class Graph;//ͼ

class MGraph;//�ڽӾ���
class DMGraph;//�����ڽӾ���
class AlGraph;//�ڽӱ�
class DAlGraph;//�����ڽӱ�

//�����麯�� �� ��̬����ͨ������ָ����Է������������ĳ�Ա���˳�Ա�Ǵӻ���̳й�ȥ�ģ��е��ƣ�Ҫ���գ�
//��Ҫ�û���ָ�����������ĳ�Ա���������Ա����Ҫ����Ϊ�麯��
//���������еĺ�������Ϊ�麯�������������о����ڱι�ϵ��ͬ�����������Զ���Ϊ�麯����
//��������ͬ���ɹ���ͬ���ڱΣ���ֻ�к���ԭ����ͬ�������ǹ�ϵ���Ź��ɶ�̬������ڱε������ǣ����Ե��û�����麯��
//һ��̳к�Ҫ�Ķ��ĺ�������Ҫ����Ϊ�麯��
//���캯���������麯�������������������麯��
//���������������������Ϊ�麯���������������ڴ�й©����http://c.biancheng.net/view/vip_2297.html

//���麯����=0���� �����࣬���ܴ�������ͨ����Ϊ���࣬������ֻ��ʵ�ִ��麯�����ܱ�ʵ����
//���Զ���һ��������ֻ࣬��ɲ��ֹ��ܣ�δ��ɵĹ��ܽ���������ȥʵ�֣�˭����˭ʵ�֣�
class Graph {
public:
	virtual char getname(int i) const = 0;	//
	virtual int cEdge(char a)const = 0;		
	virtual int getvexnum()const = 0;		//��ȡ�ڵ���
	virtual int getedgenum()const = 0;		//��ȡ����

	virtual bool Adjacent(char a, char b)const = 0;	//�������Ƿ�����
	virtual void Neighbor(char x)const = 0;			//��������ڶ���
	virtual void InsertVertex(char x) = 0;
	virtual void InsertEdge(char a, char b, int weight) = 0;
	virtual void DeleteVertex(char x) = 0;
	virtual void DeleteEdge(char a, char b) = 0;
	virtual int FirstNeighbor(char a)const = 0;
	virtual int FirstNeighbor(int i)const = 0;
	virtual int NextNeighbor(char a, char b)const = 0;
	virtual int NextNeighbor(int i, int b)const = 0;
	virtual int	GetEdgeValue(char a, char b)const = 0;
	virtual void SetEdgeValue(char a, char b,int weight	) = 0;

protected:

};
//���ڽӾ���
class MGraph :public Graph {
public:
	MGraph();
	MGraph(int vexnum, int archnum);
	MGraph(char V[], int E[][MaxSize], int n);		//EΪָ�� ��СΪ4*MaxSize���ڴ�ռ��ָ�� 
	MGraph(const MGraph& MG);

	int getvexnum()const;
	int getedgenum()const;
	char getname(int i) const;
	int cEdge(char a)const;
	void InsertEdge(char a, char b, int weight);
	void InsertVertex(char x);
	MGraph power(int n);

	MGraph operator*(const MGraph mg) const;

	bool Adjacent(char a, char b)const;

	void Neighbor(char x)const ;

	void DeleteVertex(char x);

	void DeleteEdge(char a, char b);

	int FirstNeighbor(char a) const;

	int FirstNeighbor(int x) const;

	int NextNeighbor(char a, char b) const;

	int NextNeighbor(int a, int b) const;

	int GetEdgeValue(char a, char b) const;
	int GetEdgeValue(int a, int b)const;

	void SetEdgeValue(char a, char b, int weight);



protected:
	char Vex[MaxSize];
	int Edge[MaxSize][MaxSize];
	int vexnum, edgenum;
	
};



//�ڣ��Ȳ�д
class DMGraph :public MGraph {

};

struct EdgeNode {		//�߱���
	int adjvex;			//��ָ��Ķ���
	EdgeNode* next;		//��һ��������ָ��
	int weight;
	EdgeNode(int adj, int w) {
		this->adjvex = adj;
		this->next = nullptr;
		this->weight = w;
	}
};
struct VertexNode{		//�������
	char name;			//������Ϣ
	EdgeNode* first;	//��һ�������ö���Ļ���ע�⣬����ͼ 1 ָ�� 2 �Ļ������� 1 ����Ϊ���û�β��������ʾ�����ģ�
	VertexNode() {		//ע�⣬һ�����ṹ��Ĳ�ͬ�����ǹ����Ա������
		this->name = 0;
		this->first = nullptr;
	}
	VertexNode(char a) {
		this->name = a;
		this->first = nullptr;
	}
	bool deleteEdge(int x){				//�е㸴�ӣ��ú�����
		EdgeNode* p = this->first;		
		if (p != nullptr) {				//��pΪ�գ�������ɾ���߱���
			EdgeNode* q = p->next;
			if (p->adjvex == x) {		//����һ��������x��ֱ��ɾ��
				this->first = q;
				delete p;
			}		
			else {						//���ڶ�����֮��Ľ�����x
				while (q!= nullptr) {
					if (q->adjvex == x) {
						p = q->next;
						delete q;
						return true;
					}
					p = q;
					q = q->next;
				}
			}
		}
		return false;
	}
	void insertEdge(EdgeNode* e) {		//zwbд�ĺ���������
		if (this->first == nullptr)
			this->first = e;
		else {
			EdgeNode* p = this->first;
			while (p->next != nullptr)
				p = p->next;			//ʹpָ���������һ�����
			p->next = e;
		}
	}

};

class ALGraph :public Graph {
public:
	ALGraph();
	ALGraph(const MGraph& mg);

	virtual char getname(int i)const {		return this->adjlist[i].name;	}
	virtual int cEdge(char a)const;
	virtual int getvexnum() {		return this->vexnum;	}
	virtual int getedgenum() {		return this->edgenum;	}
	virtual void visit(int i)const { cout << " " << this->adjlist[i].name << " "; }

	virtual void InsertEdge(char a, char b, int weight);
	virtual void InsertVertex(char a);
	virtual bool Adjacent(char a, char b) const;
	virtual void Neighbors(char x) const;
	virtual void DeleteVertex(char x);
	virtual void DeleteEdge(char a, char b);
	virtual int FirstNeighbor(char a) const;
	virtual int FirstNeighbor(int i) const;
	virtual int NextNeighbor(char a, char b) const;
	virtual int NextNeighbor(int a, int b) const;
	virtual int GetEdgeValue(char a, char b) const;
	virtual void SetEdgeValue(char a, char b, int weight);


protected:
	VertexNode adjlist[MaxSize];
	int vexnum, edgenum;
};



