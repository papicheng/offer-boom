#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
# define LEN sizeof(struct Student)
 
struct Student {
	char num[10];  /*ѧ��*/
	char name[20]; /*����*/
	char sex[10];  /*�Ա�*/
	int age;       /*����*/
	char phone[12];/*�绰*/
	char qq[12];   /*QQ��*/
	char nativePlace[20];/*����*/
	char department[20];/*ϵ��*/
	char major[20];/*רҵ*/
	char className[20];/*�༶*/
	struct Student *next;
};
 
char filename[30];//ȫ�ֱ�������������Ҫ�򿪵��ļ�����
 
				  /*��������*/
struct Student *Creat(int n) {
	void menu_print_in(void);
	struct Student *head;
	struct Student *p1, *p2;
    int i;
	system("cls");
	for (i = 1;i < n + 1;i++) {
		p1 = (struct Student*)malloc(LEN);
		menu_print_in();
		scanf("%s %s %s %d %s %s %s %s %s %s", p1->num, p1->name, p1->sex,
			&p1->age, p1->phone, p1->qq,p1->nativePlace,p1->department,p1->major,p1->className);
		p1->next = NULL;
		if (i == 1) {
			head = p2 = p1;
		}
		else {
			p2->next = p1;
			p2 = p1;
		}
	}
	return(head);
}
 
/*���ݴ���(wbֻд)*/
void WriteData_wb(struct Student *head) {
	FILE *fp;
	struct Student *p;
	if ((fp = fopen(filename, "wb")) == NULL)
		printf("\a error! Can not open the file!");
	p = head;
	while (p != NULL) {
		if (fwrite(p, LEN, 1, fp) != 1) {
			printf("д�����ݳ���\n");
			fclose(fp);
			return;
		}
		p = p->next;
	}
	fclose(fp);
}
 
///*���ݴ���(ab׷��)
void WriteData_ab(struct Student *head) {
	FILE *fp;
	struct Student *p;
	if ((fp = fopen(filename, "ab")) == NULL)
		printf("\a error! Can not open the file!");
	p = head;
	while (p != NULL) {
		if (fwrite(p, LEN, 1, fp) != 1) {
			printf("д�����ݳ���\n");
			fclose(fp);
			return;
		}
		p = p->next;
	}
	fclose(fp);
}
/*��ȡ����*/
/*��ȡ�����ļ����浽������ ������ָ�������ͷָ��*/
struct Student *ReadData(void) {
	struct Student *head = NULL;
	struct Student *p1, *p2;//s = p1;p = p2;
 
