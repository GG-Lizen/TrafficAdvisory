//�ӿ�ʵ��
#include"lqueue.h"
#include"graphH.h"



Status CreatNodeOnlyGraph_AL(ALGraph& G, VexType* name[], int n) {
    int i, j, k;
    VexType v, w;
    AdjVexNodeP p;
    G.n = n;//���붥����
    G.e = 0;//���뻡��
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

// ����ͼG
Status DestroyGraph_AL(ALGraph& G)
{
 
    int i;
    AdjVexNodeP p, q;
    //���ٶ�����ڽ�����
    if (G.vexs == NULL || G.tags == NULL) return ERROR;//ͼΪ��
    for (i = 0; i < G.n; i++) {
        p = G.vexs[i].firstArc;
        while (p != NULL) {
            q = p->nextArc;
            free(p);
            p = q;
        }
    }
    //���ٶ�������
    free(G.vexs);
    //���ٱ�־����
    free(G.tags);
    G.n = 0;
    G.e = 0;
    return OK;




}
//���Ҷ���v��ͼG�е�λ��
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
Status GetCityName_AL(ALGraph G, int k, VexType w[]) // ȡͼG��k��������w 
{
    if (k<0 || k>G.n)return ERROR;
    strcpy(w,G.vexs[k].cityName);
    return OK;
}
Status GetCityID_AL(ALGraph G, int k, int& w) // ȡͼG��k���б�ŵ�w 
{
    if (k<0 || k>G.n)return ERROR;
    w = G.vexs[k].cityID;
    return OK;
}
Status PutVex_AL(ALGraph G, int k, VexType w[])//��ͼG��k��������ֵw
{
    if (k<0 || k>G.n)return ERROR;
    strcpy(G.vexs[k].cityName,w);
    return OK;
}

/*��ͼG��k������ڽ�����ǿ�, ����ָ��pָ���һ�����, ��������洢���ڽӶ���λ��, ������ָ��pΪNULL, ������ - 1 */
int FirstAdjVex_AL(ALGraph G, int k, AdjVexNodeP& p) {
    if (k < 0 || k >= G.n)return -1;//k���㲻����
    p = G.vexs[k].firstArc;
    if (p != NULL)return p->adjvex;//���ص�һ�����洢��λ��
    else return -1;//k�޶���
}

// ��k������ڽ�������, ��pָ����һ�����
//��p�ǿ�, ���ش洢��p����е���һ���ڽӶ����λ��, ���򷵻� - 1
int NextAdjvex_AL(ALGraph G, int k, AdjVexNodeP& p) {
    if (k<0 || k>G.n) return ERROR;
    if (NULL == p) return -1;
    p = p->nextArc;
    if (p != NULL)return p->adjvex;
    else return -1;
}

//��ͼG������k���㵽m����ı߻�,��Ϊ��Ȩͼ,infoΪȨֵ,����Ϊ1
Status AddArc_AL(ALGraph& G, int k, int m,char *endname,char *linename, TransportKind kind, int info_Money,Time startTime,Time stopTime, Time timeCost) {
    AdjVexNodeP p;
    if (k<0 || k>G.n || m<0 || m>G.n)return ERROR;
    if ((UDG == G.kind || DG == G.kind))return ERROR;///ͼ���;�Ϊ��Ȩͼ
    p = G.vexs[k].firstArc;
    p = (AdjVexNode*)malloc(sizeof(AdjVexNode));//Ϊm����p���
    if (NULL == p)return OVERFLOW;
    p->adjvex = m;strcpy(p->endname, endname);strcpy( p->linename ,linename); p->kind = kind; p->info_Money = info_Money; p->startTime = startTime; p->stopTime = stopTime; p->timeCost = timeCost;
    p->nextArc = G.vexs[k].firstArc;//��k������ڽ������ͷ����p���
    G.vexs[k].firstArc = p;
    G.vexs[k].arcNum++;
    G.e++;
    return OK;

}

//��ͼG��ɾ��k���㵽m����ı߻�
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
    return ERROR;//�Ҳ���<k,m>��linename���
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
    return OK;//�Ҳ���<k,m>��linename���
}


Status ADDVexNode_AL(ALGraph& G, VexNode w){//���Ӷ���w
    int i;
    VexNode* vptr;
    int* iptr;
    if (G.vexs == NULL || G.tags == NULL)return ERROR;
    i = LocateVexByName_AL(G, w.cityName);
    if (i == -1) {
        if (sizeof(G.vexs) / sizeof(VexNode) <= G.n)//�ڴ治�����¿���
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

Status RemoveVexNode_AL(ALGraph& G, int k, VexNode& w) {//�Ƴ�ͼG��k���㵽w//k��λ��
    if (G.vexs == NULL || G.tags == NULL)return ERROR;
    if (k<0 || k>G.n) return ERROR;
    int i, j;
    AdjVexNodeP p;
    // int* index = (int*)malloc(sizeof(int) * (G.n - k - 1));//���汻�޸Ľ������±�
    w = G.vexs[k];
    for (i = 0; i < G.n; i++) {
        if (i == k)continue;
        RemoveArc_ALL_AL(G, i, k);
    }
    //������Ҫ�޸ĵĽ��
    for (i = 0; i < G.n; i++) {
        if (i == k) continue;
        p = G.vexs[i].firstArc;
        while (p != NULL)
        {
            if (p->adjvex > k)p->adjvex--;
            NextAdjvex_AL(G, i, p);
        }
    }


    for (i = k; i < G.n - 1; i++) {//����ǰ��
        G.vexs[i] = G.vexs[i + 1];
    }
    for (i = k; i < G.n - 1; i++) {//����ǰ��
        G.tags[i] = G.tags[i + 1];
    }
    G.n--;
    return OK;
}







