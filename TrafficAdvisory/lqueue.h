//#pragma once
//#include"base.h"
//
//
//typedef struct LQNode_Money {
//    DistInfoMoney data;
//    struct LQNode_Money* next;
//} LQNode_Money, * QueuePtr_Money; // 结点和结点指针类型
//typedef struct {
//    QueuePtr_Money  front;  // 队头指针
//    QueuePtr_Money  rear;   // 队尾指针
//} LQueue_Money;  // 链队列类型
//
//
//typedef struct LQNode_Time {
//    DistInfoTime data;
//    struct LQNode_Time* next;
//} LQNode_Time, * QueuePtr_Time; // 结点和结点指针类型
//typedef struct {
//    QueuePtr_Time front;  // 队头指针
//    QueuePtr_Time  rear;   // 队尾指针
//} LQueue_Time;  // 链队列类型
//
//Status InitQueue_LQ_Money(LQueue_Money& Q);//创建队列
//Status EnQueue_LQ_SortMoney(LQueue_Money& Q, DistInfoMoney e);//入队
//Status DeQueue_LQ_SortMoney(LQueue_Money& Q, DistInfoMoney& e);//出队
//Status QueueEmpty_LQ(LQueue_Money Q);
///* 判定链队列Q是否为空队列。           */
///* 若Q是空队列，则返回TRUE，否则FALSE。*/
//
//
///* 求链队列Q的长度并返回其值 */
//Status InitQueue_LQ_Time(LQueue_Time& Q);
//Status EnQueue_LQ_SortTime(LQueue_Time& Q, DistInfoTime e);
//Status DeQueue_LQ_SortTime(LQueue_Time& Q, DistInfoTime& e);
//Status QueueEmpty_LQ_Time(LQueue_Time Q);
//int QueueLength_LQ_Time(LQueue_Time Q);
