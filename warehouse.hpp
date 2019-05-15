//
//  warehouse.hpp
//  Warehouse management system
//
//  Created by 陈俊睿 on 2019/3/27.
//  Copyright © 2019 陈俊睿. All rights reserved.
//

#ifndef warehouse_hpp
#define warehouse_hpp


#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

struct Goods {
    string name; //记录货物名
    int count;  //记录货物数量
    struct Goods* pre;//上一个
    struct Goods* next;//下一个
};

class warehouse{
public:
    warehouse(void);//初始化
    bool in(string,int);//进货
    bool out(string,int);//出货
    bool list(void);//列出现存货物和数量
    bool flist(void);//输出到文件
    bool fin(void);//从文件中读入
    bool show(string);//输出现存某个货物的数量
    ~warehouse();//delete 并退出
    bool newhouse();//删除所有货物
protected:
    struct Goods* head;
    struct Goods* find_goods(string);//寻找目标货物
    struct Goods* end();//寻找最后一个货物
    static int total;//当前仓库内货物总数
    void outlog(string,string,int);//日志输出
};

/*
//进货，对应进货模块，表示当前进货一批数量为count的name商品
bool add_goods(string name, int count);
//更新库存信息，对应增加库存子功能，对name商品新增count数量
bool increase_count (string ,int count);
//更新库存列表，对应新增商品子功能，新增name商品且初始数量为count
bool add_to_list(string name, int count);

//出货：
//出货，对应出货模块，表示当前出货一批数量为count的name商品
bool delete_goods(string name, int count);
//更新库存信息，对应减少库存子功能，对name商品减少count数量
bool increase_count(string name, int count);
//更新库存列表，对应删除商品子功能，删除商品列表中name商品
bool delete_from_list(string name);

//查询：
///显示当前库存列表，包括商品名及其库存量
void show_goods();
//查看仓库中的name商品
//struct Goods warehouse::find_goods(char name[]);
*/
#endif /* warehouse_hpp */
