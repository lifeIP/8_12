#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <windows.h>

using namespace std;

void process(const char* file, const char* file1);
void diy(const char* strin, char* strout);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	process("file.txt", "file1.txt");
}

void process(const char* file, const char* file1)
{
	FILE* f = fopen(file, "rt");
	if (f == NULL)
	{
		cout << "File is not open  " << endl;
		return;
	}
	ofstream fo;
	fo.open(file1);
	if (!fo.is_open())
	{
		cout << "File is not open " << endl;
		fclose(f);
		return;
	}
	while (!feof(f))
	{
		char buff[2500];
		buff[0] = 0;
		fgets(buff, 2500, f);
		if (strlen(buff) > 0)
		{
			char buff2[2500];
			diy(buff, buff2);
			fo << buff2;
		}
	}
	fclose(f);
	fo.close();
}



void diy(const char* str_l, char* resault_l) {
	memset(resault_l, 0, sizeof(char) * 2500);

	char str[2500] = {};
	for (short i = 0; i < strlen(str_l); i++) {
		if (str_l[i] == '\n') {
			strcat(str, " * ");
		}
		else {
			strncat(str, i + str_l, 1);
		}
	}

	int i = 0;
	char result[2500] = {};
	int slice = 0;
	char second_processing[50] = {};
	while (true) {
		memset(second_processing, 0, sizeof(char) * 50);
		slice = strcspn(i + str, " ");
		int adr = slice + i;
		if (i == adr)break;
		strncpy(second_processing, i + str, slice);

		if (second_processing[0] == 'д' && second_processing[1] == 'а' && second_processing[2] == 0) {
			strcat(result, "таки да");
			strcat(result, " ");
		}
		else
		{
			strncat(result, i + str, slice);
			strcat(result, " ");
		}
		i = slice + i + 1;
	}
	for (int i = 0, j = strlen(result); i < strlen(result); i++, j--) {
		if (result[i] == '*') {
			resault_l[j - 1] = '\n';
		}
		else {
			resault_l[j - 1] = result[i];
		}
	}
}