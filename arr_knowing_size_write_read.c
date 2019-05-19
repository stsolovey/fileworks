#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// выводим массив в консоль
void printArr(int *Arr, int n) {
	for (int i = 0; i < n; ++i) {
		printf("Arr[%d] = %d\n", i, Arr[i]);
	}
}

// указываем имя файла
void naming(char *fn) {
	printf("enter filename: ");
	scanf("%s", fn); // вводим имя файла
}
void filewrite(int *input, int n) {
	char filename[128]; // имя файла
	naming(filename); // указываем имя
	FILE *fp = fopen(filename, "rb+");
	if (fp == NULL) { // если файл ещё не существует то..
		fp = fopen(filename, "wb+"); // создаём его
		if (fp == NULL) { // если открыть или создать файл не удалось
			return; // прерываем выполнение функции, возвращаемся
		}
	}
	fwrite(input, sizeof(int), n, fp); // пишем
	if (fwrite != 0) // проверяем
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");
	fclose(fp); // закрываем файл
}

void fileread(int n) {
	char filename[128]; // имя файла
	naming(filename); // указываем имя
	FILE *fp = fopen(filename, "rb+");
	// выделяем память для массива куда будем читать файл (файл известного размера)
	int *input = (int*)malloc(sizeof(int) * n);
	if (fp == NULL) { // если файл ещё не существует то..
		printf("File doesn't exist\n");
		return; // прерываем выполнение функции, возвращаемся
	}
	if (fread(input, sizeof(int), n, fp) != n) { // читаем, проверяем
		if (feof(fp))
			printf("Premature end of file.");
		else
			printf("File read error.");
	}
	fclose(fp); // закрываем файл
	printArr(input, n); // отправляем на вывод в консоль
}

int main(){
	int n, number; // кол-во элементов и элементы
	printf("enter number of elements: ");
	scanf("%d", &n); // вводим кол-во элементов массива
	 // выделяем память для данного кол-ва элементов
	int *Arr = (int*)malloc( sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		printf("Arr[%d] = ", i);
		scanf("%d", &number); // вводим значения элементов
		Arr[i] = number;
	}
	filewrite(Arr, n);  // пишем в файл
	fileread(n); // читаем из файла
	return 0;
}
