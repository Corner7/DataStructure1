#include "Graph.h"

MGraph::MGraph() {
	this->vexnum = 0;
	this->edgenum = 0;
}
MGraph::MGraph(int vexnum, int edgenum) {
	this->vexnum = vexnum;
	this->edgenum = edgenum;
}
MGraph::MGraph(char V[], int E[][MaxSize], int n) {	//Ϊʲô����д
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
	this->edgenum = mg.getedgenum();
	for (int i = 0; i < mg.getvexnum(); i++) {
		for (int j = 0; j < mg.getvexnum(); j++)
			this->Edge[i][j] = mg.Edge[i][j];
	}
}

int MGraph::getvexnum()const {
	return this->vexnum;
}
char MGraph::getname(int i)const {
	return this->Vex[i];
}
int MGraph::getedgenum()const {
	return this->edgenum;
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
	MGraph G(*this);
	for (int i = 0; i < n; i++) {
		G = G * (*this);		//*Ҫ����
	}
	return G;
}
//����*�����
//��������غ�������������Ϊ��ĳ�Ա��������������Ϊȫ�ֺ�����
MGraph MGraph::operator*(const MGraph mg) const {	//����˷�
	MGraph G;
	for (int i = 0; i < this->vexnum; i++) {
		for (int j = 0; j < this->vexnum; j++) {
			int sum = 0;
			for (int k = 0; k < this->vexnum; k++) {
				sum += this->Edge[i][k] * mg.Edge[k][j];	//���С�����
			}
			G.Edge[j][j] = sum;
			if (sum != 0)
				G.vexnum++;
		}
	}
	G.vexnum /= 2;
	return G;
}
//�ж��������Ƿ�����
bool MGraph::Adjacent(char a, char b)const {
	int v1 = this->cEdge(a);
	int v2 = this->cEdge(b);
	if (v1 > -1 && v2 > -1 && this->Edge[v1][v2] != 0)
		return true;
	else
		return false;
}
//���x������ھ�
void MGraph::Neighbor(char x)const {
	int v1 = this->cEdge(x);
	cout << x << "���ھ��У�";
	for (int i = 0; i < this->vexnum; i++) {
		if (this->Edge[i][v1] != 0)
			cout << " " << Vex[i] << " ";
	}
	return;
}
//ɾ������
void MGraph::DeleteVertex(char x) {		//zwbд��������
	int v1 = this->cEdge(x);
	for (int i = 0; i < this->vexnum; i++) {
		if (Edge[i][v1] != 0)
			this->edgenum--;
		//if (Edge[v1][i] != 0)
		//	this->edgenum--;
	}
	for (int j = 0; j < this->vexnum; j++)
		for (int k = 0; k < this->vexnum; k++) {
			if (j > v1)
				this->Edge[j - 1][k] = this->Edge[j][k];
			if (k > v1)
				this->Edge[j][k - 1] = this->Edge[j][k];
		}
	this->vexnum--;
}
//ɾ����
void MGraph::DeleteEdge(char a, char b) {
	int v1 = this->cEdge(a);
	int v2 = this->cEdge(b);
	this->Edge[v1][v2] = 0;
	this->Edge[v2][v1] = 0;
	this->edgenum--;
}

//��һ���ھӶ���
int MGraph::FirstNeighbor(char a)const {
	int v1 = this->cEdge(a);
	return this->FirstNeighbor(v1);
}
int MGraph::FirstNeighbor(int x)const {		//zwb��i��ʼֵ�ǲ���������
	for (int i = 0; i < this->vexnum; i++)
		if (this->Edge[i][x] != 0)
			return i;
	return -1;
}

//ĳ�������ĳ�ھӵ���һ���ھӶ���
int MGraph::NextNeighbor(char a, char b)const {
	int v1 = this->cEdge(a);
	int v2 = this->cEdge(b);
	return this->NextNeighbor(v1, v2);
}
int MGraph::NextNeighbor(int a, int b)const {
	for (int i = b + 1; i < this->vexnum; i++)
		if (this->Edge[b][i] != 0)
			return i;
	return -1;
}

//��ȡ�ߵ�Ȩֵ
int MGraph::GetEdgeValue(char a, char b)const {
	int v1 = this->cEdge(a);
	int v2 = this->cEdge(b);
	return this->Edge[v1][v2];
}
int MGraph::GetEdgeValue(int a, int b)const {
	return this->Edge[a][b];
}

void MGraph::SetEdgeValue(char a, char b, int weight) {
	int v1 = this->cEdge(a);
	int v2 = this->cEdge(b);
	this->Edge[v1][v2] = weight;
	this->Edge[v2][v1] = weight;
}


/************************************************************/

