#include<conio.h>
#include<stdio.h>
#include <string.h>

//char initial_state[] = "000";
char state[]="000" ;

struct circuit{
char ckt_string[10];
} ;
circuit ckt[5];


void shiftRight(char myarray[],char to_add,int n){
     // printf("\n  msg coming %s ",myarray);
     int output_string,op,op_string;


       //	printf("\n char adding %c ",to_add);
	for (int i=1; i < strlen(myarray); i++){
		myarray[strlen(myarray)-i]=myarray[strlen(myarray)-1-i];

	}
       myarray[0]=to_add;
       strcpy(state,myarray);
      printf("\n\n shifted msg %s ",state);
       for(int l=0;l<n;l++){
       op=0;
	op_string=0;
	output_string=0;
	printf("\n polynomial circuit %s ",ckt[l].ckt_string);
	for (int p=0; p < strlen(ckt[l].ckt_string); p++){
		if(int(ckt[l].ckt_string[p])==49){
			op += int(myarray[p]);
			//printf(" total output %d",op);
		}

	}
	op_string = op%2;
			output_string = op_string;
			printf(" output %d ",output_string);
	//gets();
}

}


void main(){
clrscr();
int n=0,k=0,K=0;
char *message;
printf("Enter value of n,k,K ");
scanf("%d",&n);
scanf("%d",&k);
scanf("%d",&K);
fflush(stdin);

printf("Enter message bits ");
gets(message);
//printf("\n value of %d, %d, %d ",n,k,K);
//printf("\n message %s",message);
	//state=initial_state;
     //shiftLeft("1110",4,1);

for(int j=0;j<n;j++){
	printf("Enter vector polynomial for circuit %d ",j+1);
	//fflush(stdin);
	gets(ckt[j].ckt_string);
}


//for(int i=1;i<=strlen(message);i++){
	int i=1;
	do{

	if(i>strlen(message)&&strcmpi(state,"000")){
	shiftRight(state,'0',n);
	} else{
	shiftRight(state,message[i-1],n);
	}
       //	if(i>strlen(message)&&strcmpi(state,"000")){
       //	shiftRight(state,'0',n);
       //	}
	i++;
	}while(i<=strlen(message) || strcmpi(state,"000"));
	//|| strcmpi(state,"000")
	//printf("\n %s",state);

//}




getch();
}