#include <stdio.h>

void Date()
{

	int month, day, year, flag, count;
	count = 0;
	flag = 1;
	while (flag == 1)
	{
		if (count == 1)
		{
			printf("Please enter a valid date;\n");
		}

		printf("\nEnter a date month/date/year \n");
		scanf_s("%i/%i/%i", &month, &day, &year);
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 0) && (day <= 31))
		{
			flag = 0;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 0) && day <= 30)
		{
			flag = 0;
		}

		if (month == 2)
		{
			if ((year % 4 != 0) && (day > 0) && (day <= 28))
			{
				flag = 0;
			}
			else if (year % 4 == 0)
			{
				if ((year % 100 == 0) && (year % 400 != 0) && (day > 0) && (day <= 28))
				{
					flag = 0;
				}
				else if ((year % 400 == 0) && (day > 0) && (day <= 29))
				{
					flag = 0;
				}
				else if ((year % 100 != 0) && (day > 0) && (day <= 29))
				{
					flag = 0;
				}
			}
		}

		count = 1;




	}
	int c, anchor, m, doom, upto, i, week;
	c = year / 100;
	anchor = (5 * (c % 4) % 7) + 2;
	m = year % 100;
	doom = ((((m + m / 4) % 7) + anchor) % 7);
	upto = 0;
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

	if (year % 4 != 0)
	{
		for (i = 0; i<(month - 1); i++)
		{
			upto = upto + a[i];
		}
		week = upto + day - 94;
	}
	else if ((year % 100 == 0) && (year % 400 != 0))
	{
		for (i = 0; i<(month - 1); i++)
		{
			upto = upto + a[i];
		}
		week = upto + day - 94;
	}
	else
	{
		for (i = 0; i<(month - 1); i++)
		{
			upto = upto + b[i];
		}
		week = upto + day - 95;
	}
	if (week < 0)
	{
		while (week < 0)
			week += 7;
	}
	else
		week = week % 7;

	week = ((week + doom) % 7);
	switch (week)
	{
	case 0: printf("The day is Sunday\n");
		break;
	case 1: printf("The day is Monday\n");
		break;
	case 2: printf("The day is Tuesday\n");
		break;
	case 3: printf("The day is Wednesday\n");
		break;
	case 4: printf("The day is Thursday\n");
		break;
	case 5: printf("The day is Friday\n");
		break;
	case 6: printf("The day is Saturday\n");
		break;
	default: printf("What in the world did you enter?\n");

	}

}
