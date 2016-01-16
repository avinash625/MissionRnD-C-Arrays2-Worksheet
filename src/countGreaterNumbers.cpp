/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int to_num(char *date, int start, int length)
{
	int num = 0, k=10,i = 1;
	for (i = 0; i<length; i++,start++)
	{
		num = num *k+(date[start] - '0');
	}
	return num;
}
int check_date(char *date, char *stat_date)
{
	if (to_num(date, 6, 4) <= to_num(stat_date, 6, 4))
	{
		if (to_num(date, 4, 2) <= to_num(stat_date, 4, 2))
		{
			if (to_num(date, 0, 2) < to_num(stat_date, 0, 2))
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, count = 0;
	if (Arr == NULL)
		return NULL;
	for (i = 0; i < len; i++)
	{
		if (check_date(date, Arr[i].date))
			return len - i ;
	}
	return count;
}
