#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"student.h"
void insert()
{
    struct Student *newNode,*temp;
    newNode=(struct student*)malloc(sizeof(struct student));
    if(newNode==NULL)
    {
        printf("memory allocation failed \n");
        return;
    }
    printf("enter the student id");
    scanf("%d",newNode->Student_ID);
    printf("enter the age");
    scanf("%d",newNode->age);
    printf("enter the marks");
    scanf("%d",newNode->marks);
    printf("enter the name of the student");
    scanf("%d",&newNode->Name;)
    printf("enter the course name");
    scanf("%d",&newNode->course);
}
 int main(void)
{
    List list;
    list.head  = NULL;
    list.count = 0;
    int choice;
    printf("enter the choice");
    switch(choice):
        case1:insert(&List;)



    return 0;
}
