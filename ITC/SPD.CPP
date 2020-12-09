#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	clrscr();
    int n;
    printf ( "Stationary Probability Distribution\n\n" ) ;
    printf("Size of transition matrix, n= ");
    scanf("%d", &n);

    float transitionMatrix[10][10], sum[10], result[10], temp=0;
    printf("Transition Matrix = \n");
    float k=0;
    for( int i = 0; i<n; i++){
	for(int j = 0; j<n; j++){
	    scanf("%f", &transitionMatrix[i][j]);
	    k += transitionMatrix[i][j];
	}
	sum[i]=k;
	k--;
       //	printf("\nk= %.2f\nSum[%d]= %0.2f\n", k, i, sum[i]);
    }

    for( i = 0; i<n; i++){
	if(transitionMatrix[i][n-1]==1){
	    if(sum[i]>1){
		printf("invalid transition matrix");
	    }
	    else if (sum[i]==1){
		result[i]=1;
	      //	printf("\nresult[%d]= %.2f", i, result[i]);
	    }
	}
	else{
	    if(sum[i]>1){
		printf("invalid transition matrix");
	    }
	    else if (sum[i]==1){
		result[i]= 1- transitionMatrix[i][n-1];
	       //	printf("\nresult[%d]= %.2f", i, result[i]);
	    }
	}
	temp+= result[i];
    }

    printf("\n\n pi= [ ");
    for( i = 0; i< n; i++){
	printf("%.2f\t", result[i]/temp);
    }
    printf("]");
    getch();
    return 0;
}