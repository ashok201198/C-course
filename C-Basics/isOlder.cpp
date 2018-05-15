/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int check(char *dob, int i, int limit)
{
	int num = 0, temp, power = limit - i, k;
	while (i <= limit)
	{
		temp = dob[i] - '0';
		for (k = power; k >= 1; k--)
		{
			temp = temp * 10;
		}
		num = num + temp;
		power--;
		i++;
	}
	return num;
}

int invalid_check(char *dob)
{
	int i = 0;
	char ch;
	while (1)
	{
		if (i == 10)
		{
			ch = 'v';
			break;
		}
		if (dob[i] >= 48 && dob[i] <= 57)
		{
			if (i == 2 || i == 5)
			{
				if (dob[i] != '-')
				{
					ch = 'i';
					break;
				}
				else
				{
					i++;
				}
			}
			else
			{
				i++;
			}

		}
		else
		{
			if (i == 2 || i == 5)
				i++;
			else
			{
				ch = 'i';
				break;
			}
		}
	}
	if (ch == 'i')
		return -1;
	if (ch == 'v')
		return 1;

}


int isOlder(char *dob1, char *dob2)
{
	int year1, year2, month1, month2, date1, date2;
	int invalid1 = invalid_check(dob1);
	int invalid2 = invalid_check(dob2);
	if (invalid1 == -1 || invalid2 == -1)
		return -1;
	else
	{
		year1 = check(dob1, 6, 9);
		year2 = check(dob2, 6, 9);
		month1 = check(dob1, 3, 4);
		month2 = check(dob2, 3, 4);
		date1 = check(dob1, 0, 1);
		date2 = check(dob2, 0, 1);
		if (date1 > 31 || date2 > 31)
			return -1;
		if (month1 > 12 || month2 > 12 || month1 == 0 || month2 == 0)
			return -1;
		if (year1 == 0 || year2 == 0)
			return -1;
		if ((date1 == 31) && (month1 == 2 || month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11))
			return -1;
		if ((date2 == 31) && (month2 == 2 || month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11))
			return -1;
		if ((date1 == 29) && (month1 == 2) && (year1 % 4 != 0))
			return -1;
		if ((date2 == 29) && (month2 == 2) && (year2 % 4 != 0))
			return -1;
		if (year1 < year2)
			return 1;
		else if (year1 > year2)
			return 2;
		else
		{
			if (month1 < month2)
				return 1;
			else if (month1 > month2)
				return 2;
			else
			{
				if (date1 < date2)
					return 1;
				else if (date1 > date2)
					return 2;
				else
					return 0;
			}

		}
	}
}