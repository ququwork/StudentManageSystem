#include <iostream>
#include "StudentManage.h"
#include "Student.h"
#include <string>
#include <fstream>
#include"algorithm"
#include<vector>

using namespace std;
vector<Student*>::iterator StudentManage::getIterator(Student* p){
    for(auto it=pStudents.begin();it!=pStudents.end();++it)
        if(*it==p)
            return it;
    return pStudents.end();
}


StudentManage::~StudentManage(){for(auto e: pStudents)
        delete e;
 }

Student *StudentManage::findStudentById(int id)
{
    vector<Student*>::iterator it=find_if(pStudents.begin(),
                                          pStudents.end(), [=](Student* p){return p->getId()==id;});
    if(it!=pStudents.end())
        return *it;
    return nullptr;
}


Student *StudentManage::findEmployeeByName(string name2)
{
    vector<Student*>::iterator it=find_if(pStudents.begin(),
                                          pStudents.end(), [=](Student* p){return p->getName()==name2;});
    if(it!=pStudents.end())
        return *it;
    return nullptr;
}
//////新内容。。
///

const Student* StudentManage::findStudentById(int id)const{
    vector<Student*>::const_iterator it=find_if(pStudents.begin(),
                                                pStudents.end(), [=](const Student* p){return p->getId()==id;});
    if(it!=pStudents.end())
        return *it;
    return nullptr;
}

void StudentManage::addStudent(Student *p)
{
    Student *pStudent = findStudentById(p->getId());
    if (pStudent != nullptr)
    {
        cout << "编号为" << p->getId() << "的学生已经存在! \n";
        return;
    }

    // Student *pc = findEmployeeByName(p->getName());
    //    if (pc != nullptr)
    //    {
    //       // cout << "名称为" << p->getName() << "的学生已经存在! \n";
    //        return;
    //    }

    pStudents.push_back(p);
    sortCommodities(); //添加学生后根据当前规则重新排序
}

void StudentManage::sortCommodities(){
    switch(sortType){
    case 0: //根据 id 排序
        sort(pStudents.begin(),pStudents.end(),
             [=](Student* p1,Student* p2){
            return p1->getId()<p2->getId();});
        break;
    case 1: //根据名称排序
        sort(pStudents.begin(),pStudents.end(),
             [=](Student* p1,Student* p2){
            return p1->getName()<p2->getName();});
        break;
    case 2: //根据学生平均成绩排序
        sort(pStudents.begin(),pStudents.end(),
             [=](Student* p1,Student* p2){
            return p1->getAvg()<p2->getAvg();});
        break;
    case 3: //根据期末排序
        sort(pStudents.begin(),pStudents.end(),
             [=](Student* p1,Student* p2){
            return p1->getFinal()<p2->getFinal();});
        break;

    case 4: //根据学生期中排序
        sort(pStudents.begin(),pStudents.end(),
             [=](Student* p1,Student* p2){
            return p1->getMid()<p2->getMid();});
        break;
    }
}

void StudentManage::sortCommoditiesByType(int type){
    if(type==sortType) //已经按指定规则排序，直接返回
        return;
    sortType=type;
    sortCommodities();
}

void StudentManage::removeStudent(int id)
{
    cout<<endl;
    Student *pStudent = findStudentById(id);
    if (pStudent == nullptr)
    {
        cout << "编号为" << id << "的学生不存在!\n";
        return;
    }

    delete[] pStudent;
    pStudents.erase(getIterator(pStudent));

}

void StudentManage::viewStudent(int id) const
{
    cout<<endl;
    const Student* pStudent=findStudentById(id);
    if (pStudent == nullptr)
    {
        cout << "编号为" << id << "的学生不存在!\n";
        return;
    }
    pStudent->output();
}

void StudentManage::viewAllCommodities() const
{
    cout<<"学生数目:"<< pStudents.size()<<endl;
    if(pStudents.size()==0)
        return;
    cout<<"指定排序方式\n(0-学生ID,1-学生名称,2-平均成绩，3-期中成绩，4-期末成绩 ):";
    int type;
    cin>>type;
    const_cast<StudentManage*>(this)->sortCommoditiesByType(type);
    for(auto e:pStudents)
        e->output();
}

void StudentManage::checkOut() const
{

cout<<endl;
    cout<<"======学生数目: "<< pStudents.size()<<endl;
    cout << "学生名称\t"
         << "期中\t"
         << "期末\t"
         << "平均成绩\t\n";

    for(auto e : pStudents){

        cout<<" "<<e->getName()<<"\t\t";
        cout<<e->getMid()<<"\t"
           <<e->getFinal()<<"\t"
          <<e->getAvg()<<endl;
    }

}

void StudentManage::saveData(string filename)
{
    ofstream out(filename);
    if (out)
    {

        out<< pStudents.size()<<endl;

        out << Student::getNextId() << endl; ////////////

        for(auto e : pStudents){
            out<<e->getInfo();}
    }
}


void StudentManage::readData(string filename)
{
    ifstream in(filename);
    if (in)
    {
        int  fileSize;
        long nextId;
        in >> fileSize >> nextId;
        Student::setNextId(nextId);

        long id;
        string name, buf;
        double mid, avg;
        int final;

        for (int i = 0; i < fileSize; ++i)
        {
            in >> id;
            getline(in, buf); //读取 id 后残留的回车要读到 buf 中
            getline(in, name);
            in >> mid >> final>>avg;
            addStudent( new
                        Student(id,name,mid,final,avg));
        }
    }
    sortCommodities();
}