ALGraph::ALGraph() {
	this->vexnum = 0;
	this->edgenum = 0;
}
ALGraph::ALGraph(const MGraph& mg) {		//��zwbд�Ĳ�ͬ
	this->vexnum = mg.getvexnum();
	this->edgenum = mg.getedgenum();
	VertexNode* p;
	for (int i = 0; i < this->vexnum; i++) {	//������ʼ��
		p = new VertexNode(mg.getname(i));
		adjlist[i] = *p;
	}
	EdgeNode* q;
	for (int i = 0; i < this->vexnum; i++) {	//�߱��ʼ��
		q = adjlist[i].first;
		for (int j = 0; j < this->vexnum; j++) {
			if (mg.GetEdgeValue(i, j) != 0) {
				q = new EdgeNode(j, mg.GetEdgeValue(i, j));
				q = q->next;
			}
		}
	}
}


int ALGraph::cEdge(char a)const {
	for (int i = 0; i < this->vexnum; i++) {
		if (a == this->getname(i))
			return i;
	}
	return -1;
}

void ALGraph::InsertEdge(char a, char b, int weight) {	//����������㲻������
	int v1 = cEdge(a);
	int v2 = cEdge(b);
	EdgeNode* p1 = new EdgeNode(v1, weight);
	EdgeNode* p2 = new EdgeNode(v2, weight);
	//ͷ��
	p2->next = adjlist[v1].first;	//��a������뵽b�ı�
	this->adjlist[v1].first = p2;	
	p1->next = adjlist[v2].first;	//��b������뵽a�ı�
	this->adjlist[v2].first = p1;
	this->edgenum++;
}
void ALGraph::InsertVertex(char x) {
	VertexNode* v = new VertexNode(x);
	this->adjlist[this->vexnum++] = *v;
}

bool ALGraph::Adjacent(char a, char b)const {
	int v1 = cEdge(a);
	int v2 = cEdge(b);
	EdgeNode* p = adjlist[v1].first;
	while (p != nullptr) {
		if (p->adjvex == v2)
			return true;
		p = p->next;
	}
	return false;
}
void ALGraph::Neighbors(char x)const {
	int v1 = cEdge(x);
	EdgeNode* p = this->adjlist[v1].first;
	while(p!=nullptr){
		cout << " " << this->adjlist[p->adjvex].name << " ";
		p = p->next;
	}
}
void ALGraph::DeleteVertex(char x) {	//��zwb��һ��
	int v1 = cEdge(x);
	for (int i = v1+1; i < this->vexnum; i++) {			//�����Ԫ�������ƶ�
		this->adjlist[i - 1] = this->adjlist[i];
	}
	this->vexnum--;

	int n = 0;
	for (int i = 0; i < this->vexnum; i++) {			//�޸ı߱�
		if (this->adjlist[i].deleteEdge(x))
			n++;
	}
	this->edgenum -= n / 2;
}

void ALGraph::DeleteEdge(char a, char b) {
	int v1 = cEdge(a);
	int v2 = cEdge(b);
	this->adjlist[v1].deleteEdge(v2);	//ɾ��a��b�Ļ�
	this->adjlist[v2].deleteEdge(v1);	//ɾ��b��a�Ļ�
	this->edgenum--;
}

int ALGraph::FirstNeighbor(char a)const {
	int v1 = cEdge(a);
	return this->FirstNeighbor(v1);		//��������ġ�
}
int ALGraph::FirstNeighbor(int x) const{
	if (this->adjlist[x].first == nullptr)
		return -1;
	else
		return this->adjlist[x].first->adjvex;
}

int ALGraph::NextNeighbor(char a,char b)const {	//ĳ�����ĳһ�ھӶ���ĺ�һ���ھӶ���,zwb��������
	int v1 = cEdge(a);
	int v2 = cEdge(b);
	return this->NextNeighbor(v1, v2);	//��������ġ�
}
int ALGraph::NextNeighbor(int x,int y)const {
	EdgeNode* p = this->adjlist[x].first;
	while (p != nullptr && p->adjvex != y)		//�ҵ�b���
		p = p->next;
	if (p == nullptr || p->next == nullptr)
		return -1;
	else
		return p->next->adjvex;
}

int ALGraph::GetEdgeValue(char a, char b)const {
	int v1 = this->cEdge(a);
	int v2 = this->cEdge(b);
	EdgeNode* p = this->adjlist[v1].first;
	while (p != nullptr && p->adjvex != v2)
		p = p->next;
	if (p == nullptr)
		return 0;
	else
		return p->weight;
}

void ALGraph::SetEdgeValue(char a,char b,int weight){
	int v1 = this->cEdge(a);
	int v2 = this->cEdge(b);
	EdgeNode* p;

	p = this->adjlist[v1].first;
	while (p != nullptr && p->adjvex != v2)
		p = p->next;
	if (p != nullptr)
		p->weight = weight;

	p = this->adjlist[v2].first;
	while (p != nullptr && p->adjvex != v1)
		p = p->next;
	if (p != nullptr)
		p->weight = weight;
}



