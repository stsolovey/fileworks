//#include "pch.h"
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void clear(void) {
	while (getchar() != '\n'); // очистка буфера консольного ввода
}
void fnaming(char *name) {
	scanf("%127s", name); // ввод имени файла
	clear();
}

// открытие файла
FILE * fopening(char *fname) {
	FILE *fptr = fopen(fname, "rb+");
	if (fptr == NULL) {
		puts("Cannot read the file. Trying to create it..");
		fptr = fopen(fname, "wb+"); // создаём его
		if (fptr == NULL) { // если открыть или создать файл не удалось
			puts("Still cannot create and read file");
			return nullptr; // прерываем выполнение функции, возвращаемся
		}
		else {
			puts("File was created successfully.");
		}
	};
	return fptr; // возвращаем файловый указатель
}

// пишем в файл из массива
void writeToFile(FILE *fp, int *arr, int n) {
	fwrite(arr, sizeof(int), n, fp); // пишем
	if (fwrite != 0) { // проверяем записалось ли
		puts("Contents to file written successfully !");
	}else {
		puts("Error writing file !");
		return;
	}	
}

// читаем из файла в массив известное количество элементов
void readFromFile(FILE *fp, int *arr, int n) {
	if (fread(arr, sizeof(int), n, fp) == n) {
		puts("Reading file successfuly !");
	}
	else {
		puts("Error reading file");
	}
}

// печатаем в консоль массив
void printingArr(int *arr, int n) {
	printf("\nPrinting array, %d elements:\n", n);
	for (int i = 0; i < n; ++i) {
		printf("Array[%d] = %d\n", i, arr[i]);
	}
	puts("");
}

// считаем количество элементов в файле
void countNumberOfElements(FILE *fp, int &noe) {
	int soe = sizeof(int); // размер одного элемента массива
	fseek(fp, 0L, SEEK_END);
	int sof = ftell(fp); // размер всего файла
	printf("\nftell(fp) %% sizeof(int) %d\n", ftell(fp) % sizeof(int));
	if ((ftell(fp) % sizeof(int))==0) { // если sof%soe==0 то вычисляем noe
		noe = ftell(fp) / sizeof(int);
	}
	else { // иначе не вычисляем noe
		printf("\nSize of file %d bytes\nCan't find number of elements in file\n", ftell(fp));
		return;
	}
	printf("\nSize of file %d bytes\nNumber of elements in file %d\n", ftell(fp), noe);
}

int main() {
	FILE *fp; // указатель на файл
	char fname[128]; // строка имени файла
	fnaming(fname); // вводим имя файла
	int noe; // неизвестное заранее количество элементов в файле
	int A[] = { 2, 3, 5, 8 }; // массив из которого пишем в файл
	int B[4]; // массив в который читаем из файла

	// пишем в файл из массива А
	fp = fopening(fname);
	writeToFile(fp, A, 4);
	fclose(fp);

	// считаем количество элементов в файле, зная тип данных
	fp = fopening(fname);
	countNumberOfElements(fp, noe);
	fclose(fp);

	// читаем из файла в массив B
	fp = fopening(fname);
	readFromFile(fp, B, noe);
	fclose(fp);


	// печатаем оба массива
	printingArr(A, 4);
	printingArr(B, 4);

	return 0;
}
