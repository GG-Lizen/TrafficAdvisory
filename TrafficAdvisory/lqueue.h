//#pragma once
//#include"base.h"
//
//
//typedef struct LQNode_Money {
//    DistInfoMoney data;
//    struct LQNode_Money* next;
//} LQNode_Money, * QueuePtr_Money; // ���ͽ��ָ������
//typedef struct {
//    QueuePtr_Money  front;  // ��ͷָ��
//    QueuePtr_Money  rear;   // ��βָ��
//} LQueue_Money;  // ����������
//
//
//typedef struct LQNode_Time {
//    DistInfoTime data;
//    struct LQNode_Time* next;
//} LQNode_Time, * QueuePtr_Time; // ���ͽ��ָ������
//typedef struct {
//    QueuePtr_Time front;  // ��ͷָ��
//    QueuePtr_Time  rear;   // ��βָ��
//} LQueue_Time;  // ����������
//
//Status InitQueue_LQ_Money(LQueue_Money& Q);//��������
//Status EnQueue_LQ_SortMoney(LQueue_Money& Q, DistInfoMoney e);//���
//Status DeQueue_LQ_SortMoney(LQueue_Money& Q, DistInfoMoney& e);//����
//Status QueueEmpty_LQ(LQueue_Money Q);
///* �ж�������Q�Ƿ�Ϊ�ն��С�           */
///* ��Q�ǿն��У��򷵻�TRUE������FALSE��*/
//
//
///* ��������Q�ĳ��Ȳ�������ֵ */
//Status InitQueue_LQ_Time(LQueue_Time& Q);
//Status EnQueue_LQ_SortTime(LQueue_Time& Q, DistInfoTime e);
//Status DeQueue_LQ_SortTime(LQueue_Time& Q, DistInfoTime& e);
//Status QueueEmpty_LQ_Time(LQueue_Time Q);
//int QueueLength_LQ_Time(LQueue_Time Q);
