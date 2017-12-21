
#include <iostream>
#include "Student.h"
#include "StudentManage.h"
#include "function.h"
using namespace std;
int main(){
    cout<<"===========欢迎使用学生管理系统!===========\n";
    char choice;
    StudentManage cm;
    cm.readData("d:\\sm32.dat");
    while(true){
        choice=menu();
        if(choice=='0')
            break;
        switch(choice){
        case '1':
            doAddStudent(cm);
            break;
        case '2':
            doRemoveStudent(cm);
            break;
        case '3':
            doViewStudent(cm);
            break;
        case '4':
            doViewAllStudent(cm);
            break;
        case '5':
            doCheckout(cm);
            break;
        default:
            cout<<"=====无效输入! 请重试!\n";
            break;
        }
    }
    cout<<"=========再见!======\n";
    cm.saveData("d:\\sm32.dat");


    return 0;
}
