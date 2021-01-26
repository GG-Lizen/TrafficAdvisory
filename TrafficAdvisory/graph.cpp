//接口实现
#include"lqueue.h"
#include"graphH.h"



Status CreatNodeOnlyGraph_AL(ALGraph& G, VexType* name[], int n) {
    int i, j, k;
    VexType v, w;
    AdjVexNodeP p;
    G.n = n;//读入顶点数
    G.e = 0;//读入弧数
    G.vexs = (VexNode*)malloc(n * sizeof(VexNode));
    G.tags = (int*)malloc(n * sizeof(int));
    if (G.vexs == NULL)return OVERFLOW;
    if (G.tags == NULL)return OVERFLOW;
    for (i = 0; i < G.n; i++)
    {
        G.tags[i] = UNVISITED;
        strcpy(G.vexs[i].cityName, name[i]);
        G.vexs[i].arcNum = 0;
        G.vexs[i].firstArc = NULL;
    }

    return OK;
}

// 销毁图G
Status DestroyGraph_AL(ALGraph& G)
{
 
    int i;
    AdjVexNodeP p, q;
    //销毁顶点的邻接链表
    if (G.vexs == NULL || G.tags == NULL) return ERROR;//图为空
    for (i = 0; i < G.n; i++) {
        p = G.vexs[i].firstArc;
        while (p != NULL) {
            q = p->nextArc;
            free(p);
            p = q;
        }
    }
    //销毁顶点数组
    free(G.vexs);
    //销毁标志数组
    free(G.tags);
    G.n = 0;
    G.e = 0;
    return OK;




}
//查找顶点v在图G中的位序
int LocateVexByName_AL(ALGraph G, VexType *v) {
    int i;
    for (i = 0; i < G.n; i++)
        if (0==strcmp(v,G.vexs[i].cityName)) return i;
    return -1;
}
int LocateVexByID_AL(ALGraph G, int ID) {
    int i;
    for (i = 0; i < G.n; i++)
        if (ID== G.vexs[i].cityID) return i;
    return -1;
}
Status GetCityName_AL(ALGraph G, int k, VexType w[]) // 取图G的k城市名到w 
{
    if (k<0 || k>G.n)return ERROR;
    strcpy(w,G.vexs[k].cityName);
    return OK;
}
Status GetCityID_AL(ALGraph G, int k, int& w) // 取图G的k城市编号到w 
{
    if (k<0 || k>G.n)return ERROR;
    w = G.vexs[k].cityID;
    return OK;
}
Status PutVex_AL(ALGraph G, int k, VexType w[])//对图G的k城市名赋值w
{
    if (k<0 || k>G.n)return ERROR;
    strcpy(G.vexs[k].cityName,w);
    return OK;
}

/*若图G中k顶点的邻接链表非空, 则令指针p指向第一个结点, 并返回其存储的邻接顶点位序, 否则令指针p为NULL, 并返回 - 1 */
int FirstAdjVex_AL(ALGraph G, int k, AdjVexNodeP& p) {
    if (k < 0 || k >= G.n)return -1;//k顶点不存在
    p = G.vexs[k].firstArc;
    if (p != NULL)return p->adjvex;//返回第一个结点存储的位序
    else return -1;//k无顶点
}

// 在k顶点的邻接链表中, 令p指向下一个结点
//若p非空, 返回存储在p结点中的下一个邻接顶点的位序, 否则返回 - 1
int NextAdjvex_AL(ALGraph G, int k, AdjVexNodeP& p) {
    if (k<0 || k>G.n) return ERROR;
    if (NULL == p) return -1;
    p = p->nextArc;
    if (p != NULL)return p->adjvex;
    else return -1;
}

//在图G中增加k顶点到m顶点的边或弧,若为带权图,info为权值,否则为1
Status AddArc_AL(ALGraph& G, int k, int m,char *endname,char *linename, TransportKind kind, int info_Money,Time startTime,Time stopTime, Time timeCost) {
    AdjVexNodeP p;
    if (k<0 || k>G.n || m<0 || m>G.n)return ERROR;
    if ((UDG == G.kind || DG == G.kind))return ERROR;///图类型均为带权图
    p = G.vexs[k].firstArc;
    p = (AdjVexNode*)malloc(sizeof(AdjVexNode));//为m分配p结点
    if (NULL == p)return OVERFLOW;
    p->adjvex = m;strcpy(p->endname, endname);strcpy( p->linename ,linename); p->kind = kind; p->info_Money = info_Money; p->startTime = startTime; p->stopTime = stopTime; p->timeCost = timeCost;
    p->nextArc = G.vexs[k].firstArc;//在k顶点的邻接链表表头插入p结点
    G.vexs[k].firstArc = p;
    G.vexs[k].arcNum++;
    G.e++;
    return OK;

}

