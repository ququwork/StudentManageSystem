
#include <iostream>
#include "function.h"


using namespace std;
char menu()
{ cout << "============================================="<<endl;
    cout << " 0) 退出 系统\n";
    cout << " 1) 向 学生生管理系统 添加学生\n";
    cout << " 2) 从 学生生管理系统 移除学生\n";
    cout << " 3) 查看 指定学生\n";
    cout << " 4) 查看 所有学生\n";
    cout << " 5) 列表\n";
    cout << "============================================="<<endl;

    cout << "=====请输入 功能选项:";
    char choice;
    cin >> choice;
    return choice;
}

void doAddStudent(StudentManage &km)
{
    string name;
    double mid, avg2;
    double final;
    fflush(stdin);

    cout << "=====输入学生名称:";
    getline(cin, name);

    cout << "=====输入 期中成绩 和 期末成绩 :"<<endl;
    cin >> mid >> final;
    avg2=(mid + final )/2;
    km.addStudent(new Student(name,mid,final,avg2));
}

void doRemoveStudent(StudentManage &cm)
{
    long id;
    cout << "=====Input id:";
    cin >> id;
    cm.removeStudent(id);
}

void doViewStudent(const StudentManage &cm)
{
    long id;
    cout << "=====Input id:";
    cin >> id;
    cm.viewStudent(id);
}

void doViewAllStudent(const StudentManage &cm)
{
    cm.viewAllCommodities();
}

void doCheckout(const StudentManage &cm)
{
    cm.checkOut();
}
//////////


