#pragma once
#include <iostream>
using namespace std;

const int MaxSize = 100;

class Graph;//图

class MGraph;//邻接矩阵
class DMGraph;//有向邻接矩阵
class AlGraph;//邻接表
class DAlGraph;//有向邻接表

//★★★虚函数 → 多态，即通过基类指针可以访问派生类对象的成员，此成员是从基类继承过去的（有点绕，要掌握）
//若要用基类指针访问派生类的成员函数，则成员函数要定义为虚函数
//若将基类中的函数声明为虚函数，则派生类中具有遮蔽关系的同名函数都将自动成为虚函数。
//函数名相同即可构成同名遮蔽，但只有函数原型相同（即覆盖关系）才构成多态，如果遮蔽但不覆盖，则仍调用基类的虚函数
//一般继承后要改动的函数，需要声明为虚函数
//构造函数不能是虚函数，析构函数可以是虚函数
//基类的析构函数必须声明为虚函数，否则可能造成内存泄漏，见http://c.biancheng.net/view/vip_2297.html

//纯虚函数（=0）→ 抽象类，不能创建对象，通常作为基类，派生类只有实现纯虚函数才能被实例化
//可以定义一个抽象基类，只完成部分功能，未完成的功能交给派生类去实现（谁派生谁实现）
class Graph {
public:
	virtual char getname(int i) const = 0;	//
	virtual int cEdge(char a)const = 0;		
	virtual int getvexnum()const = 0;		//获取节点数
	virtual int getedgenum()const = 0;		//获取弧数

	virtual bool Adjacent(char a, char b)const = 0;	//两顶点是否相邻
	virtual void Neighbor(char x)const = 0;			//顶点的相邻顶点
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
//①邻接矩阵法
class MGraph :public Graph {
public:
	MGraph();
	MGraph(int vexnum, int archnum);
	MGraph(char V[], int E[][MaxSize], int n);		//E为指向 大小为4*MaxSize的内存空间的指针 
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



//②，先不写
class DMGraph :public MGraph {

};

struct EdgeNode {		//边表结点
	int adjvex;			//弧指向的顶点
	EdgeNode* next;		//下一条弧结点的指针
	int weight;
	EdgeNode(int adj, int w) {
		this->adjvex = adj;
		this->next = nullptr;
		this->weight = w;
	}
};
struct VertexNode{		//顶点表结点
	char name;			//顶点信息
	EdgeNode* first;	//第一条依附该顶点的弧（注意，有向图 1 指向 2 的弧依附于 1 ，因为是用弧尾顶点来表示弧结点的）
	VertexNode() {		//注意，一个类或结构体的不同对象是共享成员函数的
		this->name = 0;
		this->first = nullptr;
	}
	VertexNode(char a) {
		this->name = a;
		this->first = nullptr;
	}
	bool deleteEdge(int x){				//有点复杂，好好整理
		EdgeNode* p = this->first;		
		if (p != nullptr) {				//若p为空，则无须删除边表结点
			EdgeNode* q = p->next;
			if (p->adjvex == x) {		//若第一个结点等于x，直接删除
				this->first = q;
				delete p;
			}		
			else {						//若第二个或之后的结点等于x
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
	void insertEdge(EdgeNode* e) {		//zwb写的好像有问题
		if (this->first == nullptr)
			this->first = e;
		else {
			EdgeNode* p = this->first;
			while (p->next != nullptr)
				p = p->next;			//使p指向链表最后一个结点
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



