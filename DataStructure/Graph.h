#pragma once

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
	//virtual int getedgenum()const = 0;		//获取弧数

	//virtual bool Adjacent(char a, char b)const = 0;	//两顶点是否相邻
	//virtual void Neighbor(char x)const = 0;			//顶点的相邻顶点
	virtual void InsertVertex(char x) = 0;
	virtual void InsertEdge(char a, char b, int weight) = 0;
	//virtual void DeleteVertex(char x) = 0;
	//virtual void DeletaEdge(char a, char b) = 0;
	//virtual int FirstNeighbor(char a)const = 0;
	//virtual int FirstNeighbor(int i)const = 0;
	//virtual int NextNeighbor(char a, char b)const = 0;
	//virtual int NextNeighbor(int i, int b)const = 0;
	//virtual int	GetEdgeValue(char a, char b)const = 0;
	//virtual void SetEdgeValue(char a, char b,int weight	) = 0;

protected:

};

class MGraph :public Graph {
public:
	MGraph();
	MGraph(int vexnum, int archnum);
	MGraph(char V[], int E[][MaxSize], int n);		//E为指向 大小为4*MaxSize的内存空间的指针 
	MGraph(const MGraph& MG);

	int getvexnum()const;
	char getname(int i) const;
	int cEdge(char a)const;
	void InsertEdge(char a, char b, int weight);
	void InsertVertex(char x);
	MGraph power(int n);

protected:
	char Vex[MaxSize];
	int Edge[MaxSize][MaxSize];
	int vexnum, edgenum;
	
};

MGraph::MGraph() {
	this->vexnum = 0;
	this->edgenum = 0;
}
MGraph::MGraph(int vexnum,int edgenum) {
	this->vexnum = vexnum;
	this->edgenum = edgenum;
}
MGraph::MGraph(char V[], int E[][MaxSize], int n){	//为什么这样写
	vexnum = n;
	edgenum = 0;
	for (int i = 0; i < n; i++) {
		this->Vex[i] = V[i];
		for (int j = 0; j < n; j++) {
			this->Edge[i][j] = E[i][j];
			if (E[i][j] == 1)				//为什么是1，weight不是可以为任意整数吗？
				this->edgenum++;
		}
	}
	this->edgenum /= 2;
}
MGraph::MGraph(const MGraph& mg) {
	this->vexnum = mg.getvexnum();
	this->edgenum = mg.getedgenun();
	for (int i = 0; i < mg.getvexnum(); i++) {
		for (int j = 0; j < mg.getvexnum(); j++)
			this->Edge[i][j] = mg.Edge[i][j];
	}
}

int MGraph::getvexnum()const{
	return this->vexnum;
}
char MGraph::getname(int i)const {
	return this->Vex[i];
}

//啥意思？
int MGraph::cEdge(char a)const {
	for (int i = 0; i < this->vexnum; i++) {
		if (Vex[i] == a)
			return i;
	}
	return -1;
}

//插入边
void MGraph::InsertEdge(char a, char b, int weight) {
	int v1 = -1, v2 = -1;
	for (int i = 0; i < getvexnum(); i++) {
		if (this->Vex[i] == a)
			v1 = i;
		if (this->Vex[i] == b)
			v2 = i;
		if (v1 > -1 && v2 > -1)
			break;
	}
	if (v1 > -1 && v2 > -1) {
		this->Edge[v1][v2] = weight;
		this->Edge[v2][v1] = weight;
		this->edgenum++;
	}
}

void MGraph::InsertVertex(char x) {
	this->Vex[this->vexnum] = x;
}

MGraph MGraph::power(int n) {

}


