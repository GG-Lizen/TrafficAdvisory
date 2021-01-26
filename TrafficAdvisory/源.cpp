#include"graphH.h"
#include"string.h"

//Status CreatNodeOnlyGraph_AL(ALGraph& G, VexType* name, int* ID, int n);
void inputTime(Time &startTime,Time &endTime) {
	char c1, c2, c3;
	int day, hour, minute;
	while (true)
	{
		printf("请输入出发时间(hh:mm,+d)\n");
		scanf(" %d:%d,%d", &hour, &minute,&day);
		getchar();
		if (hour > 24 || hour < 0) {
			printf("小时输入错误\n");
			continue;
		}
		if (minute > 60 || minute < 0) {
			printf("分钟输入错误\n");
			continue;
		}
		break;
	}
	startTime.day = day;
	startTime.hour = hour;
	startTime.minute = minute;
	
	
	while (true)
	{
		printf("请输入到达时间(hh:mm,+d)\n");
		scanf(" %d:%d,%d", &hour, &minute,&day);
		getchar();
		if (hour > 24 || hour < 0) {
			printf("小时输入错误\n");
			continue;
		}
		if (minute > 60 || minute < 0) {
			printf("分钟输入错误\n");
			continue;
		}
		break;
	}
	endTime.day = day;
	endTime.hour = hour;
	endTime.minute = minute;

}
void timeCost(Time startTime, Time endTime,Time&cost) {//计算所用时间
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
void timeCostforOut(Time startTime, Time endTime, Time& cost) {//计算所用时间
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
int TimeCmp(Time time1, Time time2)//1>2 返回1 相等返回0 ，小于返回-1
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
	printf("                                          **              管理员               *\n");
	printf("                                          **************************************\n");
	printf("                                          **                                   *\n");
	printf("                                          **             添加城市              *\n");
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
		printf("请输入城市名（输入BACK返回）:");
		scanf(" %s",name);
		getchar();
		if (strcmp(name, "BACK") == 0)return;
		if (-1 == LocateVexByName_AL(G, name))
		{
			strcpy(w.cityName, name);
			if (ADDVexNode_AL(G, w) == OK)printf("添加成功\n");
			else printf("添加失败\n");
			system("pause");
			return;
		}
		else {
			printf("%s已存在，请重新输入\n",name);
		}
	}

}
void AddLine(ALGraph& G) {//添加路线
	LineNode line;
	char StartName[MAX_LENGTH_STRING], EndName[MAX_LENGTH_STRING];
	char linename[MAX_LENGTH_STRING];//班次名
	char in;//输入
	int startIndex, endIndex,money;
	Time startTime, endTime, timecost;
	TransportKind kind;
	//信息输入
	while (true) {
		printf("请输入起点城市：\n");
		scanf(" %s", StartName);
		getchar();
		if (-1 == LocateVexByName_AL(G, StartName)) {
			printf("%s未开通路线请重新输入\n", StartName);
			continue;
		}
		break;
	}
	startIndex = LocateVexByName_AL(G, StartName);
	while (true)
	{
		printf("请输入终点城市：\n");
		scanf(" %s", EndName);
		getchar();
		if (-1 == LocateVexByName_AL(G, EndName)) {
			printf("%s未开通路线请重新输入\n", EndName);
			continue;
		}
		break;
	}
	endIndex = LocateVexByName_AL(G, EndName);
		printf("请输入班次名\n");
		scanf(" %s",linename);
		getchar();
	
	inputTime(startTime, endTime);
	timeCost(startTime, endTime, timecost);

		printf("请输入票价\n");
		scanf(" %d",&money);
		getchar();


	/*while (true)
	{
		printf("请输入类型名:1、飞机 2、火车\n");
		scanf(" %c",&in);
		if (in == '1')kind = PLANE;
		if (in == '2')kind = TRAIN;
		else {
			printf("输入错误\n");
			continue;
		}
			break;
	}*/

	if(OK==AddArc_AL(G, startIndex, endIndex,EndName,linename, G.vexs->firstArc->kind, money, startTime, endTime, timecost))printf("添加成功\n");
	else printf("添加失败\n");

	system("pause");
}
//显示起点城市到终点城市所有路线信息
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
		printf("没有从该城市出发的班次！");
	}
	return 1;
}
//显示系统中所有城市信息
void ShowCity(ALGraph G) {
	int i;
	if (G.n == 0) {
		printf("该系统还没有城市信息！\n");
	}
	else {
		printf("系统中有%d座城市的信息\n",G.n );
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
//显示系统中所有路线信息
void ShowLine(ALGraph G) {
	int i;
	if (G.e == 0) {
		printf("该系统还没有城市路线信息！\n");
	}
	else {
		printf("系统中有%d条线路的信息\n", G.e);
		printf("出发城市|到达城市|班次名||||||||出发时间||||||||到达时间||||||||||用时|||||||票价\n");
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
void DeleteLine(ALGraph &G) {//删除路线
	LineNode line;
	char StartName[MAX_LENGTH_STRING], EndName[MAX_LENGTH_STRING];
	char linename[MAX_LENGTH_STRING];//班次名
	char in;//输入
	int startIndex, endIndex;
	//信息输入
	while (true) {
		printf("请输入起点城市：\n");
		scanf(" %s", StartName);
		getchar();
		if (-1 == LocateVexByName_AL(G, StartName)) {
			printf("无%s出发路线请重新输入\n", StartName);
			continue;
		}
		break;
	}
	startIndex = LocateVexByName_AL(G, StartName);
	while (true)
	{
		printf("请输入终点城市：\n");
		scanf(" %s", EndName);
		getchar();
		if (-1 == LocateVexByName_AL(G, StartName)) {
			printf("无%s出发路线请重新输入\n", StartName);
			continue;
		}
		break;
	}
	endIndex = LocateVexByName_AL(G, EndName);
	printf("请输入班次名\n");
	scanf(" %s", linename);
	getchar();
	if (!RemoveArc_One_AL(G, startIndex, endIndex, linename)) {
		printf("删除失败请检查输入\n");

	}
	else printf("删除成功\n");
	system("pause");
}

void DeleteCity(ALGraph& G)
{
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **              管理员               *\n");
	printf("                                          **************************************\n");
	printf("                                          **                                   *\n");
	printf("                                          **             删除城市              *\n");
	printf("                                          **                                   *\n");
	printf("                                          v*************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
	VexNode vex;
	char name[MAX_LENGTH_STRING];
	//信息输入
	while (true) {
		printf("城市名称(输入BACK返回)：\n");
		scanf(" %s", name);
		getchar();
		if (strcmp(name, "BACK")==0)return;
		if (-1 == LocateVexByName_AL(G, name)) {
			printf("无城市%s请重新输入\n", name);
			continue;
		}
		break;
	}
	if (OK == RemoveVexNode_AL(G, LocateVexByName_AL(G, name), vex))printf("删除成功\n");
	else printf("删除失败\n");
	system("pause");
	return;
}

void Dijkstra_Money(ALGraph G, int v0, DistInfoMoney* &dis) {

	LineNodeP p;//
	dis = (DistInfoMoney*)malloc(sizeof(DistInfoMoney) * G.n);
	int i, m, k, min;
	for (i = 0; i < G.n; ++i) {//初始化
		dis[i].money = INFINITY;
		G.tags[i] = UNSELECTED; //都未找到最短路
	}
	for (p = G.vexs[v0].firstArc; p != NULL; p = p->nextArc) {
		dis[p->adjvex].prev = v0;
		if (p->info_Money < dis[p->adjvex].money) {
			dis[p->adjvex].money = p->info_Money;
		}
	}

	dis[v0].prev = -1;
	dis[v0].money = 0; //源点到源点最短路权值为0
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
	printf(" %-8s 到 %-8s , 班次 %-6s ,发车时间:", G.vexs[Dist[k].prev].cityName, minP->endname, minP->linename);
	printTime(minP->startTime);
	printf("        ");
	printf("到站时间:");
	printTime(minP->stopTime);
	printf("        ");
	printf("票价：%d", minP->info_Money);
	printf("\n");
	if (timeE0(timeWait))return;
	  printf(" 中转等候时间:%d分钟后\n", TimeWeight(timeWait));

	
}
//最少时间路径
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
	for (i = 0; i < G.n; ++i) {//初始化
		dis[i].time= INFINITY;
		dis[i].et.day = 0; dis[i].et.hour = 0; dis[i].et.minute = 0;
		G.tags[i] = UNSELECTED; //都未找到最短路
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
	dis[v0].time = 0; //源点到源点最短路权值为0
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
	printf(" %-8s 到 %-8s , 班次 %-6s ,发车时间:", G.vexs[Dist[k].prev].cityName, Dist[k].p->endname, Dist[k].p->linename);
	printTime(Dist[k].p->startTime);
	//printf("        ");
	printf("到站时间:");
	printTime(Dist[k].p->stopTime);
	//printf("        ");
	printf("时间消耗：%d分钟", TimeWeight(Dist[k].p->timeCost));
	printf("\n");
	if (timeE0(timeWait))return;
	printf(" 中转等候时间:%d分钟后\n", TimeWeight(timeWait));

}

void Dijkstra_Station(ALGraph G, int i, DistInfoStation*& Dist) {
	int j, m, k, min;
	AdjVexNodeP p;
	Dist = (DistInfoStation*)malloc(G.n * sizeof(DistInfoStation));
	for (j = 0; j < G.n; j++) {// 初始化
		Dist[j].lowcost = INFINITY;
		G.tags[j] = UNSELECTED;//所有顶点均不在集合U中
	}
	for (p = G.vexs[i].firstArc; p != NULL; p = p->nextArc) {
		// 源点i引出的所有弧的信息存入Dist
		Dist[p->adjvex].prev = i;
		Dist[p->adjvex].lowcost = 1;

	}
	Dist[i].prev = -1; Dist[i].lowcost = 0; // 源点i信息存人 Dist
	G.tags[i] = SELECTED;//初始集合U仅含源点i
	for (m = 1; m < G.n; m++) {//按路径长度升序,依次水源点到具他坝点的最短路径
		min = INFINITY; k = 0;
		for (j = 0; j < G.n; j++)
			if (0 == G.tags[j] && Dist[j].lowcost < min) {
				k = j; min = Dist[k].lowcost;
			}
		G.tags[k] = SELECTED; // 将k顶点加人集合U
		for (p = G.vexs[k].firstArc; p != NULL; p = p->nextArc) {//更新Dist 数组
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
	printf(" %-8s 到 %-8s , 班次有:\n", G.vexs[Dist[k].prev].cityName, p->endname);
	while (p!=NULL)
	{
		if (p->adjvex != k) {
			p = p->nextArc;
			continue;
		}
		printf("                          班次 %-6s ,发车时间:", p->linename);
		printTime(p->startTime);
		printf("        ");
		printf("到站时间:");
		printTime(p->stopTime);
		printf("        ");
		printf("票价：%d", p->info_Money);
		printf("\n");
		p = p->nextArc;
	}
	printf("\n");
}