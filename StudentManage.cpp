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
//////�����ݡ���
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
        cout << "���Ϊ" << p->getId() << "��ѧ���Ѿ�����! \n";
        return;
    }

    // Student *pc = findEmployeeByName(p->getName());
    //    if (pc != nullptr)
    //    {
    //       // cout << "����Ϊ" << p->getName() << "��ѧ���Ѿ�����! \n";
    //        return;
    //    }

    pStudents.push_back(p);
    sortCommodities(); //���ѧ������ݵ�ǰ������������
}

void StudentManage::sortCommodities(){
    switch(sortType){
    case 0: //���� id ����
        sort(pStudents.begin(),pStudents.end(),
             [=](Student* p1,Student* p2){
            return p1->getId()<p2->getId();});
        break;
    case 1: //������������
        sort(pStudents.begin(),pStudents.end(),
             [=](Student* p1,Student* p2){
            return p1->getName()<p2->getName();});
        break;
    case 2: //����ѧ��ƽ���ɼ�����
        sort(pStudents.begin(),pStudents.end(),
             [=](Student* p1,Student* p2){
            return p1->getAvg()<p2->getAvg();});
        break;
    case 3: //������ĩ����
        sort(pStudents.begin(),pStudents.end(),
             [=](Student* p1,Student* p2){
            return p1->getFinal()<p2->getFinal();});
        break;

    case 4: //����ѧ����������
        sort(pStudents.begin(),pStudents.end(),
             [=](Student* p1,Student* p2){
            return p1->getMid()<p2->getMid();});
        break;
    }
}

void StudentManage::sortCommoditiesByType(int type){
    if(type==sortType) //�Ѿ���ָ����������ֱ�ӷ���
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
        cout << "���Ϊ" << id << "��ѧ��������!\n";
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
        cout << "���Ϊ" << id << "��ѧ��������!\n";
        return;
    }
    pStudent->output();
}

void StudentManage::viewAllCommodities() const
{
    cout<<"ѧ����Ŀ:"<< pStudents.size()<<endl;
    if(pStudents.size()==0)
        return;
    cout<<"ָ������ʽ\n(0-ѧ��ID,1-ѧ������,2-ƽ���ɼ���3-���гɼ���4-��ĩ�ɼ� ):";
    int type;
    cin>>type;
    const_cast<StudentManage*>(this)->sortCommoditiesByType(type);
    for(auto e:pStudents)
        e->output();
}

void StudentManage::checkOut() const
{

cout<<endl;
    cout<<"======ѧ����Ŀ: "<< pStudents.size()<<endl;
    cout << "ѧ������\t"
         << "����\t"
         << "��ĩ\t"
         << "ƽ���ɼ�\t\n";

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
            getline(in, buf); //��ȡ id ������Ļس�Ҫ���� buf ��
            getline(in, name);
            in >> mid >> final>>avg;
            addStudent( new
                        Student(id,name,mid,final,avg));
        }
    }
    sortCommodities();
}
