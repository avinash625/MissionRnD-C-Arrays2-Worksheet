/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int to_No(char *date, int start, int length)
{
	int num = 0, k = 10, i = 1;
	for (i = 0; i<length; i++, start++)
	{
		num = num *k + (date[start] - '0');
	}
	return num;
}
int check_dates(char *date, char *stat_date)
{
	int year_a, year_b, month_a, month_b, day_a, day_b;
	year_a = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	year_b = (stat_date[6] - '0') * 1000 + (stat_date[7] - '0') * 100 + (stat_date[8] - '0') * 10 + (stat_date[9] - '0');
	month_a = (date[3] - '0') * 10 + (date[4] - '0');
	month_b = (stat_date[3] - '0') * 10 + (stat_date[4] - '0');
	day_a = (date[0] - '0') * 10 + (date[1] - '0');
	day_b = (date[0] - '0') * 10 + (date[1] - '0');
	if (year_a == year_b)
	{
		if (month_a == month_b)
		{
			if (day_a == day_b)
				return 1;
			else if (day_a > day_b)
				return 0;
		}
		else if (month_a > month_b)
		{
			return 0;
		}

	}
	else if (year_a > year_b)
	{
		return 0;
	}
	else
		return 1;
}
void copy(char *destination, char *source)
{
	int i;
	for (i = 0; source[i]; i++)
		destination[i] = source[i];
	destination[i] = '\0';
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int length = ALen + BLen;
	struct transaction *new_head = NULL;
	int i, count = 0, j;
	if (A == NULL|| ALen <= 0)
		return NULL;
	else if (B == NULL|BLen <=0)
		return NULL;
	else
	{
		new_head = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
		for (i = 0, j = 0; i < ALen && j < BLen;)
		{
			if (check_dates(A[i].date, B[j].date))
			{
				new_head[count] = A[i];
				i++;
			}
			else
			{
				new_head[count] = B[j];
				j++;
			}
			count++;
		}
		for (; i < ALen; i++)
		{
			new_head[count] = A[i];
			count++;
		}
		for (; j < BLen; j++)
		{
			new_head[count] = B[j];
			count++;
		}
		return new_head;
	}
}