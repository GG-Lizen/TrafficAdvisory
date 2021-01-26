//#include"lqueue.h"
////��������
//Status InitQueue_LQ_Money(LQueue_Money& Q){
//    Q.front = NULL;
//    Q.rear = NULL;
//    return OK;
//}
//
////���
//Status EnQueue_LQ_SortMoney(LQueue_Money& Q, DistInfoMoney e) {
//    LQNode_Money* p,*q,*pre=NULL;
//    p = (LQNode_Money*)malloc(sizeof(LQNode_Money));
//    if (NULL == p) return OVERFLOW;
//    p->data = e; p->next = NULL;
//    if (NULL == Q.front)Q.front = p;
//    else {
//        q = Q.front;
//        
//        while (q!= NULL) {
//            
//            if (p->data.money < q->data.money) {
//                if (q == Q.front) {
//                    p->next = q;
//                    Q.front = p;
//                }
//                else {
//                    pre->next = p;
//                    p->next = q;
//                }
//                return OK;
//        }
//            pre = q;
//            q = q->next;
//        }
//        
//    }
//
//    if (NULL != Q.rear) {
//        Q.rear->next = p;
//    }
//    Q.rear = p;
// 
//    return OK;
//}
//
////����
//Status DeQueue_LQ_SortMoney(LQueue_Money& Q, DistInfoMoney& e) {
//    LQNode_Money* p;
//    if (NULL == Q.front) return ERROR;
//    p = Q.front;
//    e = p->data;
//    Q.front = p->next;
//    if (Q.rear == p) Q.rear = NULL;
//    free(p);
//    return OK;
//}
//Status QueueEmpty_LQ(LQueue_Money Q)
///* �ж�������Q�Ƿ�Ϊ�ն��С�           */
///* ��Q�ǿն��У��򷵻�TRUE������FALSE��*/
//{
//
//    if (Q.front == NULL || NULL == Q.rear)
//        return TRUE;
//    return FALSE;
//}
//
//int QueueLength_LQ(LQueue_Money Q)
///* ��������Q�ĳ��Ȳ�������ֵ */
//{
//    if (Q.front == NULL || Q.rear == NULL) return 0;
//    int count = 0;
//    QueuePtr_Money p = Q.front;
//    while (p != Q.rear->next)
//    {
//        p = p->next;
//        count++;
//    }
//    return count;
//}
//
//Status InitQueue_LQ_Time(LQueue_Money& Q) {
//    Q.front = NULL;
//    Q.rear = NULL;
//    return OK;
//}
//
//
//
//
//
//
//
//
//
//Status InitQueue_LQ_Time(LQueue_Time& Q) {
//    Q.front = NULL;
//    Q.rear = NULL;
//    return OK;
//}
//
////���
//Status EnQueue_LQ_SortTime(LQueue_Time& Q, DistInfoTime e) {
//    LQNode_Time* p, * q, * pre = NULL;
//    p = (LQNode_Time*)malloc(sizeof(LQNode_Time));
//    if (NULL == p) return OVERFLOW;
//    p->data = e; p->next = NULL;
//    if (NULL == Q.front)Q.front = p;
//    else {
//        q = Q.front;
//
//        while (q != NULL) {
//
//            if (p->data.time < q->data.time) {
//                if (q == Q.front) {
//                    p->next = q;
//                    Q.front = p;
//                }
//                else {
//                    pre->next = p;
//                    p->next = q;
//                }
//                return OK;
//            }
//            pre = q;
//            q = q->next;
//        }
//    }
//    if (NULL != Q.rear) {
//        Q.rear->next = p;
//    }
//    Q.rear = p;
//    return OK;
//}
//
////����
//Status DeQueue_LQ_SortTime(LQueue_Time& Q, DistInfoTime& e) {
//    LQNode_Time* p;
//    if (NULL == Q.front) return ERROR;
//    p = Q.front;
//    e = p->data;
//    Q.front = p->next;
//    if (Q.rear == p) Q.rear = NULL;
//    free(p);
//    return OK;
//}
//Status QueueEmpty_LQ_Time(LQueue_Time Q)
///* �ж�������Q�Ƿ�Ϊ�ն��С�           */
///* ��Q�ǿն��У��򷵻�TRUE������FALSE��*/
//{
//
//    if (Q.front == NULL || NULL == Q.rear)
//        return TRUE;
//    return FALSE;
//}
//
//int QueueLength_LQ_Time(LQueue_Time Q)
///* ��������Q�ĳ��Ȳ�������ֵ */
//{
//    if (Q.front == NULL || Q.rear == NULL) return 0;
//    int count = 0;
//    QueuePtr_Time p = Q.front;
//    while (p != Q.rear->next)
//    {
//        p = p->next;
//        count++;
//    }
//    return count;
//}
//
//
