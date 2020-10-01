#include<stdio.h>
#include<conio.h>
#include<string.h>
void decToBinary(int n){
    int binNum[32];
    int i=0;
    while(n>0){
	binNum[i] =n%2;
	n = n/2;
	i++;
    }
    for(int j=i-1;j>=0;j--){
    printf("%d",binNum[j]);
    }
}

void main(){
clrscr();
char *str;
int count=0;
printf("enter the string ");
gets(str);
for(int i=0;i<strlen(str);i++){
	if(str[i]==str[i+1]){
		count++;

	}
       else{
	printf("\n ( %c ",str[i]);

	decToBinary(count+1);
	printf(" ) ");
	count=0;

	}
}

getch();

}
