#include"graphH.h"

#define BACK 0
#define CLOSE -1
#define CONTINUE 1
//---------------------------菜单打印--------------------------
void MainMune() {
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **        欢迎使用交通咨询系统       *\n");
	printf("                                          **************************************\n");
	printf("                                          **************************************\n");
	printf("                                          **                                   *\n");
	printf("                                          **           1、管理员登录           *\n");
	printf("                                          **                                   *\n");
	printf("                                          **           2、交通咨询             *\n");
	printf("                                          **                                   *\n");
	printf("                                          **************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
}
void adminMune() {
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **               管理员              *\n");
	printf("                                          **************************************\n");
	printf("                                          **                                   *\n");
	printf("                                          **            1、城市管理            *\n");
	printf("                                          **                                   *\n");
	printf("                                          **            2、添加班次            *\n");
	printf("                                          **                                   *\n");
	printf("                                          **            3、取消班次            *\n");
	printf("                                          **                                   *\n");
	printf("                                          **            4、查看所有路线        *\n");
	printf("                                          **                                   *\n");
	printf("                                          **            5、终止程序            *\n");
	printf("                                          **                                   *\n");
	printf("                                          **            6、返回上级目录        *\n");
	printf("                                          **                                   *\n");
	printf("                                          **************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
}
void seletedgraph() {
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **              管理员               *\n");
	printf("                                          **************************************\n");
	printf("                                          **       请选择操作交通工具类型      *\n");
	printf("                                          **                                   *\n");
	printf("                                          **              1、飞机              *\n");
	printf("                                          **                                   *\n");
	printf("                                          **              2、火车              *\n");
	printf("                                          **                                   *\n");
	printf("                                          v*************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
}
void seletedgraphuser() {
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **             交通咨询              *\n");
	printf("                                          **************************************\n");
	printf("                                          **       请选择操作交通工具类型      *\n");
	printf("                                          **                                   *\n");
	printf("                                          **              1、飞机              *\n");
	printf("                                          **                                   *\n");
	printf("                                          **              2、火车              *\n");
	printf("                                          **                                   *\n");
	printf("                                          v*************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
}
void cityManage() {
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **               管理员              *\n");
	printf("                                          **************************************\n");
	printf("                                          **              城市管理             *\n");
	printf("                                          **************************************\n");
	printf("                                          **                                   *\n");
	printf("                                          **            1、删除城市            *\n");
	printf("                                          **                                   *\n");
	printf("                                          **            2、添加城市            *\n");
	printf("                                          **                                   *\n");
	printf("                                          **            3、查看所有城市        *\n");
	printf("                                          **                                   *\n");
	printf("                                          **            4、返回上级目录        *\n");
	printf("                                          **                                   *\n");
	printf("                                          **************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
}
void addRoute() {
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **              管理员               *\n");
	printf("                                          **************************************\n");
	printf("                                          **                                   *\n");
	printf("                                          **             添加路线              *\n");
	printf("                                          **                                   *\n");
	printf("                                          v*************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
}
void DeRoute() {
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **              管理员               *\n");
	printf("                                          **************************************\n");
	printf("                                          **                                   *\n");
	printf("                                          **             删除路线              *\n");
	printf("                                          **                                   *\n");
	printf("                                          v*************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
}
void userMune() {
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **             交通咨询              *\n");
	printf("                                          **************************************\n");
	printf("                                          **************************************\n");	
	printf("                                          **                                   *\n");
	printf("                                          **          1、最快到达路线          *\n");
	printf("                                          **                                   *\n");
	printf("                                          **          2、最省钱路线            *\n");
	printf("                                          **                                   *\n");
	printf("                                          **          3、最少中转站路线        *\n");
	printf("                                          **                                   *\n");
	printf("                                          **          4、返回上级目录          *\n");
	printf("                                          **                                   *\n");
	printf("                                          **************************************\n");
	printf("                                          **************************************\n");
	printf("\n");
	printf("\n");
}
//----------------------------end------------------------------


//--------------------------管理员界面----------------------

Status adminSignIn() {//登录
	char name[10];
	char password[10];
	printf("\n");
	printf("\n");
	printf("                                          **************************************\n");
	printf("                                          **             管理员登录            *\n");
	printf("                                          **************************************\n");
	printf("                                           在账户输入一行输入 BACK 返回上级目录\n");
	printf("\n");
	printf("\n");
	
	while (true) {
		printf("请输入账户：\n");
		scanf(" %s", &name);
		getchar();
		if (0 == strcmp("BACK", name)) {
			return BACK;
		}
		printf("请输入密码：\n");
		scanf(" %s", &password);
		getchar();

		if (0 != strcmp("admin", name)) {
			printf("账户错误\n");
			continue;
		}
		if (0 != strcmp("8848", password)) {
			printf("密码错误\n");
			continue;
		}
		return CONTINUE;
	}
}
Status CityManage(ALGraph& G) {
	char in;
	while (true)
	{
		cityManage();
		while (true) {
			printf("请输入您的选择：\n");
			scanf(" %c", &in);
			getchar();
			switch (in)
			{
			case '1':DeleteCity(G); break;
			case '2':ADDCity(G); break;
			case '3':ShowCity(G); break;
			case '4':return BACK;
			default:
				printf("输入错误\n");
			}
			break;
		}
	}
}
Status adminEntry(ALGraph&GTrain , ALGraph& GPlane) {//主界面
	char in;
	ALGraph G;
	if (adminSignIn() == BACK)//登录失败返回主界面
		return BACK;
	seletedgraph();
	while (true)
	{
		printf("请输入您的选择：");
		scanf(" %c", &in);
		getchar();
		if (in == '1') {
			G = GPlane;
		}
		else if (in == '2') {
			G = GTrain;
		}
		else {
			printf("输入错误\n");
			continue;
		}
		break;
	}
	while (true)
	{
		
		adminMune();
		while (true) {
			printf("请输入您的选择：\n");
			scanf(" %c", &in);
			getchar();
			switch (in)
			{
			case '1':CityManage(G); break;
			case '2':
				addRoute();
				AddLine(G); break;
			case '3':
				DeRoute();
				DeleteLine(G); break;
			case '4':ShowLine(G); break;
			case '5':return CLOSE;
			case '6':return BACK;
			default:
				printf("输入错误\n");
			}
			break;
		}
	}
	
}

//---------------------------end--------------------------------


//-----------------------交通咨询界面入口----------------------
void lowcostStation(ALGraph G, DistInfoStation* Dist_Station, int endIndex);

Status advisoryEntry(ALGraph& GTrain, ALGraph& GPlane) {
	ALGraph G;
	char in;
	char cityS[MAX_LENGTH_STRING], cityE[MAX_LENGTH_STRING];
	TransportKind kind;
	Time time,zeroT,infT;
	zeroT.day = 0; zeroT.hour = 0; zeroT.minute = 0;
	infT.day = INFINITY; infT.hour = INFINITY; infT.minute = INFINITY;
	DistInfoMoney* Dist_Money = NULL;
	DistInfoTime* Dist_Time = NULL;
	DistInfoStation* Dist_Station = NULL;
	//DistInfoTime dis[12];
	//DistInfoStation  Dist[12];
	int startIndex, endIndex,moneyCost=0,timecost=0;
	while (true){
		printf("\n");
		printf("\n");
		printf("                                          **************************************\n");
		printf("                                          **             交通咨询              *\n");
		printf("                                          **************************************\n");
		printf("                                          **                                   *\n");
		printf("                                          **      交通工具选择输入 0 返回      *\n");
		printf("                                          **                                   *\n");
		printf("                                          **************************************\n");
		printf("\n");
		printf("\n");

			while (true)
			{
				printf("请输入交通工具类型(1、飞机 2、火车)：");
				scanf(" %c", &in);
				getchar();
				if (in == '0') {
					return BACK;
				}
				else if (in == '1') {
					G = GPlane;
				}
				else if (in == '2') {
					G = GTrain;
				}
				else {
					printf("输入错误\n");
					continue;
				}
				break;
			}
			while (true)
			{
				printf("请输入起点城市：");
				scanf(" %s", cityS);
				getchar();
				startIndex = LocateVexByName_AL(G, cityS);
				if (startIndex == -1) {
					printf(" %s 不存在\n", cityS);
					continue;
				}
				break;
			}
			while (true)
			{
				printf("请输入终点城市：");
				scanf(" %s", cityE);
				getchar();
				endIndex = LocateVexByName_AL(G, cityE);
				if (endIndex == -1) {
					printf(" %s 不存在\n", cityE);
					continue;
				}
				break;
			}
			while (true)
			{
				printf("请输入预计到达 %s 站点时间:(hh,mm)", cityS);
				scanf("%d,%d", &time.hour, &time.minute);
				getchar();
				printf("预计到达 %s 时间：%2d:%2d\n", cityS, time.hour, time.minute);
				printf("输入1确认，输入其他修改\n");
				scanf(" %c", &in);
				getchar();
				if (in == '1') {
					break;
				}
			}
			//////////////////////////
		//	G = GTrain;
			//startIndex = 1;
			//endIndex = 3;
		//	time.day = 0; time.hour = 3; time.minute = 10;
			///////////////
			Dijkstra_Money(G, startIndex, Dist_Money);
			Dijkstra_Time(G, startIndex, Dist_Time, time);
			Dijkstra_Station(G, startIndex, Dist_Station);
			///////////////////////////////////////////////////


			//////////////////////////////////////////////////
			userMune();
			while (true)
			{
				printf("请输入您的选择：\n");
				scanf(" %c", &in);
				getchar();
				if (in == '1') {
					printf("最省时间路线：\n");
					zeroT.day = 0; zeroT.hour = 0; zeroT.minute = 0;
					timecost = 0;
					Outputpath_Time(G, Dist_Time, endIndex, timecost, zeroT);
					//	Outputpath_Time(G, dis, endIndex, timecost, zeroT);
					printf("路途时间消耗：%d分钟\n", timecost);
				}
				else if (in == '2') {
					printf("最省钱路线：\n");
					moneyCost = 0;
					zeroT.day = 0; zeroT.hour = 0; zeroT.minute = 0;
					timecost = 0;
					Outputpath_Money(G, Dist_Money, endIndex, moneyCost, zeroT, timecost);
					printf("总票价：%d元\n", moneyCost);
					printf("路途时间消耗：%d分钟\n", timecost);
				}
				else if (in == '3') {
					lowcostStation(G,Dist_Station,endIndex);
				}
				else if(in=='4')break;
				else printf("输入错误\n");
			}
		}
	
		
	
}
//--------------------------end--------------------------------
void lowcostMoney(ALGraph G, DistInfoMoney* Dist_Money,int endIndex) {
	Time  zeroT;
	int moneyCost = 0;
	int	timecost = 0;
	zeroT.day = 0; zeroT.hour = 0; zeroT.minute = 0;
		printf("最省钱路线：\n");
		Outputpath_Money(G, Dist_Money, endIndex, moneyCost, zeroT, timecost);
		printf("总票价：%d元\n", moneyCost);
		printf("路途时间消耗：%d分钟\n", timecost);
	

}

void lowcostTime(ALGraph G, DistInfoTime* Dist_Time, int endIndex) {
	Time  zeroT;
	int	timecost = 0;
	zeroT.day = 0; zeroT.hour = 0; zeroT.minute = 0;
			printf("最省时间路线：\n");
			timecost = 0;
			Outputpath_Time(G, Dist_Time, endIndex, timecost, zeroT);
			//	Outputpath_Time(G, dis, endIndex, timecost, zeroT);
			printf("路途时间消耗：%d分钟\n", timecost);
	

}
void lowcostStation(ALGraph G, DistInfoStation* Dist_Station, int endIndex) {
	int cost = 0;
	printf("最少中转站路线：\n");
	Outputpath_Station( G, Dist_Station, endIndex, cost);
	printf("共经停站点%d\n", cost-1);
}
//------------------------主函数-------------------------------
void initialGraph_Train(ALGraph &G);
void initialGraph_Plane(ALGraph& G);
int main() {
	int flag=BACK;
	char in;
	ALGraph G_Train;
	ALGraph G_Plane;
	initialGraph_Train(G_Train);
	initialGraph_Plane(G_Plane);
	while (flag==BACK) {
		MainMune();
		while(true)
		{
			printf("请输入您的选择：");
			scanf(" %c", &in);
			getchar();
			if (in == '1') {
				system("cls");
				flag = adminEntry(G_Train, G_Plane);
			}else if (in == '2') {
				system("cls");
				flag = advisoryEntry(G_Train, G_Plane);
			}else {
				printf("输入错误\n");
				continue;
			}
			break;
		}
		
	}



}
//--------------------------end--------------------------------
void initialGraph_Train(ALGraph& G) {

	int n = 11;
	
	VexType* citys[11];
	char* NO[27];
	Time starttime, stoptime, timecost;
	for (int i = 0; i < 11; i++) {
		citys[i] = (VexType*)malloc(sizeof(VexType));
	}
	strcpy(citys[0], "北京"); strcpy(citys[1], "郑州"); strcpy(citys[2], "兰州"); strcpy(citys[3], "广州"); strcpy(citys[4], "西安"); strcpy(citys[5], "上海"); strcpy(citys[6], "武汉"); strcpy(citys[7], "昆明"); strcpy(citys[8], "乌鲁木齐"); strcpy(citys[9], "安徽"); strcpy(citys[10], "长沙");

	CreatNodeOnlyGraph_AL(G, citys, n);
	for (int i = 0; i < 27; i++) {
		NO[i] = (char*)malloc(sizeof(char*));
	}
//北京
	starttime.day = 0;
	starttime.hour = 13;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 21;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[0], "G27");
	AddArc_AL(G, 0, 1, citys[1], NO[0], TRAIN, 78, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 7;
	starttime.minute = 11;
	stoptime.day = 0;
	stoptime.hour = 15;
	stoptime.minute = 8;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[1], "D41");
	AddArc_AL(G, 0, 1, citys[1], NO[1], TRAIN, 90, starttime, stoptime, timecost);


	starttime.day = 0;
	starttime.hour = 19;
	starttime.minute = 24;
	stoptime.day = 1;
	stoptime.hour =10;
	stoptime.minute = 28;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[2], "D134");
	AddArc_AL(G, 0, 2, citys[2], NO[2], TRAIN, 168, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 19;
	starttime.minute = 24;
	stoptime.day = 1;
	stoptime.hour = 10;
	stoptime.minute = 28;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[2], "D1234");
	AddArc_AL(G, 0, 3, citys[3], NO[2], TRAIN, 16800, starttime, stoptime, timecost);
	
	//郑州
	starttime.day = 0;
	starttime.hour =21;
	starttime.minute = 24;
	stoptime.day = 1;
	stoptime.hour = 5;
	stoptime.minute = 13;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[3], "D27");
	AddArc_AL(G, 1, 4, citys[4], NO[3], PLANE, 82, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 13;
	starttime.minute = 42;
	stoptime.day = 0;
	stoptime.hour = 21;
	stoptime.minute = 40;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[4], "G27");
	AddArc_AL(G, 1, 0, citys[0], NO[4], PLANE, 78, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 9;
	starttime.minute = 40;
	stoptime.day = 0;
	stoptime.hour = 17;
	stoptime.minute = 37;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[5], "G41");
	AddArc_AL(G, 1, 0, citys[0], NO[5], PLANE, 90, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 15;
	starttime.minute = 20;
	stoptime.day = 1;
	stoptime.hour = 0;
	stoptime.minute = 13;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[6], "D41");
	AddArc_AL(G, 1, 5, citys[5], NO[6], PLANE, 100, starttime, stoptime, timecost);

	
	//西安
	starttime.day = 0;
	starttime.hour = 5;
	starttime.minute = 41;
	stoptime.day = 0;
	stoptime.hour = 13;
	stoptime.minute = 30;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[7], "D27");
	AddArc_AL(G, 4, 1, citys[1], NO[7], PLANE, 82, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 1;
	starttime.minute = 34;
	stoptime.day = 0;
	stoptime.hour = 18;
	stoptime.minute = 35;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[8], "G218");
	AddArc_AL(G, 4, 6, citys[6], NO[8], PLANE, 178, starttime, stoptime, timecost);
//上海	
	starttime.day = 0;
	starttime.hour = 0;
	starttime.minute = 35;
	stoptime.day = 0;
	stoptime.hour = 9;
	stoptime.minute = 28;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[9], "G41");
	AddArc_AL(G, 5, 1, citys[1], NO[9], PLANE, 100, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 8;
	starttime.minute = 20;
	stoptime.day = 1;
	stoptime.hour = 3;
	stoptime.minute = 16;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[10], "G59");
	AddArc_AL(G, 5, 3, citys[3], NO[10], PLANE, 182, starttime, stoptime, timecost);

	//广州
	starttime.day = 0;
	starttime.hour = 3;
	starttime.minute = 39;
	stoptime.day = 0;
	stoptime.hour = 22;
	stoptime.minute = 53;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[11], "G59");
	AddArc_AL(G, 3, 5, citys[5], NO[11], PLANE, 182, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 6;
	starttime.minute =18;
	stoptime.day = 0;
	stoptime.hour = 16;
	stoptime.minute = 14;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[12], "G323");
	AddArc_AL(G, 3, 7, citys[7], NO[12], PLANE, 102, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour =0;
	starttime.minute = 35;
	stoptime.day = 0;
	stoptime.hour = 11;
	stoptime.minute = 35;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[13], "D373");
	AddArc_AL(G, 3, 10, citys[10], NO[13], PLANE, 116, starttime, stoptime, timecost);

	
	//兰州
	starttime.day = 0;
	starttime.hour = 3;
	starttime.minute = 52;
	stoptime.day = 0;
	stoptime.hour = 18;
	stoptime.minute = 56;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[14], "D134");
	AddArc_AL(G, 2, 0, citys[0], NO[14], PLANE, 162, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 17;
	starttime.minute = 41;
	stoptime.day = 1;
	stoptime.hour = 14;
	stoptime.minute = 47;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[15], "D747");
	AddArc_AL(G, 2, 6, citys[6], NO[15], PLANE, 210, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 11;
	starttime.minute = 42;
	stoptime.day = 1;
	stoptime.hour =23;
	stoptime.minute = 54;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[16], "D371");
	AddArc_AL(G, 2, 8, citys[8], NO[16], PLANE, 114, starttime, stoptime, timecost);

	//昆明
	starttime.day = 0;
	starttime.hour = 16;
	starttime.minute = 31;
	stoptime.day = 1;
	stoptime.hour = 2;
	stoptime.minute = 27;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[17], "G323");
	AddArc_AL(G, 7, 3, citys[3], NO[17], PLANE, 102, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 21;
	starttime.minute = 42;
	stoptime.day = 1;
	stoptime.hour = 11;
	stoptime.minute = 46;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[18], "D873");
	AddArc_AL(G, 7, 6, citys[6], NO[18], PLANE, 134, starttime, stoptime, timecost);


	//武汉
	starttime.day = 0;
	starttime.hour = 7;
	starttime.minute = 13;
	stoptime.day = 0;
	stoptime.hour = 21;
	stoptime.minute = 17;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[19], "D873");
	AddArc_AL(G, 6, 7, citys[7], NO[19], PLANE, 134, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 9	;
	starttime.minute = 36;
	stoptime.day = 0;
	stoptime.hour = 18;
	stoptime.minute = 32;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[20], "D116");
	AddArc_AL(G, 6, 10, citys[10], NO[20], PLANE, 98, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 15;
	starttime.minute = 13;
	stoptime.day = 2;
	stoptime.hour = 12;
	stoptime.minute = 19;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[21], "D747");
	AddArc_AL(G, 6, 2, citys[2], NO[21], PLANE, 210, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 18;
	starttime.minute = 50;
	stoptime.day = 1;
	stoptime.hour = 11;
	stoptime.minute = 51;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[22], "D218");
	AddArc_AL(G, 6, 4, citys[4], NO[22], TRAIN, 178, starttime, stoptime, timecost);


	//长沙
	starttime.day = 0;
	starttime.hour = 18;
	starttime.minute = 54;
	stoptime.day = 1;
	stoptime.hour = 3;
	stoptime.minute = 48;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[23], "G116");
	AddArc_AL(G, 10, 6, citys[6], NO[23], TRAIN, 98, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 13;
	starttime.minute = 15;
	stoptime.day = 1;
	stoptime.hour = 0;
	stoptime.minute = 15;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[24], "D373");
	AddArc_AL(G, 10, 3, citys[3], NO[24], TRAIN, 116 ,starttime, stoptime, timecost);


	//乌鲁木齐
	starttime.day = 0;
	starttime.hour = 0;
	starttime.minute = 35;
	stoptime.day = 0;
	stoptime.hour = 11;
	stoptime.minute = 23;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[24], "D371");
	AddArc_AL(G, 8, 2, citys[2], NO[24], TRAIN, 114, starttime, stoptime, timecost);
	
	starttime.day = 0;
	starttime.hour = 0;
	starttime.minute = 35;
	stoptime.day = 1;
	stoptime.hour = 23;
	stoptime.minute = 23;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[24], "S371");
	AddArc_AL(G, 8, 7, citys[7], NO[24], TRAIN, 11114, starttime, stoptime, timecost);

	//安徽
	starttime.day = 0;
	starttime.hour = 15;
	starttime.minute = 20;
	stoptime.day = 0;
	stoptime.hour = 20;
	stoptime.minute = 35;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO[26], "D555");
	AddArc_AL(G, 9, 1, citys[1], NO[26], TRAIN, 310, starttime, stoptime, timecost);

}
void initialGraph_Plane(ALGraph& G) {
	int n = 11;

	VexType* citys[11];
	char* NO=(char*)malloc(sizeof(char*));
	Time starttime, stoptime, timecost;
	for (int i = 0; i < 11; i++) {
		citys[i] = (VexType*)malloc(sizeof(VexType));
	}
	strcpy(citys[0], "北京"); strcpy(citys[1], "郑州"); strcpy(citys[2], "兰州"); strcpy(citys[3], "广州"); strcpy(citys[4], "西安"); strcpy(citys[5], "上海"); strcpy(citys[6], "武汉"); strcpy(citys[7], "昆明"); strcpy(citys[8], "乌鲁木齐"); strcpy(citys[9], "安徽"); strcpy(citys[10], "长沙");

	CreatNodeOnlyGraph_AL(G, citys, n);

	//北京
	starttime.day = 0;
	starttime.hour = 16;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 21;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "GM1227");
	AddArc_AL(G, 0, 1, citys[1], NO, PLANE, 78, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 8;
	starttime.minute = 11;
	stoptime.day = 0;
	stoptime.hour = 11;
	stoptime.minute = 8;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "DD141");
	AddArc_AL(G, 0, 8, citys[8], NO, PLANE, 1490, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 9;
	starttime.minute =50 ;
	stoptime.day = 0;
	stoptime.hour = 12;
	stoptime.minute = 35;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "Gds27");
	AddArc_AL(G, 0, 4, citys[4], NO, PLANE, 978, starttime, stoptime, timecost);


	//郑州
	starttime.day = 0;
	starttime.hour = 13;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 21;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "G2ds7");
	AddArc_AL(G, 1, 4, citys[4], NO, PLANE, 1178, starttime, stoptime, timecost);


	//西安
	starttime.day = 0;
	starttime.hour = 13;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 21;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "G2sdsa7");
	AddArc_AL(G, 4, 0, citys[0], NO, PLANE, 738, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 13;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 21;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "Gasd27");
	AddArc_AL(G, 4, 3, citys[3], NO, PLANE, 1278, starttime, stoptime, timecost);
	//上海	
	starttime.day = 0;
	starttime.hour = 18;
	starttime.minute = 10;
	stoptime.day = 0;
	stoptime.hour = 19;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "MU6712");
	AddArc_AL(G, 5, 6, citys[6], NO, PLANE, 668, starttime, stoptime, timecost);
	starttime.day = 0;
	starttime.hour = 17;
	starttime.minute = 10;
	stoptime.day = 0;
	stoptime.hour = 19;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "MU6712");
	AddArc_AL(G, 5, 2, citys[2], NO, PLANE, 1668, starttime, stoptime, timecost);

	//广州
	starttime.day = 0;
	starttime.hour = 10;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 11;
	stoptime.minute = 40;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "M1231");
	AddArc_AL(G, 3, 4, citys[4], NO, PLANE, 1278, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 1;
	starttime.minute = 25;
	stoptime.day = 0;
	stoptime.hour = 13;
	stoptime.minute = 5;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "CM214");
	AddArc_AL(G, 3, 6, citys[6], NO, PLANE, 718, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 1;
	starttime.minute = 25;
	stoptime.day = 0;
	stoptime.hour = 13;
	stoptime.minute = 5;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "CK214");
	AddArc_AL(G, 3, 1, citys[6], NO, PLANE, 1718, starttime, stoptime, timecost);

	//兰州
	starttime.day = 0;
	starttime.hour = 13;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 21;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "LC901");
	AddArc_AL(G, 2, 1, citys[1], NO, PLANE, 1278, starttime, stoptime, timecost);
	
	//昆明
	starttime.day = 0;
	starttime.hour = 13;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 15;
	stoptime.minute = 20;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "MA173");
	AddArc_AL(G, 8, 9, citys[9], NO, PLANE, 878, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 12;
	starttime.minute = 35;
	stoptime.day = 0;
	stoptime.hour = 14;
	stoptime.minute = 00;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "MA173");
	AddArc_AL(G, 7, 8, citys[8], NO, PLANE, 578, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 13;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 16;
	stoptime.minute = 20;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "MA173");
	AddArc_AL(G, 8, 10, citys[10], NO, PLANE, 1878, starttime, stoptime, timecost);
	//武汉
	starttime.day = 0;
	starttime.hour = 16;
	starttime.minute = 25;
	stoptime.day = 0;
	stoptime.hour = 17;
	stoptime.minute = 15;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "MC320");
	AddArc_AL(G, 6, 7, citys[7], NO, PLANE, 1678, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 7;
	starttime.minute = 5;
	stoptime.day = 0;
	stoptime.hour = 8;
	stoptime.minute = 45;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "GCm124");
	AddArc_AL(G, 6, 3, citys[3], NO, PLANE, 678, starttime, stoptime, timecost);
	
	starttime.day = 0;
	starttime.hour = 18;
	starttime.minute = 50;
	stoptime.day = 1;
	stoptime.hour = 11;
	stoptime.minute = 51;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "GC124");
	AddArc_AL(G, 6, 5, citys[5], NO, PLANE, 658, starttime, stoptime, timecost);

	//长沙
	starttime.day = 0;
	starttime.hour = 13;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 15;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "MC901");
	AddArc_AL(G, 10, 3, citys[3], NO, PLANE, 378, starttime, stoptime, timecost);



	//乌鲁木齐
	starttime.day = 0;
	starttime.hour = 9;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 2;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "CA1123");
	AddArc_AL(G, 8, 0, citys[0], NO, PLANE, 1178, starttime, stoptime, timecost);

	starttime.day = 0;
	starttime.hour = 10;
	starttime.minute = 45;
	stoptime.day = 0;
	stoptime.hour = 3;
	stoptime.minute = 12;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "CA89");
	AddArc_AL(G, 8, 7, citys[7], NO, PLANE, 1378, starttime, stoptime, timecost);

	//安徽
	starttime.day = 0;
	starttime.hour = 10;
	starttime.minute = 25;
	stoptime.day = 0;
	stoptime.hour = 11;
	stoptime.minute = 45;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "MA173");
	AddArc_AL(G, 9, 7, citys[7], NO, PLANE, 780, starttime, stoptime, timecost);
	
	starttime.day = 0;
	starttime.hour = 14;
	starttime.minute = 15;
	stoptime.day = 0;
	stoptime.hour = 15;
	stoptime.minute = 45;
	timeCost(starttime, stoptime, timecost);
	strcpy(NO, "MC3211");
	AddArc_AL(G, 9, 6, citys[6], NO, PLANE, 678, starttime, stoptime, timecost);

}


