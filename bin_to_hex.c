#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "bin_to_hex.h"
/**
 * Функция для перевод числа из двоичной системы счисления в шестнадцатеричную
 * \param[in] bin - массив цифр двоичного числа
 * \param[out] hex - массив цифр шестнадцатеричного числа
 * \warning Если массив содержит какие-либо символы кроме  цифр 0 и 1, то функция завершается с ошибкой
 * Перевод осуществляется с помощью формулы:
 * \f$(a_{n-1}a_{n-2}\dots a_{1}a_{0})_{2}=\sum _{k=0}^{n-1}a_{k}2^{k}\f$
*/
int bin_to_hex(char *bin, char *hex)
{
	for (int i = 0; i < strlen(bin); i++)
		if (bin[i] != '0' && bin[i] != '1')
			return EXIT_FAILURE;
	int dec = 0;
	for (int i = 0; i < strlen(bin); i++)
		dec += (bin[i] - '0') * pow(2, strlen(bin) - i - 1);
	itoa(dec, hex, 16);
	return EXIT_SUCCESS;
}