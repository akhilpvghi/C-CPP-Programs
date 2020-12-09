#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
    clrscr();
    int k, n;

    printf("Enter n and k ");
    scanf("%d %d",&n, &k);


    int * G= (int*)malloc(k * n * sizeof(int));
    int * H= (int*)malloc((n-k) * n * sizeof(int));
    int * Ptranspose= (int*)malloc((n-k) * k * sizeof(int));
    int * P= (int*)malloc(k * (n-k) * sizeof(int));
    int * I= (int*)malloc(k * k * sizeof(int));
    int * u= (int*)malloc(k * sizeof(int));
    int * v= (int*)malloc(n * sizeof(int));

    printf("Enter Parity Matrix H= \n");
    for(int i= 0; i<n-k; i++){
	for(int j= 0; j<n; j++){
	    scanf("%d", &H[i*n+j]);
	}
    }


    //printf ( "Enter msg size: " ) ;
    //scanf("%d", &msgSize);

    printf("Enter message u: \n");
    for( i = 0; i<k; i++){
	scanf("%d", &u[i]);
    }

/*    printf("H= \n");
    for(int i= 0; i<n-k; i++){
	for(int j= 0; j<n; j++){
	    printf("%d\t", H[i][j]);
	}
	printf("\n");
    }
*/
   for( i= 0; i<n-k; i++){
	for(int j = 0; j< k; j++){
	    Ptranspose[i*k+j]= H[i*n+(j+(n-k))];
	}
    }

    printf("PTranspose=\n");
    for( i= 0; i<n-k; i++){
	for(int j = 0; j< k; j++){
	    printf("%d  ", Ptranspose[i*k+j]);
	    P[j*(n-k)+i]= Ptranspose[i*k+j];
	}
	printf("\n");
    }

    printf("P=\n");
    for( i= 0; i<k; i++){
	for(int j = 0; j< n-k; j++){
	    printf("%d  ", P[i*(n-k)+j]);
	    G[i*n+j] = P[i*(n-k)+j];
       }
	printf("\n");
    }

    //printf("Identity matrix of size %d \n", k);
    for( i= 0; i<k; i++){
	for(int j=0; j<k; j++){
	    if(i==j){
		I[i*k+j]= 1;
	    }
	    else{
		I[i*k+j]= 0;
	    }
	    //printf("%d\t", I[i][j]);
	    G[i*n+(j+(n-k))]= I[i*k+j];
	}
	//printf("\n");
    }

    printf("\nG=");
    for( i= 0; i<k; i++){
	for(int j=0; j<n; j++){
	    printf("%d  ", G[i*n+j]);
	    v[j]=0;
	}
	printf("\n");
    }

    printf("\nv=\n");
    for( i= 0; i<k; i++){
	for(int j = 0; j<n; j++){
	    if(u[i]==1){
		if(v[j] != G[i*n+j]){
		    v[j] = 1;
		}
		else{
		    v[j]= 0;
		}
	    }
	}
    }

    for( i= 0; i<n; i++){
	printf("%d  ", v[i]);
    }


    getch();
	return 0;
}