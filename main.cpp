
//
//  main.cpp
//  Warehouse management system
//
//  Created by 陈俊睿 on 2019/3/27.
//  Copyright © 2019 陈俊睿. All rights reserved.
//


#include "warehouse.cpp"
using namespace std;
//main函数
int main(int argc, const char * argv[]) {
    cout
    <<"           仓库管理系统"<<endl;
    cout<<"操作命令列表如下:\n————————————————————————————————————" << endl
    <<"存入        输入 1 " <<endl
    <<"取出        输入 2 " <<endl
    <<"查询数量     输入 3 " <<endl
    <<"物品列表     输入 4" <<endl
    <<"导入列表     输入 5" <<endl
    <<"导出列表     输入 6 " <<endl
    <<"软件说明     输入7"  <<endl
    <<"版本信息     输入8"<<endl
    <<"退出         输入0"<<endl
    <<"————————————————————————————————————\n请输入数字+回车:\n您的指令是：" <<endl;
    int x;
    warehouse h;
    string name;
    int  num;
    while(cin>>ws>>x){
        switch (x) {
            case 1:
                cout<<"请输入货物名字:";cin>> name;
                cout<<"请输入数量:";cin>> num;
                if(h.in(name, num))cout<<"操作成功"<<endl;
                else cout <<"操作失败"<<endl;
                cout<<"—————————————————————————\n退出输入0   说明输入7\n请再次输入命令:\n";
                break;
            case 2:
                cout<<"请输入货物名字:";cin>> name;
                cout<<"请输入数量:";cin>> num;
                if(h.out(name, num))cout<<"取出操作成功"<<endl;
                else cout <<"取出操作失败"<<endl;
                cout<<"—————————————————————————\n退出输入0   说明输入7\n请再次输入命令:\n";
                break;
            case 3:
                cout<<"请输入货物名字:";cin>> name;
                if(h.show(name))cout<<"操作成功"<<endl;
                else cout <<"无该货物，操作失败"<<endl;
                cout<<"—————————————————————————\n退出输入0   说明输入7\n请再次输入命令:\n";
                break;
            case 4:
                if(h.list())cout<<"列表成功"<<endl;
                else cout <<"操作失败"<<endl;
                cout<<"—————————————————————————\n退出输入0   说明输入7\n请再次输入命令:\n";
                break;
            case 6:
                if(h.flist())cout<<"导出列表成功"<<endl;
                else cout <<"操作失败"<<endl;
                cout<<"—————————————————————————\n退出输入0   说明输入7\n请再次输入命令:\n";
                break;
            case 5:
            	cout<<"注意：重复导入列表会导致仓库数量出错"<<endl;
                if(h.fin())cout<<"导入列表成功"<<endl;
                else cout <<"操作失败"<<endl;
                cout<<"—————————————————————————\n退出输入0   说明输入7\n请再次输入命令:\n";
                break;
            case 8:
                cout<<"Warehouse management system\nCreated by 陈俊睿 on 2019/3/27.\nCopyright © 2019 陈俊睿. All rights reserved.\n version-1.0"<<endl;
                cout<<"—————————————————————————\n退出输入0   说明输入7\n请再次输入命令:\n";
                break;
            case -1:
                if(h.newhouse())cout<<"删除成功"<<endl;
                else cout <<"操作失败"<<endl;
                cout<<"—————————————————————————\n退出输入0   说明输入7\n请再次输入命令:\n";
            	break;
            case 0:
                return 0;
            case 7:
                cout<<"操作命令列表如下:\n—————————————————————————" << endl
                <<"存入        输入 1  " <<endl
                <<"取出        输入 2  " <<endl
                <<"查询数量     输入 3  " <<endl
                <<"物品列表     输入 4" <<endl
                <<"导出列表     输入 5" <<endl
                <<"导入列表     输入 6  " <<endl
                <<"软件说明     输入 7"  <<endl
                <<"版本信息     输入 8"<<endl
                <<"删除仓库内所有物品 -1"<<endl
                <<"————————————————————————————————————" <<endl;
                cout<<"—————————————————————————\n退出输入0   说明输入7\n请再次输入命令:\n";
                break;
            default:
                cout<<"Warehouse management system\nCreated by 靓仔睿 on 2019/3/27.\nCopyright © 2019 靓仔睿. All rights reserved.\n version-1.0"<<endl;
                cout<<"—————————————————————————\n退出输入0   说明输入7\n请再次输入命令:\n";
                break;
        }
    }
    return 0;
}

