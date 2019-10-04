// This was made to show us how input functions work
// Some functions were used in C for lack of knowledge in C++
// Made by Sung-Hyun Cho (Korean)
// Github profile : Hyun-0

#pragma warning(disable : 4996)
#include "InputBuffer.h"
#include <iostream>
#define MYFLUSH while (getchar() != '\n');
#define MENUCNT 5

int menu(void);
InputBuffer *newInputBuffer();
void delInputBuffer(InputBuffer *ibp);
void showScanfChar();
void showScanfSen();
void showGetchar();
void showFgets();

int main(void)
{
	int sel = 0;

	while (1)
	{
		sel = menu();
		switch (sel)
		{
			case 1 :
				showScanfChar();
				break;
			case 2 :
				showScanfSen();
				break;
			case 3 :
				showGetchar();
				break;
			case 4 :
				showFgets();
				break;
			default :
				break;
		}
		system("PAUSE");
		system("cls");
		if (sel == MENUCNT)
		{
			break;
		}
	}

	return 0;
}

int menu(void)
{
	int menu = 0;
	const char *menuList[MENUCNT] = { "scanf(\"%c\", &ch);",
									  "scanf(\"%s\", sen);",
									  "ch = getchar();",
									  "fgets(sen, size, file);",
									  "Exit" };

	printf("-----Watch How Input Function Works-----\n");
	for (int i = 0; i < MENUCNT; ++i)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}
	printf("----------------------------------------\n");
	while ((menu < 1) || (menu > MENUCNT))
	{
		printf(">> Press the number : ");
		scanf("%d", &menu);
		MYFLUSH;
	}
	
	system("cls");

	return menu;
}

InputBuffer *newInputBuffer()
{
	InputBuffer *ibp = new InputBuffer;
	char ch = 0;

	if (ibp == NULL)
	{
		return NULL;
	}
	printf("Input Text\n");
	printf(">> ");
	do
	{
		scanf("%c", &ch);
		if (ibp->addBuffer(ch) == false)
		{
			break;
		}
	} while (ch != '\n');
	return ibp;
}

void delInputBuffer(InputBuffer *ibp)
{
	delete ibp;
	return;
}

void showScanfChar()
{
	InputBuffer *ibp = NULL;
	char ch;

	printf("\n< scanf(\"%%c\", &ch); >-----------------\n");
	ibp = newInputBuffer();
	printf("\n----------------------------------------\n");

	printf("ch : ");
	if ((ch = ibp->readBuffer()) != '\n')
	{
		printf("\'%c\'", ch);
	}

	printf("\nLeft in Input Buffer : ");
	if (ch == '\n')
	{
		printf("\'\\n\' ");
	}
	if (ibp->printBuffer() == false)
	{
		printf("\nThere's an Error, Sorry for a bug\n");
		return;
	}
	printf("\n");

	delInputBuffer(ibp);
	return;
}

void showScanfSen()
{
	InputBuffer *ibp = NULL;
	int senLimit = 0;
	char ch;

	printf("\n< scanf(\"%%s\", sen); >-----------------\n");
	while (senLimit <= 0)
	{
		printf("Type the size of the Sentence : ");
		scanf("%d", &senLimit);
		MYFLUSH;
	}
	--senLimit;
	printf("\n");
	ibp = newInputBuffer();
	printf("\n----------------------------------------\n");

	printf("sen : ");
	for (int i = 0; i < senLimit; ++i)
	{
		if ((ch = ibp->readBuffer()) != '\n')
		{
			printf("\'%c\' ", ch);
		}
		else
		{
			break;
		}
	}
	printf("\'\\0\' ");
	printf("\nLeft in Input Buffer : ");
	if (ch == '\n')
	{
		printf("\'\\n\' ");
	}
	if (ibp->printBuffer() == false)
	{
		printf("\nThere's an Error, Sorry for a bug\n");
		return;
	}
	printf("\n");

	delInputBuffer(ibp);
	return;
}

void showGetchar()
{
	InputBuffer *ibp = NULL;
	char ch = 0;

	printf("\n< ch = getchar() >----------------------\n");
	ibp = newInputBuffer();
	printf("\n----------------------------------------\n");

	printf("ch : ");
	if ((ch = ibp->readBuffer()) != '\n')
	{
		printf("\'%c\'", ch);
	}

	printf("\nLeft in Input Buffer : ");
	if (ch == '\n')
	{
		printf("\'\\n\' ");
	}
	if (ibp->printBuffer() == false)
	{
		printf("\nThere's an Error, Sorry for a bug\n");
		return;
	}
	printf("\n");

	delInputBuffer(ibp);
	return;
}

void showFgets()
{
	InputBuffer *ibp = NULL;
	int senLimit = 0;
	char ch;

	printf("\n< fgets(sen, size, file); >-------------\n");
	while (senLimit <= 0)
	{
		printf("Type the size of the Sentence : ");
		scanf("%d", &senLimit);
		MYFLUSH;
	}
	--senLimit;
	printf("\n");
	ibp = newInputBuffer();
	printf("\n----------------------------------------\n");

	printf("sen : ");
	for (int i = 0; i < senLimit; ++i)
	{
		if ((ch = ibp->readBuffer()) != '\n')
		{
			printf("\'%c\' ", ch);
		}
		else
		{
			printf("\'\\n\' ");
			break;
		}
	}
	printf("\'\\0\' ");
	printf("\nLeft in Input Buffer : ");
	if (ibp->printBuffer() == false)
	{
		printf("\nThere's an Error, Sorry for a bug\n");
		return;
	}
	printf("\n");

	delInputBuffer(ibp);
	return;
}
