//Программу не успел доделать, и она перводит только шестнадцатезначные двоичные числа
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define SUCCESS 0
#define INCORRECT_INPUT 1
#define MAX_LENGHT_OF_BIN 16
void zeroing(char *bin, char *hex)
{
	for (int i = 0; i <= MAX_LENGHT_OF_BIN + 2; i++)
		bin[i] = '\0';
	for (int i = 0; i <= MAX_LENGHT_OF_BIN / 4 + 2; i++)
		hex[i] = '\0';
}
int check_bin(FILE *file, char *bin)
{
	if (strlen(bin) > MAX_LENGHT_OF_BIN)
	{
		fprintf(file, "Цифр в числе больше шестнадцати.\n");
		return INCORRECT_INPUT;
	}
	for (int i = 0; i < strlen(bin); i++)
	{
		if ((bin[i] >= ' ' && bin[i] <= '/') || (bin[i] >= ':' && bin[i] <= '@') || (bin[i] >= '[' && bin[i] <= '`') || bin[i] >= '{')
		{
			fprintf(file,"Встречены посторонние символы, или чисел в строке больше одной.\n");
			return INCORRECT_INPUT;
		}
	}
	return SUCCESS;
}
int bin_to_hex(char *bin, char *hex)
{
	int j = 0;
	for (char *ptr = bin; *ptr != '\0'; ptr += 4)
	{
		if (!memcmp(ptr,"0000", 4 * sizeof(char)))
			hex[j] = '0';
		else if (!memcmp(ptr, "0001", 4 * sizeof(char)))
			hex[j] = '1';
		else if (!memcmp(ptr, "0010", 4 * sizeof(char)))
			hex[j] = '2';
		else if (!memcmp(ptr, "0011", 4 * sizeof(char)))
			hex[j] = '3';
		else if (!memcmp(ptr, "0100", 4 * sizeof(char)))
			hex[j] = '4';
		else if (!memcmp(ptr, "0101", 4 * sizeof(char)))
			hex[j] = '5';
		else if (!memcmp(ptr, "0110", 4 * sizeof(char)))
			hex[j] = '6';
		else if (!memcmp(ptr, "0111", 4 * sizeof(char)))
			hex[j] = '7';
		else if (!memcmp(ptr, "1000", 4 * sizeof(char)))
			hex[j] = '8';
		else if (!memcmp(ptr, "1001", 4 * sizeof(char)))
			hex[j] = '9';
		else if (!memcmp(ptr, "1010", 4 * sizeof(char)))
			hex[j] = 'A';
		else if (!memcmp(ptr, "1011", 4 * sizeof(char)))
			hex[j] = 'B';
		else if (!memcmp(ptr, "1100", 4 * sizeof(char)))
			hex[j] = 'C';
		else if (!memcmp(ptr, "1101", 4 * sizeof(char)))
			hex[j] = 'D';
		else if (!memcmp(ptr, "1110", 4 * sizeof(char)))
			hex[j] = 'E';
		else if (!memcmp(ptr, "1111", 4 * sizeof(char)))
			hex[j] = 'F';
		j++;
	}
	/*char temp;
	for (int i = 0; i < MAX_LENGHT_OF_BIN / 4; i++)
	{
		temp = hex[i];
		hex[i] = hex[MAX_LENGHT_OF_BIN / 2 - i - 1];
		hex[MAX_LENGHT_OF_BIN / 2 - i - 1] = temp;
	}*/
	return SUCCESS;
}
int main(int argc, char **argv)
{
	/*if (argc == 3 && argv[1] && argv[2])
	{*/
		char bin[MAX_LENGHT_OF_BIN + 2], hex[MAX_LENGHT_OF_BIN / 4 + 2];
		FILE *input_file = fopen(/*argv[1]*/"D:\\in.txt", "r");
		if (!input_file)
			return INCORRECT_INPUT;
		FILE *output_file = fopen(/*argv[2]*/"D:\\out.txt", "a");
		while (!feof(input_file))
		{
			zeroing(bin, hex);
			if (!fgets(bin, MAX_LENGHT_OF_BIN + 2, input_file))
				return INCORRECT_INPUT;
			if (check_bin(input_file, bin))
				return INCORRECT_INPUT;
			if (bin_to_hex(bin, hex))
				return INCORRECT_INPUT;
			fprintf(output_file, "%s\n", hex);
		}
		fclose(input_file);
		fclose(output_file);
	/*}
	else
	{
		printf("Неизвестные команды строки, или несуществующие файлы.");
		return INCORRECT_INPUT;
	}*/
}