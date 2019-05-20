#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<assert.h>
#include<Windows.h>

typedef struct book {
	char book_name[30];
	int bianhao;
	double price;
	char author[20];
	char state[20];
	char name[20];
	char sex[10];
	int xuehao;
	struct book *book_next;
}book;
typedef struct club {
	char name[20];
	char sex[10];
	int xuehao;
	char borrow[30];
	struct club *club_next;
}club;
book*load_in_book(char *books);
void load_out_book(char *books, book*list);
club* load_in_club(char *clubs);
void load_out_club(char *clubs, club*list);
void Print_Book(book *head_book);//�������ͼ����Ϣ
void Print_Club(club *head_club);//������л�Ա��Ϣ
book *Insert_Book(book*list, book* a);
book *Create_New_Book(club*list);//�����µ�ͼ��⣬ͼ��������Ϊ0ʱ����
book *Search_Book_bianhao(int bianhao, book *head_book);
book *Search_Book_name(char *b_name, book *head_book);
book *Search_Book_price(double price_h, double price_l, book *head_book);
book *Delete_Book(book *head_book, int bianhao);//ɾ��ͼ��
club *Create_New_Club(club*list);
club *Search_Club_xuehao(int xuehao, club *head_club);
club *Search_Club_name(char *c_name, club *head_club);
club *Insert_Club(club*list, club*a);
club *Delete_Club(club *head_club, int xuehao);
book *Lent_Book(int bianhao, int xuehao, book *head_book, club *head_club);
book *back(int bianhao, int xuehao, book *head_book, club *head_club);
int main()
{
	book *head_book = NULL, *p_book;
	char book_name[30], name[20], author[20], sex[10], books[20] = "books.bin", clubs[20] = "clubs.bin";
	int bianhao;
	double price, price_h, price_l;
	int size_book = sizeof(book);
	int m = 1, n = 1, f;
	char *b_name, *c_name;
	club *head_club = NULL, *p_club;
	int xuehao;
	int size_club = sizeof(club);
	int who;
	int choice = 1;
	head_book = load_in_book(books);
	head_club = load_in_club(clubs);
	//assert(sizeof(club));
	printf("��ӭʹ�ñ�ͼ��ݹ���ϵͳ\n");
	printf("�����������ݣ�[1]:����Ա[2]:ע���Ա\n");
	scanf("%d", &who);
	system("cls");
	while (choice != 0 && who == 1) {
		char number[13];
		char answer[13] = "shanweijixin";
		printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
		printf("��������������롣\n");
		scanf("%s", &number);
		system("cls");
		printf("\n��ӭʹ�ñ�ͼ�����ϵͳ!\n\n");
		if (strcmp(answer, number) == 0) {
			while (choice != 0) {
				printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
				printf("\t\t\t[1]:���ͼ��\t"); printf(" [4]:��ӻ�Ա\n");
				printf("\t\t\t[2]:ɾ��ͼ��\t"); printf(" [5]:ɾ����Ա\n");
				printf("\t\t\t[3]:����ͼ��\t"); printf("[6]:������Ա\n\n");
				printf("\t\t\t****************\n\n");
				printf("\t\t\t0:�˳�\n\n");
				scanf("%d", &choice);
				switch (choice) {
				case 1:
					system("cls");
					printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
					printf("������ͼ������:");
					scanf("%s", book_name);
					printf("������ͼ����:");
					scanf("%d", &bianhao);
					printf("�����뵥��:");
					scanf("%lf", &price);
					printf("��������������:");
					scanf("%s", author);
					printf("\n");
					book *ptr_b;
					if (m) {
						p_book = (book *)malloc(size_book);
						strcpy(p_book->book_name, book_name);
						p_book->bianhao = bianhao;
						p_book->price = price;
						p_book->xuehao = 0;
						strcpy(p_book->author, author);
						strcpy(p_book->state, "����");
						strcpy(p_book->sex, "����");
						strcpy(p_book->name, "����");
						p_book->book_next = NULL;
						book *list = head_book;
						for (; (list->book_next != NULL) && (list->bianhao>p_book->bianhao); list = list->book_next);
						{
							p_book->book_next = list->book_next;
							list->book_next = p_book;
						}
						printf("\n���ͼ��ɹ�!\n\n");
					}
					break;
				case 2:
					system("cls");
					printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
					printf("����ɾ��ͼ����:\n");
					scanf("%d", &bianhao);
					head_book = Delete_Book(head_book, bianhao);
					printf("\nɾ��ͼ��ɹ�!\n\n");
					break;
				case 3:
					system("cls");
					printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
					Print_Book(head_book);
					break;
				case 4:
					system("cls");
					printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
					printf("�������Ա����:");
					scanf("%s", name);
					printf("�������Ա�Ա�:");
					scanf("%s", sex);
					printf("�������Աѧ��:");
					scanf("%d", &xuehao);
					printf("\n");
					club *ptr_c;
					if (n) {
						p_club = (club *)malloc(sizeof(club));
						strcpy(p_club->name, name);
						strcpy(p_club->sex, sex);
						p_club->xuehao = xuehao;
						strcpy(p_club->borrow, "����");
						head_club = Insert_Club(head_club, p_club);
						printf("\n��ӻ�Ա�ɹ�!\n\n");
					}
					break;
				case 5:
					system("cls");
					printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
					printf("����Ҫɾ����Աѧ��:\n");
					scanf("%d", &xuehao);
					head_club = Delete_Club(head_club, xuehao);
					printf("\nɾ����Ա�ɹ�!\n\n");
					break;
				case 6:
					system("cls");
					printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
					Print_Club(head_club);
					break;
				case 0:
					break;
				default:
					printf("��Чѡ�������ѡ��\n");
				}
			}
		}
		else
			printf("��������������������롣\n");
	}
	while (choice != 0 && who == 2) {
		printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
		printf("\n");
		printf("\t\t\t[1]:�������\t"); printf(" [3]:�������\n");
		printf("\n");
		printf("\t\t\t[2]:��ѯͼ��\t"); printf(" [4]:��ѯ��Ա\n");
		printf("\t\t\t****************\n\n");
		printf("\t\t\t0:�˳�\n\n");
		printf("��ѡ��<0~4>:");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
			printf("��������ͼ����:\n");
			scanf("%d", &bianhao);
			printf("��������˵�ѧ��:\n");
			scanf("%d", &xuehao);
			head_book = Lent_Book(bianhao, xuehao, head_book, head_club);
			system("cls");
			printf("\n���ĳɹ�!\n\n");
			printf("�����Ϣ����:\n\n");
			head_book = Search_Book_bianhao(bianhao, head_book);
			break;
		case 2:
			system("cls");
			printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
			printf("1.����Ų�ѯ\n\n");
			printf("2.�����Ʋ�ѯ\n\n");
			printf("3.���۸������ѯ\n\n");
			printf("0.�������˵�\n\n");
			printf("��ѡ��:");
			scanf("%d", &f);
			if (f == 1) {
				printf("�������ѯͼ����:");
				scanf("%d", &bianhao);
				printf("�����Ϣ����:\n\n");
				head_book = Search_Book_bianhao(bianhao, head_book);
				break;
			}
			else if (f == 2) {
				b_name = book_name;
				getchar();
				printf("�������ѯͼ������:");
				gets(b_name);
				printf("�����Ϣ����:\n\n");
				head_book = Search_Book_name(b_name, head_book);
				break;
			}
			else if (f == 3) {
				printf("��������߼۸�:");
				scanf("%lf", &price_h);
				printf("��������ͼ۸�:");
				scanf("%lf", &price_l);
				printf("�����Ϣ����:\n\n");
				head_book = Search_Book_price(price_h, price_l, head_book);
				break;
			}
			else if (f == 0) {
				break;
			}
			break;
		case 3:
			printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
			printf("��������ͼ����:\n");
			scanf("%d", &bianhao);
			printf("���뻹���˵�ѧ��:\n");
			scanf("%d", &xuehao);
			head_book = back(bianhao, xuehao, head_book, head_club);
			system("cls");
			printf("\n�黹�ɹ�!\n\n");
			printf("�����Ϣ����:\n\n");
			head_book = Search_Book_bianhao(bianhao, head_book);
			break;
		case 4:
			system("cls");
			printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
			printf("1.��ѧ�Ų�ѯ\n\n");
			printf("2.��������ѯ\n\n");
			printf("0.�������˵�\n\n");
			printf("��ѡ��:");
			scanf("%d", &f);
			if (f == 1) {
				printf("�������ѯ��Աѧ��:");
				scanf("%d", &xuehao);
				printf("�����Ϣ����:\n\n");
				head_club = Search_Club_xuehao(xuehao, head_club);
				break;
			}
			else if (f == 2) {
				c_name = name;
				getchar();
				printf("�������ѯ��Ա����:");
				gets(c_name);
				printf("�����Ϣ����:\n\n");
				head_club = Search_Club_name(c_name, head_club);
				break;
			}
			else if (f == 0) {
				break;
			}
			break;
			printf("�������ѯ��Աѧ��:\n");
			scanf("%d", &xuehao);
			printf("�����Ϣ����:\n\n");

			break;
		case 0:
			system("cls");
			printf("\n\t\t\t*****ͼ�����ϵͳ*****\n\n");
			printf("\nлл����ʹ��!\n\n");
			break;
		}
	}
	load_out_book(books, head_book);
	load_out_club(books, head_club);
	return 0;
}
book *Insert_Book(book*list, book* a)
{
	book *head_book, *p_book;
	int bianhao;
	double price;
	char book_name[30], author[20];
	int size_book = sizeof(book);
	head_book = list;
	p_book = (book *)malloc(size_book);
	strcpy(p_book->book_name, a->book_name);
	p_book->bianhao = a->bianhao;
	p_book->price = a->price;
	p_book->xuehao = a->xuehao;
	strcpy(p_book->author, a->author);
	strcpy(p_book->state, a->state);
	strcpy(p_book->sex, a->sex);
	strcpy(p_book->name, a->name);
	if (list == NULL)
		return p_book;
	else
		for (; (list->book_next != NULL) && (list->bianhao>a->bianhao); list = list->book_next);
	{
		p_book->book_next = list->book_next;
		list->book_next = p_book;
	}
	return head_book;
}
book *Search_Book_bianhao(int bianhao, book *head_book)
{
	book *ptr_book;
	int flag = 0;
	for (ptr_book = head_book; ptr_book; ptr_book = ptr_book->book_next)
	{
		if (ptr_book->bianhao == bianhao) {
			printf("ͼ����:%d\n", ptr_book->bianhao);
			printf("ͼ������:%s\n", ptr_book->book_name);
			printf("ͼ�鵥��:%.2lf\n", ptr_book->price);
			printf("ͼ������:%s\n", ptr_book->author);
			printf("����״̬:%s\n", ptr_book->state);
			printf("����������:%s\n", ptr_book->name);
			printf("�������Ա�:%s\n", ptr_book->sex);
			printf("ѧ��:%d\n", ptr_book->xuehao);
			printf("\n");
			flag++;
		}
	}
	if (flag == 0) {
		printf("���޴�ͼ����Ϣ!\n\n");
	}
	return head_book;
}
book *Search_Book_name(char *b_name, book *head_book)
{
	book *ptr_book;
	int flag = 0;
	for (ptr_book = head_book; ptr_book; ptr_book = ptr_book->book_next)
	{
		if (strcmp(ptr_book->book_name, b_name) == 0) {
			printf("ͼ����:%d\n", ptr_book->bianhao);
			printf("ͼ������:%s\n", ptr_book->book_name);
			printf("ͼ�鵥��:%.2lf\n", ptr_book->price);
			printf("ͼ������:%s\n", ptr_book->author);
			printf("����״̬:%s\n", ptr_book->state);
			printf("����������:%s\n", ptr_book->name);
			printf("�������Ա�:%s\n", ptr_book->sex);
			printf("ѧ��:%d\n", ptr_book->xuehao);
			printf("\n");
			flag++;
		}
	}
	if (flag == 0) {
		printf("���޴�ͼ����Ϣ!\n\n");
	}
	return head_book;
}
book *Search_Book_price(double price_h, double price_l, book *head_book)
{
	book *ptr_book;
	int flag = 0;
	for (ptr_book = head_book; ptr_book; ptr_book = ptr_book->book_next)
	{
		if ((ptr_book->price >= price_l) && (ptr_book->price <= price_h)) {
			printf("ͼ����:%d\n", ptr_book->bianhao);
			printf("ͼ������:%s\n", ptr_book->book_name);
			printf("ͼ�鵥��:%.2lf\n", ptr_book->price);
			printf("ͼ������:%s\n", ptr_book->author);
			printf("����״̬:%s\n", ptr_book->state);
			printf("����������:%s\n", ptr_book->name);
			printf("�������Ա�:%s\n", ptr_book->sex);
			printf("ѧ��:%d\n", ptr_book->xuehao);
			printf("\n");
			flag++;
		}
	}
	if (flag == 0) {
		printf("���޴�ͼ����Ϣ!\n\n");
	}
	return head_book;
}
book *Delete_Book(book *head_book, int bianhao)
{
	book *ptr1_book, *ptr2_book;

	while (head_book != NULL && head_book->bianhao == bianhao) {
		ptr2_book = head_book;
		head_book = head_book->book_next;
		free(ptr2_book);
	}
	if (head_book == NULL)
		return NULL;

	ptr1_book = head_book;
	ptr2_book = head_book->book_next;
	while (ptr2_book != NULL) {
		if (ptr2_book->bianhao == bianhao) {
			ptr1_book->book_next = ptr2_book->book_next;
			free(ptr2_book);
		}
		else
			ptr1_book = ptr2_book;
		ptr2_book = ptr1_book->book_next;
	}

	return head_book;
}
club *Insert_Club(club*list, club*a)
{
	club *head_club, *p_club;
	int xuehao;
	char name[20], sex[10];
	int size_club = sizeof(club);
	p_club = (club *)malloc(size_club);
	strcpy(p_club->name, a->name);
	strcpy(p_club->sex, a->sex);
	p_club->xuehao = a->xuehao;
	strcpy(p_club->borrow, a->borrow);
	if (list == NULL)
		return p_club;
	else
		for (; (list->club_next != NULL) && (list->xuehao>p_club->xuehao); list = list->club_next);
	{
		p_club->club_next = list->club_next;
		list->club_next = p_club;
	}
	return head_club;
}
club *Search_Club_xuehao(int xuehao, club *head_club)
{
	club *ptr_club;
	int flag = 0;
	for (ptr_club = head_club; ptr_club; ptr_club = ptr_club->club_next)
	{
		if (ptr_club->xuehao == xuehao) {
			printf("��Ա����:%s\n", ptr_club->name);
			printf("��Ա�Ա�:%s\n", ptr_club->sex);
			printf("��Աѧ��:%d\n", ptr_club->xuehao);
			printf("����ͼ��:%s\n", ptr_club->borrow);
			printf("\n");
			flag++;
		}
	}
	if (flag == 0) {
		printf("���û�������!\n\n");
	}
	return head_club;
}
club *Search_Club_name(char *c_name, club *head_club)
{
	club *ptr_club;
	int flag = 0;
	for (ptr_club = head_club; ptr_club; ptr_club = ptr_club->club_next)
	{
		if (strcmp(ptr_club->name, c_name) == 0) {
			printf("��Ա����:%s\n", ptr_club->name);
			printf("��Ա�Ա�:%s\n", ptr_club->sex);
			printf("��Աѧ��:%d\n", ptr_club->xuehao);
			printf("����ͼ��:%s\n", ptr_club->borrow);
			printf("\n");
			flag++;
		}
	}
	if (flag == 0) {
		printf("���û�������!\n\n");
	}
	return head_club;
}
book *Lent_Book(int bianhao, int xuehao, book *head_book, club *head_club)
{
	book *ptr_book;
	club *ptr_club;
	int flag = 0;

	for (ptr_book = head_book; ptr_book; ptr_book = ptr_book->book_next)
		if (ptr_club != NULL)
			for (ptr_club = head_club; ptr_club; ptr_club = ptr_club->club_next)
			{
				if ((ptr_book->bianhao == bianhao) && (ptr_club->xuehao == xuehao))
				{
					strcpy(ptr_book->name, ptr_club->name);   //�ַ����ĸ��ƣ����ұߵ����ݸ��Ƶ����
					strcpy(ptr_book->sex, ptr_club->sex);
					ptr_book->xuehao = ptr_club->xuehao;
					strcpy(ptr_book->state, "����");
					strcpy(ptr_club->borrow, ptr_book->book_name);
					flag++;
				}
				if (flag == 0) {
					printf("���޴�ͼ�������δע��Ϊ��Ա!\n\n");
				}
			}

	return head_book;
}
book *back(int bianhao, int xuehao, book *head_book, club *head_club)
{
	book *ptr_book;
	club *ptr_club;
	int flag = 0;

	for (ptr_book = head_book; ptr_book; ptr_book = ptr_book->book_next)
		for (ptr_club = head_club; ptr_club; ptr_club = ptr_club->club_next)
		{
			if ((ptr_book->bianhao == bianhao) && (ptr_club->xuehao == xuehao))
			{
				strcpy(ptr_book->name, "����");
				strcpy(ptr_book->sex, "����");
				ptr_book->xuehao = 0;
				strcpy(ptr_book->state, "����");
				strcpy(ptr_club->borrow, "����");
				flag++;
			}
			if (flag == 0) {
				printf("��������������\n\n");
			}
		}

	return head_book;
}

