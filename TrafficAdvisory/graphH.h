#pragma once
#include"base.h"
#include"string.h"
//#include"lqueue.h"
//�ڽӱ���ṹ����
#define UNVISITED 0
#define VISITED 1
#define INFINITY MAX_INT  
#define SELECTED 1
#define UNSELECTED 0 
typedef enum { DG, DN, UDG, UDN }GraphKind;//����ͼ�������Ȩͼ������ͼ�������Ȩͼ
typedef enum {MONEY,TIME}infoKind;//����Ǯ������ʱ��
typedef enum { PLANE, TRAIN } TransportKind;//
//

//
typedef struct AdjVexNode {
	int adjvex;// �ڽӶ����ڶ��������е�λ��
	char endname[MAX_LENGTH_STRING];//�յ�վ
	char linename[MAX_LENGTH_STRING];//�����
	TransportKind kind;
	Time startTime, stopTime;
	int info_Money; //A��B�� ��Ǯ����
	Time timeCost; // A��B�� ʱ������
	AdjVexNode* nextArc; // ָ����һ���ڽӶ���(��һ���߻�)
} AdjVexNode, * AdjVexNodeP, LineNode, * LineNodeP; // �ڽ�����Ľ������

typedef struct vexNode {
	VexType cityName[MAX_LENGTH_STRING];//����ֵ, VexType�Ƕ�������,���û�����
	int cityID;//���б��
	struct AdjVexNode* firstArc; // �ڽ������ͷָ��
	int arcNum;//·����
}VexNode;//���������Ԫ������
typedef struct {
	VexNode* vexs; // ��������, ���ڴ洢������Ϣ
	int n, e;//�������ͱ�(��)��
	GraphKind kind;//ͼ������
	int* tags; // ��־����, ��������ͼ�ı����б�Ƕ���ü����
}ALGraph;//�ڽӱ�����

typedef struct {
	VexType v, w;//�߶˵�
	int ID;
	int info_Money;
	int info_Time;
}ArcInfo;
typedef struct {
	int prev;//��ǰ���·���ϸö����ǰ������λ��
	int money;//��ǰ���·������
}DistInfoMoney;

typedef struct {
	int prev;//��ǰ���·���ϸö����ǰ������λ��
	int time; //(ʱ��)
	Time et; //����ʱ��
	LineNodeP p;//��prev�ĳ���
}DistInfoTime;

typedef struct {
	int prev;//��ǰ���·���ϸö����ǰ������λ��
	int lowcost;//��ǰ���·������
	//LineNodeP p;//��prev�ĳ���
}DistInfoStation;

//�ӿ�

//Status visit(VexType v);//���ʽ��
//Status CreatDG_AL(ALGraph& G);//����n�������e���ߵ�kind���ͼG,vexsΪ������Ϣ,arcsΪ����Ϣ

Status CreatNodeOnlyGraph_AL(ALGraph& G, VexType* name[], int n);//����n�������ͼG
Status DestroyGraph_AL(ALGraph& G); // ����ͼG
int LocateVexByName_AL(ALGraph G, VexType *v); //���Ҷ���v��ͼG�е�λ��
int LocateVexByID_AL(ALGraph G, int ID);
Status GetVex_AL(ALGraph G, int k, VexType& w); // ȡͼG��k�����ֵ��w
Status PutVex_AL(ALGraph G, int k, VexType w);//��ͼG��k���㸳ֵw
int FirstAdjVex_AL(ALGraph G, int k, AdjVexNode& p);
/*��ͼG��k������ڽ�����ǿ�, ����ָ��pָ���һ�����, ���������д����ڽ�$��λ��, ������ָ��pΪNULL, ������ - 1 */
int NextAdjvex_AL(ALGraph G, int k, AdjVexNodeP& p);
// ��k������ڽ�������, ��pָ����һ�����
//��p�ǿ�, ���ش洢��p����е���һ���ڽӶ����λ��, ���򷵻� - 1
Status AddArc_AL(ALGraph& G, int k, int m, char *endname, char *linename, TransportKind kind, int info_Money, Time startTime, Time stopTime, Time timeCost);//��ͼG������k���㵽m����ı߻�,��Ϊ��Ȩͼ,infoΪȨֵ,����Ϊ1
Status RemoveArc_One_AL(ALGraph& G, int k, int m, char* lineName);//��ͼG��ɾ��k���㵽m����ı߻�
//Status DFSTraverse_AL(ALGraph G, Status(*visit)(VexType));  // ������ȱ���ͼG
//Status BFSTraverse_AL(ALGraph G, Status(*visit)(VexType));//������ȱ���ͼG
Status ADDVexNode_AL(ALGraph& G, VexNode w);//���Ӷ���w
Status RemoveVexNode_AL(ALGraph& G, int k, VexNode& w);//�Ƴ�ͼG��k���㵽w//�Ƴ��ڵ㲻�ͷ��ڴ�
void Dijkstra_Money(ALGraph G, int v0, DistInfoMoney* &dis);
void Dijkstra_Time(ALGraph G, int v0, DistInfoTime*& dis, Time arriveT);
void inputTime(Time& startTime, Time& endTime);
void timeCost(Time startTime, Time endTime, Time& cost);
int TimeWeight(const Time& t);
int TimeCmp(Time time1, Time time2);
Time TimeADD(Time time1, Time time2);
void printTime(Time t);
void AddLine(ALGraph& G);
void ADDCity(ALGraph& G);
Status ShowLine(ALGraph& G, char startname[], char endname[]);;
void ShowCity(ALGraph G);
void ShowLine(ALGraph G);
void DeleteLine(ALGraph& G);
void DeleteCity(ALGraph& G);
void Outputpath_Money(ALGraph G, DistInfoMoney Dist[], int k, int& cost, Time& arriveT, int& timecost);
void Outputpath_Time(ALGraph G, DistInfoTime Dist[], int k, int& cost, Time& arriveT);
void Dijkstra_Station(ALGraph G, int i, DistInfoStation*& Dist);
void Outputpath_Station(ALGraph G, DistInfoStation Dist[], int k, int& cost);