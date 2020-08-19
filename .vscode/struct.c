#include<stdio.h>
struct student
{
    char name[20];//name姓名
    int age;
    int Stu_id;
    int score;//成绩
};
int main()
{
    struct student Gdd={"Gdd",20,2020,33};
    struct student *Gdd_pointer=&Gdd;
    printf("姓名 年龄 学号 成绩\n");
    printf("%-5s %-5d %-5d %-5d\n",Gdd.name,Gdd.age,Gdd.Stu_id,Gdd.score);
    (*Gdd_pointer).age+=30;//年龄加30
    printf("%-5s %-5d %-5d %-5d\n",(*Gdd_pointer).name,(*Gdd_pointer).age,(*Gdd_pointer).Stu_id,(*Gdd_pointer).score);
    return 0;
}

// struct student stu[3];///定义三个学生
//     int i;
//     printf("请输入三位学生的姓名、年龄、学号、成绩(以空格分开输入)：\n");
//     for(i=0;i<3;i++)
//     {
//         printf("请输入第%d个学生的信息:",i+1);
//         scanf("%s%d%d%d",stu[i].name,&stu[i].age,&stu[i].Stu_id,&stu[i].score);
//     }
//     printf("姓名 年龄 学号 成绩\n");
//     for(i=0;i<3;i++)
//     {
//         printf("%-5s %-5d %-5d %-5d\n",stu[i].name,stu[i].age,stu[i].Stu_id,stu[i].score);
//     }