// va_list   → создать переменную для обхода аргументов
// va_start  → поставить её в начало списка
// va_arg    → взять следующий аргумент
// va_end    → закончить работу
//
//        va_list args
//             │
//             ▼
// va_start(args, format)
//             │
//             ▼
//     va_arg(args, type)
//             │
//             ▼
//     va_arg(args, type)
//             │
//             ▼
//           ...
//             │
//             ▼
//        va_end(args)
//
// va_list
//     переменная, которая хранит состояние обхода аргументов
//
// va_start(args, format)
//     начать читать аргументы после format
//
// va_arg(args, int)
//     взять следующий аргумент как int
//     и перейти к следующему
//
// va_arg(args, char *)
//     взять следующий аргумент как char *
//     и перейти к следующему
//
// va_end(args)
//     закончить работу с аргументами

#include <stdarg.h>
#include <stdio.h>

void	print_numbers(int count, ...)
{
	va_list	args;
	int		i;
	int		value;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		value = va_arg(args, int);
		printf("%d\n", value);
		i++;
	}
	va_end(args);
}

int	main(void)
{
	print_numbers(3, 10, 20, 30);
	return(0);
}