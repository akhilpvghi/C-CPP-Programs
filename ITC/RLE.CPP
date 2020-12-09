#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
int decToBinary(int n)
{
	int binary_digit_count = 0;
	int binNum[32];
	int i = 0;
	while (n > 0)
	{
		binNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%d", binNum[j]);
		binary_digit_count++;
	}
	return binary_digit_count;
}

void main()
{
	clrscr();
	char *str;
	int count = 0, total_no_of_char = 0,binary_count_i=0, total_binary_count = 0, max_binary_count = 0;
	float comp_ration = 0.0;
	printf("enter the string ");
	gets(str);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == str[i + 1])
		{
			count++;
		}
		else
		{
			printf("\n ( ");
			total_no_of_char++;
			 binary_count_i = decToBinary(count + 1);
		       //	if (total_binary_count < binary_count_i)
		       //	{
			 //	max_binary_count = log(binary_count_i) / log(2);
		       //	}
		      //	printf("\n max_binary_count %d", max_binary_count);
			printf(" %c ", str[i]);
			//	total_binary_count=max_binary_count*total_no_of_char+total_no_of_char;
			total_binary_count+=   binary_count_i+1;
			printf(" ) ");
			//printf("\n total_binary_count %d", total_binary_count);
			count = 0;
		}
			}
			printf("\nstr length of input string %d", strlen(str));

		printf("\ntotal_binary_count %d ",total_binary_count);
		comp_ration = total_binary_count/float(strlen(str))  ;
		printf("\n COMPRESIION RATIO IS %f ",comp_ration);


	getch();
}
