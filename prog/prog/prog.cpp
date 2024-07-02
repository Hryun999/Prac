
void print(int* A, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void save1(FILE* F1, char* F1name, int* A, int size)
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

void save2(FILE* F2, char* F2name, int* A, int size)
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
	int* A = new int[size];
	for (int i = 0; i < size; i++) //Заполнение массива А случайными числами
	{
		A[i] = (rand() % 20001) - 10000;
	}
	printf("Исходные числа в файле \"%s\" \n", F1name);
	save1(F1, F1name, A, size);
	time_t start = clock();
	Merge_Sort(A, 0, (size - 1));
	time_t stop = clock();
	double time = (stop - start) / 1000.0;
	printf("Время сортировки: %f секунд\n", time);
	save2(F2, F2name, A, size);
	printf("Отсортированные числа в файле \"%s\" \n", F2name);
}

