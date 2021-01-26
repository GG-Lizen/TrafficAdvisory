#pragma once
#include"base.h"
#include"string.h"
//#include"lqueue.h"
//邻接表储存结构定义
#define UNVISITED 0
#define VISITED 1
#define INFINITY MAX_INT  
#define SELECTED 1
#define UNSELECTED 0 
typedef enum { DG, DN, UDG, UDN }GraphKind;//有向图，有向带权图，无向图，无向带权图
typedef enum {MONEY,TIME}infoKind;//消耗钱，消耗时间
typedef enum { PLANE, TRAIN } TransportKind;//
//

//
typedef struct AdjVexNode {
	int adjvex;// 邻接顶点在顶点数组中的位序
	char endname[MAX_LENGTH_STRING];//终点站
	char linename[MAX_LENGTH_STRING];//班次名
	TransportKind kind;
	Time startTime, stopTime;
	int info_Money; //A到B地 金钱消耗
	Time timeCost; // A到B地 时间消耗
	AdjVexNode* nextArc; // 指向下一个邻接顶点(下一条边或弧)
} AdjVexNode, * AdjVexNodeP, LineNode, * LineNodeP; // 邻接链表的结点类型

typedef struct vexNode {
	VexType cityName[MAX_LENGTH_STRING];//顶点值, VexType是顶点类型,由用户定义
	int cityID;//城市编号
	struct AdjVexNode* firstArc; // 邻接链表的头指针
	int arcNum;//路线数
}VexNode;//顶点数组的元素类型
typedef struct {
	VexNode* vexs; // 顶点数组, 用于存储顶点信息
	int n, e;//顶点数和边(弧)数
	GraphKind kind;//图的类型
	int* tags; // 标志数组, 可用于在图的遍历中标记顶点访间与否
}ALGraph;//邻接表类型

typedef struct {
	VexType v, w;//边端点
	int ID;
	int info_Money;
	int info_Time;
}ArcInfo;
typedef struct {
	int prev;//当前最短路径上该顶点的前驱顶点位序
	int money;//当前最短路径长度
}DistInfoMoney;

typedef struct {
	int prev;//当前最短路径上该顶点的前驱顶点位序
	int time; //(时间)
	Time et; //到达时间
	LineNodeP p;//到prev的车次
}DistInfoTime;

typedef struct {
	int prev;//当前最短路径上该顶点的前驱顶点位序
	int lowcost;//当前最短路径长度
	//LineNodeP p;//到prev的车次
}DistInfoStation;

//接口

//Status visit(VexType v);//访问结点
//Status CreatDG_AL(ALGraph& G);//创建n个顶点和e条边的kind类的图G,vexs为顶点信息,arcs为边信息

Status CreatNodeOnlyGraph_AL(ALGraph& G, VexType* name[], int n);//创建n个顶点的图G
Status DestroyGraph_AL(ALGraph& G); // 销毁图G
int LocateVexByName_AL(ALGraph G, VexType *v); //查找顶点v在图G中的位序
int LocateVexByID_AL(ALGraph G, int ID);
Status GetVex_AL(ALGraph G, int k, VexType& w); // 取图G的k顶点的值到w
Status PutVex_AL(ALGraph G, int k, VexType w);//对图G的k顶点赋值w
int FirstAdjVex_AL(ALGraph G, int k, AdjVexNode& p);
/*若图G中k顶点的邻接链表非空, 则令指针p指向第一个结点, 开返凹具仔储的邻接$点位序, 否则令指针p为NULL, 并返回 - 1 */
int NextAdjvex_AL(ALGraph G, int k, AdjVexNodeP& p);
// 在k顶点的邻接链表中, 令p指向下一个结点
//若p非空, 返回存储在p结点中的下一个邻接顶点的位序, 否则返回 - 1
Status AddArc_AL(ALGraph& G, int k, int m, char *endname, char *linename, TransportKind kind, int info_Money, Time startTime, Time stopTime, Time timeCost);//在图G中增加k顶点到m顶点的边或弧,若为带权图,info为权值,否则为1
Status RemoveArc_One_AL(ALGraph& G, int k, int m, char* lineName);//在图G中删除k顶点到m顶点的边或弧
//Status DFSTraverse_AL(ALGraph G, Status(*visit)(VexType));  // 深度优先遍历图G
//Status BFSTraverse_AL(ALGraph G, Status(*visit)(VexType));//广度优先遍历图G
Status ADDVexNode_AL(ALGraph& G, VexNode w);//增加顶点w
Status RemoveVexNode_AL(ALGraph& G, int k, VexNode& w);//移除图G的k顶点到w//移除节点不释放内存
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