#include <bits/stdc++.h>

using namespace std;

struct Server
{
    string name;
    int cpu;
    int memory;
    int cost;
    int dayCost;
    int index;

    int pears[2];

    Server() {}

    Server(string _name, int _cpu, int _memory, int _cost, int _dayCost, int _index)
    {
        name = _name;
        cpu = _cpu;
        memory = _memory;
        cost = _cost;
        dayCost = _dayCost;
        index = _index;
        pears[0] = 0;
        pears[1] = 0;
    }
};

struct VM
{
    string name;
    int cpu;
    int memory;
    //对于双节点VM会存在将cpu和memory平分的情况，故引入cpuHalf和memoryHalf
    //node==1 表示双节点
    int node;
    int cpuHalf;
    int memoryHalf;
    VM() {};

    VM(string _name, int _cpu, int _memory, int _node,int _cpuHalf,int _memoryHalf)
    {
        name = _name;
        cpu = _cpu;
        memory = _memory;
        node = _node;
        cpuHalf = _cpuHalf;
        memoryHalf = _memoryHalf;
    }
};

struct Request
{
    string function;
    string VMname;
    int VMID;

    Request(){};

    Request(string _function,string _VMname,int _VMID){
        function=_function;
        VMname=_VMname;
        VMID=_VMID;
    }
};

//比较两个服务器的优先级，按cpu数、内存大小、每日价格、成本的顺序依次判断
//若s1<s2返回1，否则返回0
bool serverLess(Server s1, Server s2) {    
    if (s1.cpu < s2.cpu)
    {
        return true;
    }
    else if (s1.cpu == s2.cpu)
    {
        if (s1.memory < s2.memory)
        {
            return true;
        }
        else if (s1.memory == s2.memory)
        {
            if (s1.dayCost < s2.dayCost)
            {
                return true;
            }
            else if (s1.dayCost == s2.dayCost)
            {
                if (s1.cost < s2.cost)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

typedef vector<Server> serverList;
typedef vector<VM> VMList;

//从标准输入输出读到一个服务器信息，返回一个Server
Server getServer() {
    Server OneServer;
    char str[100];
    getchar();
    scanf("%s, ",str);
    int i;
    for(i=0;str[i]!='\0';i++);
    str[--i]='\0';
    scanf("%d, %d, %d, %d",&OneServer.cpu,&OneServer.memory,&OneServer.cost,&OneServer.dayCost);
    string str2 = string(str);
    Server ans = Server(str2,OneServer.cpu,OneServer.memory,OneServer.cost,OneServer.dayCost,1);
    return ans;
}

//获取所有服务器信息，存入list
void getAllServer(serverList &list) {
     int n;//n服务器类型数量
     scanf("%d",&n);
    for(int i = 0;i<n;i++){
        list.push_back(getServer());
    }
}

//将ServerList按serverLess排序
void sortServerList(serverList &list) {
    sort(list.begin(),list.end(),serverLess);
}

//将s插入到list（有序）中按serverLess顺序的位置
//服务器index值为index
void InsertToServerList(VMList &list, Server s, int index) {}

//从标准输入输出读到一个虚拟机信息，返回一个VM
VM getVM() {
    VM oneVM;
    getchar();
    char str[100];
    scanf("%s, ",str);
    int i=0;
    for(i=0;str[i]!='\0';i++);
    str[--i]='\0';
    scanf("%d, %d, %d",&oneVM.cpu,&oneVM.memory,&oneVM.node);
    string str2 = string(str);
    if(oneVM.node){
        oneVM.cpuHalf=oneVM.cpu/2;
        oneVM.memoryHalf=oneVM.memory/2;
    }else{
        oneVM.cpuHalf=0;
        oneVM.memoryHalf=0;
    }
    VM ans =VM(str2,oneVM.cpu,oneVM.memory,oneVM.node,oneVM.cpuHalf,oneVM.memoryHalf);
    return ans;
}

//获取一天的需求
void getRequestList(VMList &list) {
    VMList myList;
    int R;
    scanf("%d",&R);
    for(int j=0;j<R;j++){
        char func[5];
        getchar();
        scanf("%s, ",func);
        int i=0;
        for(i=0;func[i]!='\0';i++);
        func[--i]='\0';
        char func2[4];
        for(int m=0;m<3;m++){
            func2[m]=func[m+1];
        }
        func2[3]='\0';
        string function=string(func2);
        char name[21];
        scanf("%s, ",name);
        for(i=0;name[i]!='\0';i++);
        name[--i]='\0';
        string VMname=string(name);
        int VMID;
        scanf("%d",&VMID);
        Request temp=Request(function,VMname,VMID);
    }
}

//将vm插入slist和vlist中
//slist保证新插入的vm在满足硬件要求的前提下，尽量处于slist的靠前位置和A（peer[0]）节点
//将slist中的该节点值改为vlist中vm对应的下标（从1开始）
//vlist保证新插入vm在vlist末位，编号从1开始，即vlist[0]为空虚拟机
//注意加入双节点虚拟机时特殊处理
void addVM(serverList &slist, VMList &vlist, VM vm) {}

//将slist中若干个peer迁移至slist尽量靠前的位置（且满足硬件要求）
//最多迁移maxTimes次
//返回一个vector<int>，下标为0~2n-1，其中0为原服务器index，
//注意双节点虚拟机暂不考虑迁移
vector<int> migrateVM(serverList &slist, VMList &vlist, int maxTimes) {}

//根据request，检查slist是否需要购买服务器
//message为可购买的服务器信息，按serverLess升序排序
//若需要购买服务器，则在slist中添加若干服务器
//返回一个serverList，内容为添加的服务器列表
serverList purchaseServer(serverList &slist, VMList &request, serverList &message) {}

void solve()
{
}

int main()
{
    //VM testVM = VM();
    //getRequestList() ;
    //getVM();
    serverList test;
    getAllServer(test);
    sortServerList(test);
    system("pause");
    return 0;
}