
#include <iostream>
#include "function.h"


using namespace std;
char menu()
{ cout << "============================================="<<endl;
    cout << " 0) �˳� ϵͳ\n";
    cout << " 1) �� ѧ��������ϵͳ ���ѧ��\n";
    cout << " 2) �� ѧ��������ϵͳ �Ƴ�ѧ��\n";
    cout << " 3) �鿴 ָ��ѧ��\n";
    cout << " 4) �鿴 ����ѧ��\n";
    cout << " 5) �б�\n";
    cout << "============================================="<<endl;

    cout << "=====������ ����ѡ��:";
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

    cout << "=====����ѧ������:";
    getline(cin, name);

    cout << "=====���� ���гɼ� �� ��ĩ�ɼ� :"<<endl;
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


