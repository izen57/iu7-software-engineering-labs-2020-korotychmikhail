#include <stdio.h>
#include <string.h>
#include "bin_to_hex.h"
#define SUCCESS 0
#define INCORRECT_INPUT 1
#define MAX_LENGHT_OF_BIN 128
/**
 * Функция, обнуляющая вспомогательные массивы hex и bin
 * \param bin- массив с цифрами двоичного числа
 * \param hex - массив с цифрами шестнадцатеричного числа 
*/
void zeroing(char *bin, char *hex)
{
	for (int i = 0; i <= MAX_LENGHT_OF_BIN + 3; i++)
		bin[i] = '\0';
	for (int i = 0; i <= MAX_LENGHT_OF_BIN / 4 + 1; i++)
		hex[i] = '\0';
}
/**
 * Функция, проверяющая вспомогательный массивы hex и bin
 * \warning Если массив больше 128 символов или в нём есть какие-либо символы кроме десятичных цифр, то функция завершается с ошибкой
 * \param[in] file - входной файл
 * \param[in] bin - массив цифр двоичного числа
 * \return Код ошибки
*/
int check_bin(FILE *file, char *bin)
{
	if (!strlen(bin))
		return INCORRECT_INPUT;
	if (strlen(bin) > MAX_LENGHT_OF_BIN + 1)
	{
		fprintf(file, "Цифр в числе больше шестнадцати.\n");
		return INCORRECT_INPUT;
	}
	for (int i = 0; i < strlen(bin); i++)
		if (bin[i] == '\n')
			bin[i] = '\0';
	for (int i = 0; i < strlen(bin); i++)
		if (bin[i] < '0' || bin[i] > '9')
		{
			fprintf(file,"Встречены посторонние символы, или чисел в строке больше одной.\n");
			return INCORRECT_INPUT;
		}
	return SUCCESS;
}
/**
 * Главная функция
 * \param[in] argc - количество аргументов командной строки
 * \param[in] **argv - массив строк-аргументов командной строки
 * \return Код ошибки
*/
int main(int argc, char **argv)
{
	if (argc == 3 && argv[1] && argv[2])
	{
		char bin[MAX_LENGHT_OF_BIN + 2], hex[MAX_LENGHT_OF_BIN / 4 + 1];
		FILE *input_file = fopen(argv[1], "r");
		if (!input_file)
		{
			printf("Файл не существует.");
			return INCORRECT_INPUT;
		}
		FILE *output_file = fopen(argv[2], "a");
		while (!feof(input_file))
		{
			zeroing(bin, hex);
			if (!fgets(bin, MAX_LENGHT_OF_BIN + 3, input_file))
				return INCORRECT_INPUT;
			if (check_bin(output_file, bin))
				continue;
			if (bin_to_hex(bin, hex))
			{
				fprintf(output_file,"Встречены посторонние символы, или чисел в строке больше одной.\n");
				continue;
			}
			fprintf(output_file, "%s\n", hex);
		}
		fclose(input_file);
		fclose(output_file);
		return SUCCESS;
	}
	else
	{
		printf("Неизвестные команды строки, или несуществующие файлы.");
		return INCORRECT_INPUT;
	}
}