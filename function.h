#ifndef FUNCTION_H
#define FUNCTION_H

#include "StudentManage.h"
char menu();
void doAddStudent(StudentManage& cm);

void doRemoveStudent(StudentManage& cm);
void doViewStudent(const StudentManage& cm);
void doViewAllStudent(const StudentManage& cm);
void doCheckout(const StudentManage& cm);

#endif // FUNCTION_H
