#pragma once

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
	//virtual int getedgenum()const = 0;		//��ȡ����

	//virtual bool Adjacent(char a, char b)const = 0;	//�������Ƿ�����
	//virtual void Neighbor(char x)const = 0;			//��������ڶ���
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
	MGraph(char V[], int E[][MaxSize], int n);		//EΪָ�� ��СΪ4*MaxSize���ڴ�ռ��ָ�� 
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
MGraph::MGraph(char V[], int E[][MaxSize], int n){	//Ϊʲô����д
	vexnum = n;
	edgenum = 0;
	for (int i = 0; i < n; i++) {
		this->Vex[i] = V[i];
		for (int j = 0; j < n; j++) {
			this->Edge[i][j] = E[i][j];
			if (E[i][j] == 1)				//Ϊʲô��1��weight���ǿ���Ϊ����������
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

//ɶ��˼��
int MGraph::cEdge(char a)const {
	for (int i = 0; i < this->vexnum; i++) {
		if (Vex[i] == a)
			return i;
	}
	return -1;
}

//�����
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


