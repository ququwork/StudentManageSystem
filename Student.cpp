#include <iostream>
#include "student.h"
using namespace std;
#include <sstream>
string Student::getInfo()const{
    ostringstream ostr;
    ostr<<getId()<<endl;
    ostr<<getName()<<endl;
    ostr<<mid<<" "<<final<<" ";
    return ostr.str();
}


long Student::nextId=100;

Student::Student(string n,double p,double k,double j)
    :Student(autoNextId(),n,p,k,j){}

Student::Student(long i,std::string n,double p,double k,double j)
    :id(i),name(n),mid(p),final(k),avg(j){}

void Student::output()const{
    cout<<endl;
    cout<<" ѧ�����(id):"<<id<<endl;
    cout<<" ѧ������:"<<name<<endl;
     cout<<" ѧ�����гɼ�:"<<mid<<endl;
      cout<<" ѧ����ĩ�ɼ�:"<<final<<endl;
}
