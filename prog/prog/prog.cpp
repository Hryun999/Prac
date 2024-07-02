#pragmawarning(disable : 4996)
#include"menu.h"
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<Windows.h>


void Merge(int* Ap, intp, intq, intr)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L; int* R;
	L = newint[n1 + 1];
	R = newint[n2 + 1];

	for (int i = 1; i <= n1; i++)
	{
		L[i - 1] = Ap[p + i - 1];
	}

	for (int j = 1; j <= n2; j++)
	{
		R[j - 1] = Ap[q + j];
	}

	for (int i = 0, j = 0, k = p; k <= r; k++) {
		if (i < n1 && j < n2) {
			if (L[i] <= R[j]) {
				Ap[k] = L[i];
				i++;
			}
			else {
				Ap[k] = R[j];
				j++;
			}
		}
		elseif(i < n1) {
			Ap[k] = L[i];
			i++;
		}
		else {
			Ap[k] = R[j];
			j++;
		}
	}

}

void Merge_Sort(int* Ap, intp, intr)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		Merge_Sort(Ap, p, q);
		Merge_Sort(Ap, q + 1, r);
		Merge(Ap, p, q, r);
	}
}


void save1(FILE* F1, char* F1name, int* A, intsize)
{
	F1 = fopen(F1name, "w");
	if (F1 != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(F1, "%d\n", A[i]);
		}
	}
	else
	{
		printf("Ошибка записи в файл");
	}
	fclose(F1);
}

void save2(FILE* F2, char* F2name, int* A, intsize)
{
	F2 = fopen(F2name, "w");
	if (F2 != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(F2, "%d\n", A[i]);
		}
	}
	else
	{
		printf("Ошибка записи в файл");
	}
	fclose(F2);
}

void random(void)
{
	int size;
	FILE* F1, * F2;
	char F1name[20];
	char F2name[20];
	printf("Введите файл, в котором будут находиться исходные числа: ");
	gets_s(F1name);
	F1 = fopen(F1name, "w");
	printf("Введите файл, в котором будут находиться отсортированные числа: ");
	gets_s(F2name);
	F2 = fopen(F2name, "w");
	printf("Введите размер массива (больше 1): ");
	do
	{
		scanf_s("%d", &size);
		if (size < 2)
		{
			printf("Неверно ввёден размер массива\n");
			printf("Введите размер массива (больше 1): ");
		}
	} while (size < 2);
	int* A = newint[size];
	for (int i = 0; i < size; i++) //Заполнение массива А случайными числами
	{
		A[i] = (rand() % 20001) - 10000;
	}
	printf("Исходные числа в файле \"%s\" \n", F1name);
	save1(F1, F1name, A, size);
	time_t start = clock();
	Merge_Sort(A, 0, (size - 1));
	time_t stop = clock();
	int time = (stop - start) / 1000;
	printf("Время сортировки: %i мс\n", time);
	save2(F2, F2name, A, size);
	printf("Отсортированные числа в файле \"%s\" \n", F2name);
}

void sort(void)
{
	FILE* F3, * F4, * F5, * F6;
	char F3name[20], F4name[20];
	printf("Введите название файла: ");
	gets_s(F3name);
	F3 = fopen(F3name, "r");
	if (F3 == NULL)
	{
		printf("Невозможно открыть файл \"%s\"\n", &F3name);
	}
	else
	{
		int size = 0;
		int curDigit = 0;
		while (fscanf(F3, "%d", &curDigit) != EOF) {
			size++;
		}
		fseek(F3, 0, SEEK_SET);
		int* A = newint[size];
		for (int i = 0; i < size; i++)
		{
			fscanf(F3, "%d", &A[i]);
		}
		fclose(F3);
		time_t start = clock();
		Merge_Sort(A, 0, size - 1);
		time_t stop = clock();
		int time = (stop - start) / 1000;
		printf("Время сортировки: %i мс\n", time);
		printf("Напишите, в какой файл сохранить отсортированные файлы (текстовый файл!): ");
		gets_s(F4name);
		F4 = fopen(F4name, "w");
		if (F4 != NULL)
		{
			for (int i = 0; i < size; i++)
			{
				fprintf(F4, "%d\n", A[i]);
			}
		}
		else
		{
			printf("Ошибка записи в файл");
		}
		fclose(F4);
	}
}