club *Delete_Club(club *head_club, int xuehao)
{
	club *ptr1_club, *ptr2_club;

	while (head_club != NULL && head_club->xuehao == xuehao) {
		ptr2_club = head_club;
		head_club = head_club->club_next;
		free(ptr2_club);
	}
	if (head_club == NULL)
		return NULL;

	ptr1_club = head_club;
	ptr2_club = head_club->club_next;
	while (ptr2_club != NULL) {
		if (ptr2_club->xuehao == xuehao) {
			ptr1_club->club_next = ptr2_club->club_next;
			free(ptr2_club);
		}
		else
			ptr1_club = ptr2_club;
		ptr2_club = ptr1_club->club_next;
	}

	return head_club;
}
void Print_Book(book *head_book)
{
	book *ptr_b;
	if (head_book == NULL) {
		printf("\n�޼�¼\n\n");
		return;
	}
	printf("\nͼ����\tͼ������\tͼ�鵥��\tͼ������\n\n");
	for (ptr_b = head_book; ptr_b; ptr_b = ptr_b->book_next)
		printf("%d\t\t%s\t\t%.2lf\t\t%s\n\n", ptr_b->bianhao, ptr_b->book_name, ptr_b->price, ptr_b->author);
}
void Print_Club(club *head_club) {
	club *ptr_b;
	if (head_club == NULL) {
		printf("\n�޼�¼\n\n");
		return;
	}
	printf("\n��������\t�����Ա�\t����ѧ��\t�������\n\n");
	for (ptr_b = head_club; ptr_b; ptr_b = ptr_b->club_next)
		printf("%s\t\t%s\t\t%d\t\t%s\n\n", ptr_b->name, ptr_b->sex, ptr_b->xuehao, ptr_b->borrow);
}
book*load_in_book(char *books) {
	FILE* file;
	book*b = (book*)malloc(sizeof(book));
	book*list = NULL;
	file = fopen(books, "rb");
	for (; feof(file) != 1;)
		fread(b, sizeof(book), 1, file);
	list = Insert_Book(list, b);
	fclose(file);
	free(b);
	return list;
}
void load_out_book(char *books, book*list) {
	FILE* file;
	book *a;
	file = fopen(books, "wb");
	for (; list->book_next != NULL; a = list, list = list->book_next) {
		fwrite(list, sizeof(book), 1, file);
	}
	fclose(file);
	return;
}
club* load_in_club(char *clubs) {
	FILE* file;
	club*b = (club*)malloc(sizeof(club));;
	club*list = NULL;
	file = fopen(clubs, "rb");
	for (; feof(file) != 1;)
		fread(b, sizeof(book), 1, file);
	list = Insert_Club(list, b);
	free(b);
	return list;
}
void load_out_club(char *clubs, club* list) {
	FILE* file;
	club*a;
	file = fopen(clubs, "wb");
	for (; list->club_next != NULL; a = list, list = list->club_next) {
		fwrite(list, sizeof(club), 1, file);
		free(a);
	}
	fclose(file);
	return;
}
club *Create_New_Club(club *list) {
	struct club *head_club, *p_club;
	int xuehao;
	char name[20], sex[10];
	int size_club = sizeof(club);
	head_club = list;
	printf("�������Ա����:");
	scanf("%s", name);
	printf("�������Ա�Ա�:");
	scanf("%s", sex);
	printf("�������Աѧ��:");
	scanf("%d", &xuehao);
	printf("/n");
	p_club = (club *)malloc(size_club);
	strcpy(p_club->name, name);
	strcpy(p_club->sex, sex);
	p_club->xuehao = xuehao;
	strcpy(p_club->borrow, "����");
	head_club = Insert_Club(head_club, p_club);
	p_club->club_next = NULL;
	return head_club;
}
book *Create_New_Book(club* list)
{
	book *p_book;
	int bianhao;
	double price;
	char book_name[30], author[20];
	int size_book = sizeof(struct book);
	printf("������ͼ������:");
	scanf("%s", book_name);
	printf("������ͼ����:");
	scanf("%d", &bianhao);
	printf("�����뵥��:");
	scanf("%lf", &price);
	printf("��������������:");
	scanf("%s", author);
	printf("/n");
	p_book = (struct book *)malloc(size_book);
	strcpy(p_book->book_name, book_name);
	p_book->bianhao = bianhao;
	p_book->price = price;
	p_book->xuehao = 0;
	strcpy(p_book->author, author);
	strcpy(p_book->state, "����");
	strcpy(p_book->sex, "����");
	strcpy(p_book->name, "����");
	p_book->book_next = NULL;
	list = Insert_Book(list, p_book);
	return list;
}