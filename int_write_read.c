#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void naming(char *fn) {
	printf("enter filename: ");
	scanf("%s", fn); // вводим имя файла
}
void filewrite(int input) {
	char filename[128];
	naming(filename);
	FILE *fp = fopen(filename, "rb+");
	if (fp == NULL) { // если файл ещё не существует то..
		fp = fopen(filename, "wb+");
		if (fp == NULL) { // если открыть или создать файл не удалось
			return; // возвращаем 0
		}
	}
	fwrite(&input, sizeof(int), 1, fp); // пишем
	if (fwrite != 0)
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");
	fclose(fp); // закрываем файл
}

void fileread() {
	char filename[128];
	naming(filename);
	FILE *fp = fopen(filename, "rb+");
	int input=0;
	if (fp == NULL) { // если файл ещё не существует то..
		printf("File doesn't exist\n");
		return;
	}
	fread(&input, sizeof(int), 1, fp);
	fclose(fp);
	printf("read from file: %d", input);
}

int main(){
	int write = 0;
	int read = 0;
	printf("enter number: ");
	scanf("%d", &write);
	filewrite(write);
	fileread();
	return 0;
}
