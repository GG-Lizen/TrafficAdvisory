#include"graphH.h"
#include"string.h"

//Status CreatNodeOnlyGraph_AL(ALGraph& G, VexType* name, int* ID, int n);
void inputTime(Time &startTime,Time &endTime) {
	char c1, c2, c3;
	int day, hour, minute;
	while (true)
	{
		printf("���������ʱ��(hh:mm,+d)\n");
		scanf(" %d:%d,%d", &hour, &minute,&day);
		getchar();
		if (hour > 24 || hour < 0) {
			printf("Сʱ�������\n");
			continue;
		}
		if (minute > 60 || minute < 0) {
			printf("�����������\n");
			continue;
		}
		break;
	}
	startTime.day = day;
	startTime.hour = hour;
	startTime.minute = minute;
	
	
	while (true)
	{
		printf("�����뵽��ʱ��(hh:mm,+d)\n");
		scanf(" %d:%d,%d", &hour, &minute,&day);
		getchar();
		if (hour > 24 || hour < 0) {
			printf("Сʱ�������\n");
			continue;
		}
		if (minute > 60 || minute < 0) {
			printf("�����������\n");
			continue;
		}
		break;
	}
	endTime.day = day;
	endTime.hour = hour;
	endTime.minute = minute;

}
void timeCost(Time startTime, Time endTime,Time&cost) {//��������ʱ��
	cost.day = 0;
	cost.hour = 0;
	cost.minute = 0;
	cost.minute = endTime.minute - startTime.minute;
	if (cost.minute < 0) {
		cost.minute += 60;
		cost.hour--;
	}
	cost.hour += endTime.hour - startTime.hour;
	if (cost.hour < 0) {
		cost.hour += 24;
		cost.day--;
	}
	cost.day = 0;

}
void timeCostforOut(Time startTime, Time endTime, Time& cost) {//��������ʱ��
	cost.day = 0;
	cost.hour = 0;
	cost.minute = 0;
	cost.minute = endTime.minute - startTime.minute;
	cost.hour = endTime.hour - startTime.hour;
	if (cost.minute < 0) {
		cost.minute += 60;
		cost.hour--;
	}
	
	if (cost.hour < 0) {
		cost.hour += 24;
		cost.day--;
	}

}
int TimeCmp(Time time1, Time time2)//1>2 ����1 ��ȷ���0 ��С�ڷ���-1
{
	if (time1.day > time2.day) return 1;
	else if (time1.day < time2.day)return -1;
	else if (time1.day == time2.day)
	{
		if (time1.hour > time2.hour) return 1;
		else if (time1.hour < time2.hour)return -1;
		else if (time1.hour == time2.hour) {
			if (time1.minute > time2.minute) return 1;
			else if (time1.minute < time2.minute)return -1;
			else if (time1.minute == time2.minute)
				return 0;
		}

	}
	return MAX_INT;
}
Time TimeADD(Time time1, Time time2) {
	Time T;
	T.day = 0;
	T.hour = 0;
	T.minute = 0;
	T.minute = time1.minute + time2.minute;
	if (T.minute > 59) { T.hour++; T.minute - 59; }
	T.hour = time1.hour + time2.hour;
	if (T.hour > 23) { T.day++; T.hour -= 23; }
	T.day = 0;
	return T;

}
int TimeWeight(const Time& t) {
	return (t.day * 24 + t.hour) * 60 + t.minute;
}
int timeE0(Time time) {
	if (time.day == 0 && time.hour == 0 && time.minute == 0) return 1;
	else return 0;
}
void printTime(Time t) {
	printf("\t%02d:%02d,+%d", t.hour, t.minute, t.day);

}
void ADDCity(ALGraph& G) {
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **              ����Ա               *\n");
	printf("                                          **************************************\n");
	printf("                                          **                                   *\n");
	printf("                                          **             ��ӳ���              *\n");
	printf("                                          **                                   *\n");
	printf("                                          v*************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
	VexNode w;
	char name[MAX_LENGTH_STRING];
	w.arcNum = 0;
	w.cityID = G.n;
	w.firstArc = NULL;
	while (true)
	{
		printf("�����������������BACK���أ�:");
		scanf(" %s",name);
		getchar();
		if (strcmp(name, "BACK") == 0)return;
		if (-1 == LocateVexByName_AL(G, name))
		{
			strcpy(w.cityName, name);
			if (ADDVexNode_AL(G, w) == OK)printf("��ӳɹ�\n");
			else printf("���ʧ��\n");
			system("pause");
			return;
		}
		else {
			printf("%s�Ѵ��ڣ�����������\n",name);
		}
	}

}
void AddLine(ALGraph& G) {//���·��
	LineNode line;
	char StartName[MAX_LENGTH_STRING], EndName[MAX_LENGTH_STRING];
	char linename[MAX_LENGTH_STRING];//�����
	char in;//����
	int startIndex, endIndex,money;
	Time startTime, endTime, timecost;
	TransportKind kind;
	//��Ϣ����
	while (true) {
		printf("�����������У�\n");
		scanf(" %s", StartName);
		getchar();
		if (-1 == LocateVexByName_AL(G, StartName)) {
			printf("%sδ��ͨ·������������\n", StartName);
			continue;
		}
		break;
	}
	startIndex = LocateVexByName_AL(G, StartName);
	while (true)
	{
		printf("�������յ���У�\n");
		scanf(" %s", EndName);
		getchar();
		if (-1 == LocateVexByName_AL(G, EndName)) {
			printf("%sδ��ͨ·������������\n", EndName);
			continue;
		}
		break;
	}
	endIndex = LocateVexByName_AL(G, EndName);
		printf("����������\n");
		scanf(" %s",linename);
		getchar();
	
	inputTime(startTime, endTime);
	timeCost(startTime, endTime, timecost);

		printf("������Ʊ��\n");
		scanf(" %d",&money);
		getchar();


	/*while (true)
	{
		printf("������������:1���ɻ� 2����\n");
		scanf(" %c",&in);
		if (in == '1')kind = PLANE;
		if (in == '2')kind = TRAIN;
		else {
			printf("�������\n");
			continue;
		}
			break;
	}*/

	if(OK==AddArc_AL(G, startIndex, endIndex,EndName,linename, G.vexs->firstArc->kind, money, startTime, endTime, timecost))printf("��ӳɹ�\n");
	else printf("���ʧ��\n");

	system("pause");
}
//��ʾ�����е��յ��������·����Ϣ
Status ShowLine(ALGraph &G ,char startname[], char endname[]) {
	int start, end;
	int flag = 0;
	start = LocateVexByName_AL(G,startname);
	end = LocateVexByName_AL(G, endname);
	LineNodeP p;

	for (p = G.vexs[start].firstArc; p != NULL; NextAdjvex_AL(G,start,p)) {
		if (strcmp(p->endname, endname) == 0) {
			printf( p->linename);
			printTime(p->startTime);
			printTime(p->stopTime);
			printTime(p->timeCost);
			printf("%d ",p->info_Money);
			printf("\n");
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("û�дӸó��г����İ�Σ�");
	}
	return 1;
}
//��ʾϵͳ�����г�����Ϣ
void ShowCity(ALGraph G) {
	int i;
	if (G.n == 0) {
		printf("��ϵͳ��û�г�����Ϣ��\n");
	}
	else {
		printf("ϵͳ����%d�����е���Ϣ\n",G.n );
		printf("                        ");
		for (i = 0; i < G.n; i++) {

			printf("%-16s", G.vexs[i].cityName);
			if (i % 5 == 0 && i != 0) {
				printf("\n");
				printf("                        ");
			}
		}
		printf("\n");
	}
	system("pause");
}
//��ʾϵͳ������·����Ϣ
void ShowLine(ALGraph G) {
	int i;
	if (G.e == 0) {
		printf("��ϵͳ��û�г���·����Ϣ��\n");
	}
	else {
		printf("ϵͳ����%d����·����Ϣ\n", G.e);
		printf("��������|�������|�����||||||||����ʱ��||||||||����ʱ��||||||||||��ʱ|||||||Ʊ��\n");
		LineNode* p = NULL;
		for (i = 0; i < G.n; ++i) {
			p = G.vexs[i].firstArc;
			while (p) {
				printf("%-8s %-8s %-6s ",G.vexs[i].cityName,p->endname,p->linename);
			
				printTime(p->startTime);
				//printf("        ");
				printTime(p->stopTime);
				//printf("        ");
				printTime(p->timeCost);
				printf("    ");
				printf("%d", p->info_Money);
				printf("\n");
				NextAdjvex_AL(G, i, p);
			}
		}
	}
	system("pause");
}
//Status RemoveArc_AL(ALGraph& G, int k, int m);
void DeleteLine(ALGraph &G) {//ɾ��·��
	LineNode line;
	char StartName[MAX_LENGTH_STRING], EndName[MAX_LENGTH_STRING];
	char linename[MAX_LENGTH_STRING];//�����
	char in;//����
	int startIndex, endIndex;
	//��Ϣ����
	while (true) {
		printf("�����������У�\n");
		scanf(" %s", StartName);
		getchar();
		if (-1 == LocateVexByName_AL(G, StartName)) {
			printf("��%s����·������������\n", StartName);
			continue;
		}
		break;
	}
	startIndex = LocateVexByName_AL(G, StartName);
	while (true)
	{
		printf("�������յ���У�\n");
		scanf(" %s", EndName);
		getchar();
		if (-1 == LocateVexByName_AL(G, StartName)) {
			printf("��%s����·������������\n", StartName);
			continue;
		}
		break;
	}
	endIndex = LocateVexByName_AL(G, EndName);
	printf("����������\n");
	scanf(" %s", linename);
	getchar();
	if (!RemoveArc_One_AL(G, startIndex, endIndex, linename)) {
		printf("ɾ��ʧ����������\n");

	}
	else printf("ɾ���ɹ�\n");
	system("pause");
}

void DeleteCity(ALGraph& G)
{
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **              ����Ա               *\n");
	printf("                                          **************************************\n");
	printf("                                          **                                   *\n");
	printf("                                          **             ɾ������              *\n");
	printf("                                          **                                   *\n");
	printf("                                          v*************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
	VexNode vex;
	char name[MAX_LENGTH_STRING];
	//��Ϣ����
	while (true) {
		printf("��������(����BACK����)��\n");
		scanf(" %s", name);
		getchar();
		if (strcmp(name, "BACK")==0)return;
		if (-1 == LocateVexByName_AL(G, name)) {
			printf("�޳���%s����������\n", name);
			continue;
		}
		break;
	}
	if (OK == RemoveVexNode_AL(G, LocateVexByName_AL(G, name), vex))printf("ɾ���ɹ�\n");
	else printf("ɾ��ʧ��\n");
	system("pause");
	return;
}

void Dijkstra_Money(ALGraph G, int v0, DistInfoMoney* &dis) {

	LineNodeP p;//
	dis = (DistInfoMoney*)malloc(sizeof(DistInfoMoney) * G.n);
	int i, m, k, min;
	for (i = 0; i < G.n; ++i) {//��ʼ��
		dis[i].money = INFINITY;
		G.tags[i] = UNSELECTED; //��δ�ҵ����·
	}
	for (p = G.vexs[v0].firstArc; p != NULL; p = p->nextArc) {
		dis[p->adjvex].prev = v0;
		if (p->info_Money < dis[p->adjvex].money) {
			dis[p->adjvex].money = p->info_Money;
		}
	}

	dis[v0].prev = -1;
	dis[v0].money = 0; //Դ�㵽Դ�����·ȨֵΪ0
	G.tags[v0] = SELECTED;
	for (m = 1; m < G.n; m++) {
		min = INFINITY; k = 0;
		for (i = 0; i < G.n; i++)
			if (0 == G.tags[i] && dis[i].money < min) {
				k = i; min = dis[k].money;
			}
		G.tags[k] = SELECTED;
		for (p = G.vexs[k].firstArc; p != NULL; p = p->nextArc) {
			i = p->adjvex;

			if (UNSELECTED == G.tags[i] && dis[k].money + p->info_Money < dis[i].money) {
				dis[i].money = dis[k].money + p->info_Money;
				dis[i].prev = k;
			}
		}

	}




}//dijkstra_Money
void Outputpath_Money(ALGraph G, DistInfoMoney Dist[], int k, int& cost,Time &arriveT,int &timecost) {
	if (-1 == k) return;
	Time timeWait;
	
	LineNodeP p, minP;
	if (Dist[k].prev == -1)return;
	p = G.vexs[Dist[k].prev].firstArc;
	minP = p;
	while (p != NULL) {
		if (p->info_Money < minP->info_Money && p->adjvex == k)
		{
			minP = p;
		}
		p = p->nextArc;
	}
	cost += minP->info_Money;
	if (timeE0(arriveT))arriveT = minP->stopTime;
	timeCost(minP->stopTime, arriveT, timeWait);
	if (timeWait.day < 0 || timeWait.hour < 0 || timeWait.minute < 0)
		timecost +=  TimeWeight(minP->timeCost);
	else	timecost += TimeWeight(timeWait) + TimeWeight(minP->timeCost);
	arriveT = minP->startTime;
	Outputpath_Money(G, Dist, Dist[k].prev, cost, arriveT,timecost);
	printf(" %-8s �� %-8s , ��� %-6s ,����ʱ��:", G.vexs[Dist[k].prev].cityName, minP->endname, minP->linename);
	printTime(minP->startTime);
	printf("        ");
	printf("��վʱ��:");
	printTime(minP->stopTime);
	printf("        ");
	printf("Ʊ�ۣ�%d", minP->info_Money);
	printf("\n");
	if (timeE0(timeWait))return;
	  printf(" ��ת�Ⱥ�ʱ��:%d���Ӻ�\n", TimeWeight(timeWait));

	
}
//����ʱ��·��
int TimeTransWeight( Time t1, Time t2) {
	Time t;
	t.day = 0;
	t.hour = 0;
	t.minute = 0;
	t.minute = t1.minute - t2.minute;
	if (t.minute < 0) {
		t.minute += 60;
		t.hour--;
	}
	t.hour = t1.hour - t2.hour;
	if (t.hour < 0) {
		t.hour += 24;
		t.day--;
	}
	if (t1.day < t2.day) {
		t.day++;
	}

	return  t.hour * 60 + t.minute;

}
void Dijkstra_Time(ALGraph G, int v0, DistInfoTime*& dis,Time arriveT) {

	LineNodeP p;//
	dis = (DistInfoTime*)malloc(sizeof(DistInfoTime) * G.n);
	int i, m, k, min;
	Time  waitTcost,temp;
	for (i = 0; i < G.n; ++i) {//��ʼ��
		dis[i].time= INFINITY;
		dis[i].et.day = 0; dis[i].et.hour = 0; dis[i].et.minute = 0;
		G.tags[i] = UNSELECTED; //��δ�ҵ����·
	}
	for (p = G.vexs[v0].firstArc; p != NULL; p = p->nextArc) {
		dis[p->adjvex].prev = v0;
		timeCost(arriveT, p->startTime, waitTcost);
		if (TimeWeight(p->timeCost)+TimeWeight(waitTcost) < dis[p->adjvex].time) {
			dis[p->adjvex].time = TimeWeight(p->timeCost)+TimeWeight(waitTcost);
			dis[p->adjvex].p = p;
			dis[p->adjvex].et.day = 0; dis[p->adjvex].et.hour = p->stopTime.hour; dis[p->adjvex].et.minute = p->stopTime.minute;

		}
	}

	dis[v0].prev = -1;
	dis[v0].time = 0; //Դ�㵽Դ�����·ȨֵΪ0
	dis[v0].et = arriveT;
	dis[v0].p = NULL;
	G.tags[v0] = SELECTED;
	for (m = 1; m < G.n; m++) {
		min = INFINITY; k = 0;
		for (i = 0; i < G.n; i++)
			if (0 == G.tags[i] && dis[i].time < min) {
				k = i; min = dis[k].time;
			}
		G.tags[k] = SELECTED;
		for (p = G.vexs[k].firstArc; p != NULL; p = p->nextArc) {
			i = p->adjvex;
			timeCost(dis[k].et, p->startTime, waitTcost);
			if (UNSELECTED == G.tags[i] && dis[k].time +TimeWeight(waitTcost)+ TimeWeight(p->timeCost) < dis[i].time) {
				dis[i].time = dis[k].time + TimeWeight(waitTcost) + TimeWeight(p->timeCost);
				dis[i].prev = k;
				temp = TimeADD(TimeADD(dis->et, waitTcost), p->timeCost);
				dis[i].et.day =0 ; dis[i].et.hour =p->stopTime.hour; dis[i].et.minute = p->stopTime.minute;
				dis[p->adjvex].p = p;
			}
		}

	}






}//dijkstra_Time
void Outputpath_Time(ALGraph G, DistInfoTime Dist[], int k, int& cost, Time &arriveT) {
	if (-1 == k) return;
	Time timeWait;

	LineNodeP p;
	if (Dist[k].prev == -1)return;
	p = G.vexs[Dist[k].prev].firstArc;
	if (timeE0(arriveT))arriveT = Dist[k].p->stopTime;
	timeCost(Dist[k].p->stopTime, arriveT, timeWait);
	if (timeWait.day >= 0 && timeWait.hour >= 0 && timeWait.minute >= 0)
	cost +=   TimeWeight(timeWait);
	cost += TimeWeight(Dist[k].p->timeCost);
	arriveT = Dist[k].p->startTime;
	Outputpath_Time(G, Dist, Dist[k].prev, cost, arriveT);
	printf(" %-8s �� %-8s , ��� %-6s ,����ʱ��:", G.vexs[Dist[k].prev].cityName, Dist[k].p->endname, Dist[k].p->linename);
	printTime(Dist[k].p->startTime);
	//printf("        ");
	printf("��վʱ��:");
	printTime(Dist[k].p->stopTime);
	//printf("        ");
	printf("ʱ�����ģ�%d����", TimeWeight(Dist[k].p->timeCost));
	printf("\n");
	if (timeE0(timeWait))return;
	printf(" ��ת�Ⱥ�ʱ��:%d���Ӻ�\n", TimeWeight(timeWait));

}

void Dijkstra_Station(ALGraph G, int i, DistInfoStation*& Dist) {
	int j, m, k, min;
	AdjVexNodeP p;
	Dist = (DistInfoStation*)malloc(G.n * sizeof(DistInfoStation));
	for (j = 0; j < G.n; j++) {// ��ʼ��
		Dist[j].lowcost = INFINITY;
		G.tags[j] = UNSELECTED;//���ж�������ڼ���U��
	}
	for (p = G.vexs[i].firstArc; p != NULL; p = p->nextArc) {
		// Դ��i���������л�����Ϣ����Dist
		Dist[p->adjvex].prev = i;
		Dist[p->adjvex].lowcost = 1;

	}
	Dist[i].prev = -1; Dist[i].lowcost = 0; // Դ��i��Ϣ���� Dist
	G.tags[i] = SELECTED;//��ʼ����U����Դ��i
	for (m = 1; m < G.n; m++) {//��·����������,����ˮԴ�㵽�����ӵ�����·��
		min = INFINITY; k = 0;
		for (j = 0; j < G.n; j++)
			if (0 == G.tags[j] && Dist[j].lowcost < min) {
				k = j; min = Dist[k].lowcost;
			}
		G.tags[k] = SELECTED; // ��k������˼���U
		for (p = G.vexs[k].firstArc; p != NULL; p = p->nextArc) {//����Dist ����
			j = p->adjvex;
			if (UNSELECTED == G.tags[j] && Dist[k].lowcost + 1 < Dist[j].lowcost) {
				Dist[j].lowcost = Dist[k].lowcost + 1;
				Dist[j].prev = k;
			}

		}


	}

}
void Outputpath_Station(ALGraph G, DistInfoStation Dist[], int k, int& cost) {
	if (-1 == k) return;
	LineNodeP p;
	cost++;
	if (Dist[k].prev == -1)return;
	int kj = Dist[k].prev;

	p = G.vexs[Dist[k].prev].firstArc;
	while (p->adjvex!=k)
	{
		p = p->nextArc;
	}
	
	Outputpath_Station(G, Dist, Dist[k].prev, cost);
	printf(" %-8s �� %-8s , �����:\n", G.vexs[Dist[k].prev].cityName, p->endname);
	while (p!=NULL)
	{
		if (p->adjvex != k) {
			p = p->nextArc;
			continue;
		}
		printf("                          ��� %-6s ,����ʱ��:", p->linename);
		printTime(p->startTime);
		printf("        ");
		printf("��վʱ��:");
		printTime(p->stopTime);
		printf("        ");
		printf("Ʊ�ۣ�%d", p->info_Money);
		printf("\n");
		p = p->nextArc;
	}
	printf("\n");
}