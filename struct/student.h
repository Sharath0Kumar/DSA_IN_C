#ifndef STUDENT_H
#define STUDENT_H
struct Student
{
       int Student_ID;
       int age;
       int marks;
       char Name[30];
       char course[30];
};
typedef struct List
{
Student*head;
int count;
}List;
void insert(List *list);
#endif // STUDENT_H