	FILE *fp;
	if ((fp = fopen(filename, "rb+")) == NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	while (!feof(fp)) {
		if ((p1 = (struct Student*)malloc(LEN)) == NULL) {
			printf("�ڴ��������\n");
			fclose(fp);
			exit(0);
		}
		if (fread(p1, LEN, 1, fp) != 1) {
			free(p1);
			break;
		}
		if (head == NULL)
			head = p2 = p1;
		else {
			p2->next = p1;
			p2 = p1;
		}
	}
	fclose(fp);
	return (head);
}
 
/*��1��ȫ����ѯ*/
void Print_inquire_all(void) {
	void menu_print_out(void);
	struct Student *pt;
	pt = ReadData();
	menu_print_out();
	do {
		printf("%-10s%6s%8s%4d%13s%11s  %s %s %s %s\n",
			pt->num, pt->name, pt->sex, pt->age, pt->phone, pt->qq, pt->nativePlace, pt->department, pt->major, pt->className);
		pt = pt->next;
	} while (pt != NULL);
	printf("\n\n");
}
 
/*��2��ѧ�Ų�ѯ*/
int Print_inquire_num() {
	void menu_print_out(void);
	struct Student *pt;
	char str_num[10];
	printf("����������Ҫ��ѯ��ѧ��:");
	scanf("%s", str_num);
	pt = ReadData();
	menu_print_out();
	do {
		if (strcmp(pt->num, str_num) == 0) {
			printf("%-10s%6s%8s%4d%13s%11s %s %s %s %s\n",
				pt->num, pt->name, pt->sex, pt->age, pt->phone, pt->qq, pt->nativePlace, pt->department, pt->major, pt->className);
			printf("\n\n");
			return 0;
		}
		pt = pt->next;
	} while (pt != NULL);
	printf("���ݿ���û�д洢��Ҫ��ѯ�����ݣ�\n");
	printf("\n\n");
	return 0;
}
 
/*��3��������ѯ*/
int Print_inquire_name() {
	void menu_print_out(void);
	struct Student *pt;
	char str_name[20];
	printf("����������Ҫ��ѯ������:");
	scanf("%s", str_name);
	pt = ReadData();
	menu_print_out();
	do {
		if (strcmp(pt->name, str_name) == 0) {
			printf("%-10s%6s%8s%4d%13s%11s  %s %s %s %s\n",
				pt->num, pt->name, pt->sex, pt->age, pt->phone, pt->qq, pt->nativePlace, pt->department, pt->major, pt->className);
			printf("\n\n");
			return 0;
		}
		pt = pt->next;
	} while (pt != NULL);
	printf("���ݿ���û�д洢��Ҫ��ѯ�����ݣ�\n");
	printf("\n\n");
	return 0;
}
 
/*��4��ģ����ѯ*/
int Print_inquire_fuzzy(void) {
	void menu_print_out(void);
	struct Student *pt;
	char str_find[20];
	int m = 0;
	printf("����������Ҫ��ѯ�Ĺؼ���:");
	scanf("%s", str_find);
	pt = ReadData();
	menu_print_out();
	do {
		if (strstr(pt->num, str_find) != 0 || strstr(pt->name, str_find) != 0
			|| strstr(pt->sex, str_find) != 0 || strstr(pt->phone, str_find) != 0
			|| strstr(pt->qq, str_find) != 0) {
			printf("%-10s%6s%8s%4d%13s%11s %s %s %s %s\n",
				pt->num, pt->name, pt->sex, pt->age, pt->phone, pt->qq, pt->nativePlace, pt->department, pt->major, pt->className);
			m = 1;
		}
		pt = pt->next;
	} while (pt != NULL);
	if (!m)
		printf("���ݿ���û�д洢��Ҫ��ѯ�����ݣ�\n");
	printf("\n\n");
	return 0;
}
 
/*��1���޸�����֮ɾ����¼*/
int Delete() {
	struct Student *pt1, *pt2, *head;
	char str_num[20];
	printf("\n����������Ҫɾ����ѧ����Ϣ:");
	scanf("%s", str_num);
	pt1 = ReadData();
	pt2 = pt1->next;
	head = pt1;
	while (pt2 != NULL) {
		if (strcmp(pt1->num, str_num) == 0) {
			WriteData_wb(pt2);
		}
		else if (strcmp(pt2->num, str_num) == 0) {
			pt1->next = pt2->next;
			WriteData_wb(head);
		}
		pt2 = pt2->next;
		pt1 = pt1->next;
	}
	if (pt2 != NULL)
		printf("���ݿ���û�д洢��Ҫɾ�������ݣ�\n");
	printf("\n\n");
	return 0;
}
 
/*��2���޸�����֮�޸ļ�¼*/
int Amend() {
	void menu_print_in(void);
	struct Student *pt1, *pt2, *head;
	char str_num[20];
	printf("����������Ҫ�޸ĵ�ѧ����Ϣ:");
	scanf("%s", str_num);
	pt1 = ReadData();
	pt2 = pt1->next;
	head = pt1;
	while (pt2 != NULL) {
		if (strcmp(pt1->num, str_num) == 0) {
			menu_print_in();
			scanf("%s %s %s %d %s %s %s %s %s %s", pt1->num, pt1->name, pt1->sex,
				&pt1->age, pt1->phone, pt1->qq, pt1->nativePlace, pt1->department, pt1->major, pt1->className);
			WriteData_wb(head);
		}
		else if (strcmp(pt2->num, str_num) == 0) {
			menu_print_in();
			scanf("%s %s %s %d %s %s %s %s %s %s", pt2->num, pt2->name, pt2->sex,
				&pt2->age, pt2->phone, pt2->qq, pt2->nativePlace, pt2->department, pt2->major, pt2->className);
			WriteData_wb(head);
		}
		pt2 = pt2->next;
		pt1 = pt1->next;
	}
	if (pt2 != NULL)
		printf("���ݿ���û�д洢��Ҫɾ�������ݣ�\n");
	return 0;
}
 
/*��3���޸�����֮��������*/
int Neaten() {
	struct Student *first;
	struct Student *tail;
	struct Student *p_min;
	struct Student *min;
	struct Student *p;
	struct Student *head;
	head = ReadData();
	first = NULL;
	while (head != NULL) {
		for (p = head, min = head; p->next != NULL; p = p->next) {
			if (strcmp(p->next->num, min->num) < 0) {
				p_min = p;
				min = p->next;
			}
		}
		if (first == NULL) {
			first = min;
			tail = min;
		}
		else {
			tail->next = min;
			tail = min;
		}
		if (min == head) {
			head = head->next;
		}
		else {
			p_min->next = min->next;
		}
	}
	if (first!= NULL) {
		tail->next = NULL;
	}
	head=first;
 
	WriteData_wb(head);
	return 0;
}
 
/*����д�����ݵ�����*/
int Creat_num(void) {
	int n;
	printf("\n�����������˴�Ҫ��ӵ����ݸ���:");
	
	if (scanf("%d", &n) != 1) {
		printf("\a error!");
	}
	return n;
}
 
/*ѡ��Ҫ�򿪵��ļ�*/
int File_name() {
	printf("\n������������Ҫ�򿪵��ļ�:");
	if (scanf("%s", filename) != 1)
		printf("\a error!");
	return 0;
}
 
/*���˵�*/
void menu(void) {
	void menu_add(void);
	void menu_inquire(void);
	void menu_amend(void);
	int a = 0;
	printf("              �q�T�T�T�T�T�T�T�T�r              \n");
	printf("�q�T�T�T�T�T�T�gѧ������ϵͳV1.0�d�T�T�T�T�T�T�r\n");
	printf("�U            �t�T�T�T�T�T�T�T�T�s            �U\n");
	printf("�U   ��1���������           ��3���޸�����    �U\n");
	printf("�U                                            �U\n");
	printf("�U   ��2����ѯ����           ��4���˳�ϵͳ    �U\n");
	printf("�U                                            �U\n");
	printf("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
	printf("�������빦��ǰ����Ž�����Ӧ�Ĺ���:��   ��\b\b");
 
	
	a = getchar();
 
	while (a!='1'&&a!='2'&&a!='3'&&a!='4') {
		printf("error! please input the right number!\n");
		putchar('\a');
		getchar();
		printf("�����������빦��ǰ����Ž�����Ӧ�Ĺ���:��   ��\b\b");
		a = getchar();
	}
	switch (a) {
	case '1': File_name();menu_add();
		break;
	case '2': File_name();menu_inquire();
		break;
	case '3': File_name();menu_amend();
		break;
	case '4': exit(0);
		break;
	}
	getchar();
}
 
/*�����˵�֮�������*/
void menu_add(void) {
	int a = 0;
	system("cls");
	getchar();
	printf("              �q�T�T�T�T�T�T�T�T�r              \n");
	printf("�q�T�T�T�T�T�T�g  ������ݷ�ʽ  �d�T�T�T�T�T�T�r\n");
	printf("�U            �t�T�T�T�T�T�T�T�T�s            �U\n");
	printf("�U ��1���½��ļ� ��2���������� ��3�����ز˵�  �U\n");
	printf("�U                                            �U\n");
	printf("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
	printf("�������빦��ǰ����Ž�����Ӧ�Ĺ���:��   ��\b\b");
 
	
	a = getchar();
 
	while (a != '1'&&a != '2'&&a != '3') {
		printf("error! please input the right number!\n");
		putchar('\a');
		getchar();
		printf("�����������빦��ǰ����Ž�����Ӧ�Ĺ���:��   ��\b\b");
		a = getchar();
	}
	switch (a) {
	case '1': WriteData_wb(Creat(Creat_num()));
		printf("\n���½��ļ��ɹ��������ѳɹ������\n");
		system("pause");
		system("cls");
		menu_add();
		break;
	case '2': WriteData_ab(Creat(Creat_num()));
		printf("\n�������ѳɹ���ӡ�\n");
		system("pause");
		system("cls");
		menu_add();
		break;
	case '3': system("cls");
		getchar();
		menu();
		break;
	}
}
 
/*�����˵�֮��ѯ����*/
void menu_inquire(void) {
	int a = 0;
	system("cls");
	getchar();
	while (1) {
		system("cls");
		printf("              �q�T�T�T�T�T�T�T�T�r              \n");
		printf("�q�T�T�T�T�T�T�g  ��ѯ���ݷ�ʽ  �d�T�T�T�T�T�T�r\n");
		printf("�U            �t�T�T�T�T�T�T�T�T�s            �U\n");
		printf("�U    ��1��ȫ����ѯ         ��4��ģ����ѯ     �U\n");
		printf("�U                                            �U\n");
		printf("�U    ��2��ѧ�Ų�ѯ         ��5�����ز˵�     �U\n");
		printf("�U                                            �U\n");
		printf("�U    ��3��������ѯ                           �U\n");
		printf("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
		printf("�������빦��ǰ����Ž�����Ӧ�Ĺ���:��   ��\b\b");
		
		a = getchar();
 
		while (a!='1'&&a!='2'&&a!='3'&&a!='3'&&a!='4'&&a!='5'&&a!= '6') {
			printf("error! please input the right number!\n");
			putchar('\a');
			getchar();
			printf("�����������빦��ǰ����Ž�����Ӧ�Ĺ���:��   ��\b\b");
			a = getchar();
		}
		switch (a) {
		case '1': Print_inquire_all();system("pause");getchar();
			break;
		case '2': Print_inquire_num();system("pause");getchar();
			break;
		case '3': Print_inquire_name();system("pause");getchar();
			break;
		case '4': Print_inquire_fuzzy();system("pause");getchar();;
			break;
		case '5': system("cls");getchar();menu();
			break;
		}
	}
}
 
/*�����˵�֮�޸�����*/
void menu_amend(void) {
	int a = 0;
	system("cls");
	getchar();
	while (1) {
		system("cls");
		printf("              �q�T�T�T�T�T�T�T�T�r              \n");
		printf("�q�T�T�T�T�T�T�g  �޸����ݷ�ʽ  �d�T�T�T�T�T�T�r\n");
		printf("�U            �t�T�T�T�T�T�T�T�T�s            �U\n");
		printf("�U    ��1��ɾ����¼          ��3����������    �U\n");
		printf("�U                                            �U\n");
		printf("�U    ��2���޸ļ�¼          ��4�����ز˵�    �U\n");
		printf("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
		printf("�������빦��ǰ����Ž�����Ӧ�Ĺ���:��   ��\b\b");
 
		
		a = getchar();
 
		while (a!='1'&&a!='2'&&a!='3'&&a!='4') {
			printf("error! please input the right number!\n");
			putchar('\a');
			getchar();
			printf("�����������빦��ǰ����Ž�����Ӧ�Ĺ���:��   ��\b\b");
			a = getchar();
		}
		switch (a) {
		case '1': Delete();
			printf("\n\n���ѳɹ�ɾ��ָ�����ݡ�\n");
			system("pause");
			getchar();
			break;
		case '2': Amend();
			printf("\n\n���ѳɹ��޸�ָ�����ݡ�\n");
			system("pause");
			getchar();
			break;
		case '3': Neaten();
			printf("\n\n�������ѳɹ�����ѧ���������С�\n");
			system("pause");
			getchar();
			break;
		case '4': system("cls");
			getchar();
			menu();
			break;
		}
	}
}
 
/*���������ʾ��*/
void menu_print_in(void) {
	printf("------------------------------------------------------------------------\n");
	printf("ѧ��      ����     �Ա�  ����    �绰         QQ        ����  ϵ��  רҵ  �༶   \n");
	printf("------------------------------------------------------------------------\n");
}
void menu_print_out(void) {
	printf("--------------------------------------------------------------------------\n");
	printf("ѧ��      ����     �Ա�  ����    �绰         QQ        ����  ϵ��  רҵ  �༶ \n");
	printf("--------------------------------------------------------------------------\n");
}
 
/*������*/
int main(void) {
	SetConsoleTitle("ѧ��ѧ������ϵͳ");
	menu();
	return 0;
}
