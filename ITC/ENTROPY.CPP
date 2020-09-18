#include<conio.h>
#include<math.h>
#include<stdio.h>
void entropy(int n,float *a){
float entropy = 0,selfInfoasymbol=0;
for(int i=0;i<n;i++){
selfInfoasymbol = log(1/a[i])/log(2);
printf("\nself info for symbol %d is %f",i+1,selfInfoasymbol);
entropy+=a[i]*selfInfoasymbol;

}
printf("\n Entropy Of source is %f ",entropy);
}

void main(){
clrscr();
float a[10];
int n;
printf("Enter no of symbols");
scanf("%d",&n);

for(int i=0;i<n;i++){
printf("\n Enter Probability for symbol %d :",i+1);
scanf("%f",&a[i]);
}
entropy(n,a);
getch();
}