
 #include "libftprintf.h"
#include <stdio.h>



// char *ft_itoh(long n, int lower_upper, char *prev)
// {
// 	char *set;
// 	char *str;

// 	str = malloc(2);
// 	if (!str)
// 		return (NULL);
// 	str[1]= '\0';
// 	if (lower_upper)
// 		set = "0123456789ABCDEF";
// 	else
// 		set = "0123456789abcdef";
// 	if (n < 16 && n >= 0)
// 	{
// 		str[0]= set[n];
// 		return (str);
// 	}
// 	if (n < 0)
// 	{
// 		str[0]= '-';
// 		return (ft_strjoin(str, ft_itoh((-1 * n), lower_upper, NULL)));
// 	}
// 	if (n >= 16)
// 	{
// 		str[0]= set[n % 16];
// 		return (ft_strjoin(str,ft_itoh(n / 16, lower_upper, NULL)));
// 	}
//}

// int main(int argc, char** argv)
int main(void)
{
	int d;
	int * dd = &d;

	printf(" %X ", dd);
	ft_printf(" %p ", dd);
	return 0;
}