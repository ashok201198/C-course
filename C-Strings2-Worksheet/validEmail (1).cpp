/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>

int checkname(char * name,char * email);
int checkemailbefore(char * email);
int isValidEmail(char *email)
{
	int i = 0, l = 0,j=0,cn,ceb,cd=0,cl;
	char * name = (char *)malloc(sizeof(char) * 100);
	char * domain = (char *)malloc(sizeof(char) * 100);
	char * last = (char *)malloc(sizeof(char) * 100);
	char * emailbefore = (char *)malloc(sizeof(char) * 100);
	if (email == NULL)
	{
		return 0;
	}
	while (email[++l]){}
	if (l > 254)
	{
		return 0;
	}
	for (i = 0; i < l; i++)
	{
		if (email[i] == '@')
		{
			cd++;
		}
	}
	if (cd !=1)
	{
		return 0;
	}
	i = 0;
	while (email[i] != ' '&&email[i] != '\0')
	{
		name[j] = email[i];
		i++;
		j++;
	}
	i++;
	name[j] = '\0';
	j = 0;
	if (i-1 == l)
	{
		return 0;
	}
	while (email[i] == ' '){ i++; }
	while (email[i] != '@'&&email[i]!='\0')
	{
		emailbefore[j] = email[i];
		i++;
		j++;
	}
	i++; emailbefore[j] = '\0';
	j = 0;
	if (i-1 == l)
	{
		return 0;
	}
	while (email[i] != '.'&&email[i] != '\0')
	{
		domain[j] = email[i];
		i++;
		j++;
	}
	i++; domain[j] = '\0';
	j = 0;
	if (i-1 == l)
	{
		return 0;
	}
	else
	{
		while (email[i] != '\0'&&email[i] != '\0')
		{
			last[j] = email[i];
			i++;
			j++;
		}
	}
	last[j] = '\0';
	j = 0;
	ceb = checkemailbefore(emailbefore);
	cn = checkname(name,emailbefore);
	if (ceb == -1)
	{
		return 0;
	}
	if (cn == -1)
	{
		return 1;
	}
	else return 2;
}
int checkname(char * name,char *email)
{
	int i = -1,l=-1,j=0,k=1,m=1;
	while (name[++i])
	{
		if (name[i] >= 65 && name[i] <= 90)
		{
			name[i] += 32;
		}
	}
	while (email[++l])
	{
		if (email[l] >= 65 && email[l] <= 90)
		{
			email[l] += 32;
		}
	}
	l = l - i;
	for (j = 0; j < i; j++)
	{
		if (name[j] != email[j])
		{
			k = 0;
		}
	}
	for (j = 0; j < i; j++)
	{
		if (name[j] != email[l+j])
		{
			m = 0;
		}
	}
	if (k == 0 && m == 0)
	{
		return -1;
	}
	else
	return 0;
}
int checkemailbefore(char * email)
{
	int i = 0;
	if (email[0] == '-' || email[0] == '_' || email[0] == '.')
	{
		return -1;
	}
	while (email[i] != '\0')
	{
		if ((email[i] >= 97 && email[i] <= 122) || (email[i] >= 65 && email[i] <= 90) || (email[i] >= 48 && email[i] <= 57) || (email[i] == '-') || (email[i] == '_') || (email[i] == '.'))
		{
			i++;
		}
		else return -1;
	}
	return 0;
}