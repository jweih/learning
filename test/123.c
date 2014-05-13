#include <stdio.h>
#include <string.h>
int main()
{
	void sort(char str[]);
	char string[11];
	int i ;
	printf("input char :\n");
	for(i = 0; i < 10; i++)
		scanf("%c", &string[i]);
        string[10]='\0';
	printf("The original :\n");
	for(i = 0; i < 10; i++)
		printf("%c ", string[i]); 
	printf("\n");
	sort(string);
	printf("The sorted :\n");
	for(i = 0; i < 10; i++)
		printf("%c ", string[i]);
	printf("\n");
	return 0;
}


void sort(char str[])
{
	int i, j, k, n;
	char temp;
	n = strlen(str);
	for(i = 0; i < n - 1; i++)
	{
		k = 0;
		for(j = 1; j < n - i; j++)
		{
			if(str[k] > str[j])
			{
				temp = str[k];
				str[k] = str[j];
				str[j] = temp;
			}
			k = j;
		}
	}
}