//在图G中删除k顶点到m顶点的边或弧
Status RemoveArc_One_AL(ALGraph& G, int k, int m,char *lineName) {
    AdjVexNodeP p, q = NULL;
    if (k<0 || k>G.n || m<0 || m>G.n) return ERROR;
    p = G.vexs[k].firstArc;
    while (p != NULL) {

        if (m == p->adjvex&&0==strcmp(lineName,p->linename)) {
            if (p == G.vexs[k].firstArc) {
                G.vexs[k].firstArc = p->nextArc;
                free(p);
            }
            else {
                q->nextArc = p->nextArc;
                free(p);
            }
            G.e--;
            G.vexs[k].arcNum--;
            return OK;
        }
        q = p;
        p = p->nextArc;
    }
    return ERROR;//找不到<k,m>的linename班次
}

Status RemoveArc_ALL_AL(ALGraph& G, int k, int m) {
    AdjVexNodeP p, q = NULL;
    if (k<0 || k>G.n || m<0 || m>G.n) return ERROR;
    p = G.vexs[k].firstArc;
    while (p != NULL) {

        if (m == p->adjvex) {
            if (p == G.vexs[k].firstArc) {
                G.vexs[k].firstArc = p->nextArc;
                q = p->nextArc;
                free(p);
                p = q->nextArc;
            }
            else {
                q->nextArc = p->nextArc;
                free(p);
                p = q;
            }
            G.e--;
            G.vexs[k].arcNum--;
           
        }
        q = p;
        p = p->nextArc;
    }
    return OK;//找不到<k,m>的linename班次
}


Status ADDVexNode_AL(ALGraph& G, VexNode w){//增加顶点w
    int i;
    VexNode* vptr;
    int* iptr;
    if (G.vexs == NULL || G.tags == NULL)return ERROR;
    i = LocateVexByName_AL(G, w.cityName);
    if (i == -1) {
        if (sizeof(G.vexs) / sizeof(VexNode) <= G.n)//内存不足重新开辟
        {
            vptr = (VexNode*)realloc(G.vexs, sizeof(VexNode) * (G.n + 1));
            if (vptr == NULL)return OVERFLOW;
            else G.vexs = vptr;
        }
        if (sizeof(G.tags) / sizeof(int) <= G.n)
        {
            iptr = (int*)realloc(G.tags, sizeof(int) * (G.n + 1));
            if (iptr == NULL)return OVERFLOW;
            else G.tags = iptr;
        }
        G.vexs[G.n] = w;
        G.tags[G.n] = UNVISITED;
        G.n++;

        return OK;
    }
    else {
        return ERROR;
    }
}

Status RemoveVexNode_AL(ALGraph& G, int k, VexNode& w) {//移除图G的k顶点到w//k是位序
    if (G.vexs == NULL || G.tags == NULL)return ERROR;
    if (k<0 || k>G.n) return ERROR;
    int i, j;
    AdjVexNodeP p;
    // int* index = (int*)malloc(sizeof(int) * (G.n - k - 1));//储存被修改结点的新下标
    w = G.vexs[k];
    for (i = 0; i < G.n; i++) {
        if (i == k)continue;
        RemoveArc_ALL_AL(G, i, k);
    }
    //查找需要修改的结点
    for (i = 0; i < G.n; i++) {
        if (i == k) continue;
        p = G.vexs[i].firstArc;
        while (p != NULL)
        {
            if (p->adjvex > k)p->adjvex--;
            NextAdjvex_AL(G, i, p);
        }
    }


    for (i = k; i < G.n - 1; i++) {//数组前移
        G.vexs[i] = G.vexs[i + 1];
    }
    for (i = k; i < G.n - 1; i++) {//数组前移
        G.tags[i] = G.tags[i + 1];
    }
    G.n--;
    return OK;
}







