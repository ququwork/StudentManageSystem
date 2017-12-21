#ifndef STUDENTMANAGE_H
#define STUDENTMANAGE_H
#include"Student.h"
#include <vector>
#include<string.h>
class StudentManage{
public:
    StudentManage()=default;
    ~StudentManage();
    StudentManage(const StudentManage& c)=delete;
    StudentManage& operator=(const StudentManage& c)=delete;
    void addStudent(Student* p);
    void removeStudent(int id);
    void viewStudent(int id)const;
    void viewAllCommodities()const;
    void checkOut()const;
    void readData(std::string filename);
    void saveData(std::string filename);

    void displaystudent();

private:
    std::vector<Student*> pStudents;

    Student* findStudentById(int id);
    Student *findEmployeeByName(std::string name2);

    const Student* findStudentById(int id)const;
    std::vector<Student*>::iterator getIterator(Student* p);

    int sortType=0; //记录当前排序类型
    void sortCommodities();
    void sortCommoditiesByType(int type);
};


#endif // STUDENTMANAGE_H
