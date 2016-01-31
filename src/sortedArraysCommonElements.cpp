/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int number(char *date, int start, int length)
{
	int num = 0, k = 10, i = 1;
	for (i = 0; i<length; i++, start++)
	{
		num = num *k + (date[start] - '0');
	}
	return num;
}
int same_date(char *date, char *stat_date)
{
	if (number(date, 6, 4) == number(stat_date, 6, 4))
	{
		if (number(date, 4, 2) == number(stat_date, 4, 2))
		{
			if (number(date, 0, 2) == number(stat_date, 0, 2))
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
void copy(struct transaction *head, int count, struct transaction *A, int A_index)
{
	int i;
	for (i = 0; A[A_index].date[i]; i++)
		head[count].date[i] = A[A_index].date[i];
	head[count].date[i] = '\0';
	for (i = 0; A[A_index].description[i]; i++)
		head[count].description[i] = A[A_index].description[i];
	head[count].description[i] = '\0';
	
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j, count = 0, len = ALen+BLen;
	struct transaction head[100];
	if (A == NULL || B == NULL)
		return NULL;
	else
	{
		for (i = 0; i < ALen;i++)
			for (j = 0; j < BLen; j++)
			{
				if (same_date(A[i].date, B[j].date))
				{
					head[count] = A[i];
					count++;
					break;
				}
			}
	}
	return head;
}