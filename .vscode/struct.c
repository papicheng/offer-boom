#include<stdio.h>
struct student
{
    char name[20];//name����
    int age;
    int Stu_id;
    int score;//�ɼ�
};
int main()
{
    struct student Gdd={"Gdd",20,2020,33};
    struct student *Gdd_pointer=&Gdd;
    printf("���� ���� ѧ�� �ɼ�\n");
    printf("%-5s %-5d %-5d %-5d\n",Gdd.name,Gdd.age,Gdd.Stu_id,Gdd.score);
    (*Gdd_pointer).age+=30;//�����30
    printf("%-5s %-5d %-5d %-5d\n",(*Gdd_pointer).name,(*Gdd_pointer).age,(*Gdd_pointer).Stu_id,(*Gdd_pointer).score);
    return 0;
}

// struct student stu[3];///��������ѧ��
//     int i;
//     printf("��������λѧ�������������䡢ѧ�š��ɼ�(�Կո�ֿ�����)��\n");
//     for(i=0;i<3;i++)
//     {
//         printf("�������%d��ѧ������Ϣ:",i+1);
//         scanf("%s%d%d%d",stu[i].name,&stu[i].age,&stu[i].Stu_id,&stu[i].score);
//     }
//     printf("���� ���� ѧ�� �ɼ�\n");
//     for(i=0;i<3;i++)
//     {
//         printf("%-5s %-5d %-5d %-5d\n",stu[i].name,stu[i].age,stu[i].Stu_id,stu[i].score);
//     }