//
//  warehouse.cpp
//  Warehouse management system
//
//  Created by 陈俊睿 on 2019/3/27.
//  Copyright © 2019 陈俊睿. All rights reserved.
//

#include "warehouse.hpp"
using namespace std;
//找到某个货物，并返回该货物指针
struct Goods* warehouse::find_goods(string target){
    struct Goods* find=head;
    while(find!=NULL){
        if (find->name==target) {
            break;
        }
        else find=find->next;
    }
    return find;
}
//定位最后一个货物
struct Goods* warehouse::end(){
    struct Goods* find=head;
    if (find==NULL) return find;
    while(find->next!=NULL)find=find->next;
    return find;
}
//构造函数 初始化头指针
warehouse::warehouse(void){
    head=NULL;
    time_t now = time(0);
}
//进货函数
bool warehouse::in(string target,int num){
    if(num<=0) return 0;
    struct Goods* find = find_goods(target);
    if(find!=NULL)find->count+=num;
    else{
        find=end();
        if (head==NULL)
        {
            find = new struct Goods;
            find->name=target;
            find->count=num;
            find->next=NULL;
            find->pre=NULL;
            head=find;
        }else{
            find->next = new struct Goods;
            find->next->name=target;
            find->next->count=num;
            find->next->next=NULL;
            find->next->pre=find;
        }
        total+=1;
    }
    outlog("存入货物：",target,num);
    return 1;
}
//出货函数
bool warehouse::out(string target,int num){
    struct Goods* find = find_goods(target);
    if(find==NULL){
        cout<<"没有该货物"<<endl;
        return 0;
    }
    if(num<find->count){
        find->count-=num;
        cout<<"货物已取出"<<endl;
    }else if(num==find->count){
        if (find==head){
            if(head->next!=NULL)head->next->pre=NULL;
            head=head->next;
            delete find;
            find=NULL;
        }
        else{
            find->pre->next=find->next;
            find->next->pre=find->pre;
            delete find;
            cout<<"货物已全部取出"<<endl;
            find=NULL;
        }
        total-=1;
    }
    else {
        cout<<"货物数量不足"<<endl;
        return 0;
    }
    outlog("取出货物：",target,num);
    return 1;
}
//析构函数 释放申请的空间
warehouse::~warehouse(){
    //退出时自动输出
    struct Goods* out=head;
    ofstream outfile;
    outfile.open("autosave.txt");
    outfile <<"自动保存：\n物品清单如下："<<endl<<"共： "<<total<<" 件"<<endl<<"——————————————————"<<endl;
    while (out!=NULL) {
        outfile<<setw(10)<<out->name<<setw(8)<<out->count<<endl;
        out=out->next;
    }
    outfile <<"——————————————————"<<endl;
    outfile <<"以上"<<total<<"个物品"<<endl;
    outfile.close();
    //释放内存
    struct Goods* del;
    struct Goods* save;
    del=head;
    if (head==NULL)return;
    while (del->next!=NULL) {
        save=del->next;
        delete del;
        del=save;
    }
}
//查找某个货物的存量
bool warehouse::show(string target){
    struct Goods* find = find_goods(target);
    if (find==NULL){
        cout<<"仓库无此货物"<<endl;
        return 0;
    }
    else cout<<"库存内有"<<target<<"  共："<<find->count<<endl;
    return 1;
}
//列出现存所有货物的数量
bool warehouse::list(void){
    struct Goods* out=head;
    cout<<"物品清单如下：\n———————————————————"<<endl;
    while (out!=NULL) {
        cout<<setw(10)<<out->name<<setw(8)<<out->count<<endl;
        out=out->next;
    }
    cout<<"———————————————————"<<endl;
    cout<<"以上共"<<total<<"个物品"<<endl;
    return 1;
}
//导出货物列表
bool warehouse::flist(void){
    struct Goods* out=head;
    ofstream outfile;
    outfile.open("date.txt");
    outfile <<"物品清单如下："<<endl<<"共： "<<total<<" 件"<<endl<<"——————————————————"<<endl;
    while (out!=NULL) {
        outfile<<setw(10)<<out->name<<setw(8)<<out->count<<endl;
        out=out->next;
    }
    outfile <<"——————————————————"<<endl;
    outfile <<"以上"<<total<<"个物品"<<endl;
    outfile.close();
    return 1;
}
//从列表中导入数据
bool warehouse::fin(){
    //cout<<"如果进行该操作，您将会失去之前所有记录：\n确定请按1\n";
    ifstream infile;
    infile.open("date.txt");
    string name;
    int num;
    int i;
    int filetotal;
    /*
     if (i!=1)break;
     else{
     struct Goods* del;
     struct Goods* save;
     del=head;
     if (head==NULL){}
     else{
     while (del->next!=NULL) {
     save=del->next;
     delete del;
     del=save;
     }
     }
     }
     */
    infile>>name;
    infile>>name;
    infile>>filetotal;
    infile>>name;
    infile>>name;
    for(i=0;i<filetotal;i++) {
        infile>>name;
        infile >> num;
        in(name, num);
    }
    infile.close();
    return 1;
}
//初始化
int warehouse::total=0;
//删除所有货物
bool warehouse::newhouse(){
    struct Goods* del;
    struct Goods* save;
    del=head;
    if (head==NULL)return 1;
    while (del->next!=NULL) {
        save=del->next;
        delete del;
        del=save;
    }
    head=NULL;
    total=0;
    outlog("删除所有货物操作"," ",0);
    return 1;
}
//日志 自动记录操作
void warehouse::outlog(string ope,string name,int num=0){
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    
    time( &rawtime );
    
    info = localtime( &rawtime );
    //printf("当前的本地时间和日期：%s", asctime(info));
    
    ofstream outfile;
    outfile.open("log.txt",ios::app);
    if(num!=0) outfile<<setw(10)<<ope<<setw(10)<<name<<setw(8)<<num<<"  "<< asctime(info)<<endl;
    else outfile<<setw(10)<<ope<<"  "<< asctime(info) <<endl;
    outfile.close();
}
