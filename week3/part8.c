#include<stdio.h>
#include<string.h>
struct Student
{
    char name[100];
    int yob;
    char class[100];
};
int main()
{
    struct Student student1;
    printf("Input name of student 1: ");
    fgets(student1.name,sizeof(student1.name),stdin);
    printf("Input YOB of student 1: ");
    scanf("%d",&student1.yob);
    getchar();
    printf("Input class of student 1: ");
    fgets(student1.class,sizeof(student1.class),stdin);
   
    struct Student student2;
    printf("Input name of student 2: ");
    fgets(student2.name,sizeof(student2.name),stdin);
    printf("Input YOB of student 2: ");
    scanf("%d",&student2.yob);
    getchar();
    printf("Input class of student 2: ");
    fgets(student2.class,sizeof(student2.class),stdin);
    if(student1.yob > student2.yob)
    {
        printf("Name is %s",student1.name);
        printf("YOB %d\n",student1.yob);
        printf("Class %s",student1.class);
    }
    else
    {
        printf("Name is %s",student2.name);
        printf("YOB %d\n",student2.yob);
        printf("Class %s",student2.class);
    }
   
}
