
#include "pch.h"
#include <stdio.h>
#include <clocale>
#include <stdlib.h>
#include <time.h> 

int creation1(char* chek);
int creation2(char* chek);
int printMenu(char* chek);
int fill(char* chek);
void manually(int** arr, char* chek, int n, int m);
void printArr(int** arr, int n, int m);
void processing(int** arr, int n, int m);

int main()
{
	setlocale(LC_ALL, "RUS");

	int n = 0;
	int m = 0;
	char chek = '\0';

	srand(time(NULL));

	n = creation1(&chek);
	m = creation2(&chek);
	
	int **arr = NULL;

	int menu = 0;

	bool sample = false;
	bool sample_1 = false;
	
	do
	{
		menu = printMenu(&chek);

		switch (menu)
		{
		case 1:
		{
			printf("\n1. Ввести вручную\n");
			printf("2. Ввести автоматически\n\n");
			printf("Ответ: ");

			arr = new int *[n]();

			for (int i = 0; i < n; i++)
			{
				arr[i] = new int[m];
			}

			int f = 0;

			f = fill(&chek);

			switch (f)
			{
			case 1:
			{
				manually(arr, &chek, n, m);
			}

			printf("\nМассив успешно заполнен");

			sample = true;
			sample_1 = true;

			break;

			case 2:
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						arr[i][j] = rand();
					}
				}
			}

			printf("\nМассив успешно заполнен\n");

			sample = true;
			sample_1 = true;

			break;
			}

		}
		break;

		case 2:
		{
			if (sample == true)
			{
				processing(arr, n, m);
			}

			else
			{
				printf("\nПеред обработкой, пожалуйста, создайте массив.\n");
				printf("Для этого выберите первый пункт меню.\n\n");
			}
			printf("Для перехода в главное меню нажмите клавишу 'Enter'");
			getchar();
		}
		break;

		case 3:
		{
			if (sample_1 == true)
			{
				printArr(arr, n, m);
			}

			else
			{
				printf("\nМассив не создан, для его создания выберите пункт 1 в главном меню");
			}
			printf("\n\nДля перехода в главное меню нажмите клавишу 'Enter'");
			getchar();
		}
		break;

		case 4:
		{
			n = creation1(&chek);
			m = creation2(&chek);

			sample = false;
			sample_1 = false;

		}
		}
	} while (menu != 5);

	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
	
	return 0;
}

int creation1(char* chek)
{
	int line = 0;
	
	printf("Введите количество строк в матрице: ");

	while (scanf_s("%d%c", &line, &*chek, 1) != 2 || *chek != '\n' || line <= 0)
	{
		while (getchar() != '\n');
		printf("Ошибка! Введите положительное число: \n ");
	}

	return line;
}

int creation2(char* chek)
{
	int colomn = 0;

	printf("Введите количество столбцов в матрице: ");

	while (scanf_s("%d%c", &colomn, &*chek, 1) != 2 || *chek != '\n' || colomn <= 0)
	{
		while (getchar() != '\n');
		printf("Ошибка! Введите положительное число: \n ");
	}

	return colomn;
}


int printMenu(char* chek)
{
	printf("\nВыберите пункт меню:\n");
	printf("1. Ввод данных\n");
	printf("2. Обработка массива\n");
	printf("3. Вывод массива на экран\n");
	printf("4. Изменить размерность маcсива\n");
	printf("5. Выход\n\n");
	printf("Ваш ответ: ");

	int choice = 0;

	while (scanf_s("%d%c", &choice, &*chek, 1) != 2 || *chek != '\n' || choice > 5 || choice < 1)
	{
		while (getchar() != '\n');
		printf("Ошибка! Выберите пункт меню:\n\n");
	}

	return choice;
}

int fill(char* chek)
{
	int fill = 0;

	while (scanf_s("%d%c", &fill, &*chek, 1) != 2 || *chek != '\n' || fill < 1 || fill > 2)
	{
		while (getchar() != '\n');
		printf("\nОшибка! Выберите пункт 1 или 2: ");
	}

	return fill;
}

void manually(int** arr, char* chek, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("\nВведите элемент [%d][%d]: ", i + 1, j + 1);
			while (scanf_s("%d%c", &arr[i][j], &*chek, 1) != 2 || *chek != '\n')
			{
				while (getchar() != '\n');
				printf("Ошибка! Введите число: \n");
			}
		}
	}
}


void printArr(int** arr, int n, int m)
{
	printf("\nСозданный массив имеет вид: \n\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void processing(int** arr, int n, int m)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n - k - 1; i++)
		{
			if (arr[i][0] > arr[i + 1][0])
			{
				int* proc = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = proc;
			}
		}
	}
	printf("\nОбработка массива завершена успешно\n\n");
}
