
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*STRUCTURES*/
struct tree                 
{	int data;                
	int trav_val;            
	char ckey;              
	tree *rlink;            
	tree *llink;            
}**root=NULL,*temp;

struct calc_sum              
{	int sum;                 
	int right;               
	int left;                 
}*total;                     

struct string                //The structure is used to assign the frequency of each character
{	char alph;               //alph is the character
	int freq;                //freq is the frequency of the character
}*ori_string,*pre_string,*fixed_string;    /*ori_string is the original string(containing freq and char of each character entered by user)
			                   and pre_string is the preserved string*/

struct encode                //The structure is used to assign the Huffman's code to different characters
{	char letter;             //This is the character assigned to the leaf node
	int *code;               //It contains the Huffman's code for the character 
	int length;              //Contains the length of the Huffman's code
}*enc;

/*FUNCTION DECLARATIIONS*/
void sort(string [],int);
void insert(struct calc_sum [],int);
void display(struct tree *, int str_len);
void encode(struct encode *,char *);

/*GLOBAL VARIABLES*/
/*i,j,k,m are loop variables
  next_char is the no of different characters in the input string
  str_len is the length of the input string
  ch is used to drive the menu
  input is the input string
*/
int next_char,str_len;
static int *trav,m,root_check,i,j,k;
char ch,*input,dest[300],*alpha[]={"a","b","c","d","e","f","g","h"};
float avgCodeLength =0.0;
float entropy=0;
/*MAIN*/
void main()
{
int freq[10],noOfStr=0;
do
	{   char *string;//It is a temporary pointer variable containing the string
		int flag,char_freq;//char_freq is the freq of different characters
		clrscr();
		//akhil printf("\nEnter the String\n");
	printf("\nEnter no of strings : "); //akhil
		scanf("%d",&noOfStr);
		for(int i=0;i<noOfStr;i++){
		printf("enter frequency for symbol %s : ",alpha[i]);
		scanf("%d",&freq[i]);
		str_len+=   freq[i] ;
		for(int j=0;j<freq[i];j++)
		strcat(dest,alpha[i]);
		}
	fflush(stdin);
		input = dest;
		// input=gets(string);
		//str_len=strlen(input);
		//printf("\nLength of the string:%d",str_len);
		ori_string=(struct string *)malloc(str_len*sizeof(struct string));
		trav=(int *)malloc(str_len*sizeof(int));
		pre_string=(struct string *)malloc(str_len*sizeof(struct string));
		fixed_string=(struct string *)malloc(str_len*sizeof(struct string));
		 for(i=32,next_char=0;i<127;i++)
		 {       flag=0,char_freq=0,j=0;
			while(input[j]!='\0')
			{	if(input[j]==i)
				{	flag=1;
					ori_string[next_char].alph=pre_string[next_char].alph=fixed_string[next_char].alph=input[j];
					char_freq++;
				}
				j++;
			}
			if(flag)
			{
				ori_string[next_char].freq=pre_string[next_char].freq=fixed_string[next_char].freq=char_freq;
				next_char++;				}
			}
		if(next_char==1||str_len==0)
		{   printf("\n!!!ENCODING NOT POSSIBLE!!!\nYOU HAVE ENTERED\n1.A SINGLE CHARACTER OR\n2.SAME SET OF CHARACTERS");
			printf("\nPRESS 'ENTER' TO TRY AGAIN");
			fflush(stdin);
			getch();
		}
		else
		{	enc=(struct encode *)malloc(next_char*sizeof(struct encode));
			sort(ori_string,next_char);
		}
		printf("\n\nDo you want to continue(Y/N)\n");
		free(ori_string);
		free(pre_string);
		free(trav);
		free(total);
		free(temp);
		free(root);
		fflush(stdin);
		free(enc);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
}


void sort(string ori_string[],int next_char)
{  	k=next_char-1;
	int swap;
	total=(struct calc_sum *)malloc(k*sizeof(struct calc_sum));
	while(k>0)
     {	for(i=0;i<k+1;i++)
		for(j=i+1;j<k+1;j++)
		{	if(ori_string[i].freq<ori_string[j].freq)
			{	swap=ori_string[i].freq;
				ori_string[i].freq=ori_string[j].freq;
				ori_string[j].freq=swap;
			}
		}
		total[next_char-1-k].left=ori_string[i-1].freq;
		total[next_char-1-k].right=ori_string[i-2].freq;
		total[next_char-1-k].sum=total[next_char-1-k].left+total[next_char-1-k].right;
		ori_string[k-1].freq=total[next_char-1-k].sum;
		// printf("%d  \t%d  \t%d\n",total[next_char-1-k].left,total[next_char-1-k].right,total[next_char-1-k].sum);
		k--;
	}
	insert(total,next_char);
}


void insert(struct calc_sum total[],int next_char)
{	int roots,count=0,lflag,rflag,rchange=0,lchange=0;
	k=0;
	char swap;
	float tot_roots;
	tot_roots=log(2*next_char-1)/log(2);
	roots=pow(2,int(tot_roots-1));
	root=(struct tree **)malloc(roots*sizeof(struct tree));
	for(i=0;i<roots;i++)
	root[i]=NULL;
	while(k<next_char-1)
	{   lflag=rflag=1;
		temp=(struct tree *)malloc(sizeof(struct tree));
		temp->data=total[k].sum;
		if(k==0)
		{	struct tree *r=(struct tree *)malloc(sizeof(struct tree));
			r->data=total[k].right;
			r->trav_val=1;
			r->rlink=NULL;
			r->llink=NULL;
			for(i=next_char-1;i>=0;i--)
			{	if(pre_string[i].freq==total[k].right)
				{   r->ckey=pre_string[i].alph;
					pre_string[i].freq=0;
					break;
				}
			}
			temp->rlink=r;
			struct tree *l=(struct tree *)malloc(sizeof(struct tree));
			l->data=total[k].left;
			l->trav_val=0;
			l->rlink=NULL;
			l->llink=NULL;
			for(i=next_char-1;i>=0;i--)
			{	if(pre_string[i].freq==total[k].left)
				{   l->ckey=pre_string[i].alph;
					pre_string[i].freq=0;
					break;
				}
			}
			temp->llink=l;
			root[0]=temp;
		}
		else
		{	for(i=0;i<roots;i++)      // check for right
			{	if(total[k].right==root[i]->data)
				{
					root[i]->trav_val=1;
					temp->rlink=root[i];
					rflag=0;
					rchange=i;
					root[rchange]=temp;
				}
				if(!rflag)
				break;
			}
			if(i>=roots)
			{	struct tree *r=(struct tree *)malloc(sizeof(struct tree));
				r->data=total[k].right;
				r->trav_val=1;
				r->rlink=NULL;
				r->llink=NULL;
				for(i=next_char-1;i>=0;i--)
				{	if(pre_string[i].freq==total[k].right)
					{       r->ckey=pre_string[i].alph;
						pre_string[i].freq=0;
						break;
					}
				}
				temp->rlink=r;
			}
			for(i=0;i<roots;i++)       //check for left
			{	if(total[k].left==root[i]->data)
				{
					root[i]->trav_val=0;
					temp->llink=root[i];
					lflag=0;
					lchange=i;
					root[lchange]=temp;
				}
				if(!lflag)
				break;
			}
			if(i>=roots)
			{
				struct tree *l=(struct tree *)malloc(sizeof(struct tree));
				l->data=total[k].left;
				l->trav_val=0;
				l->rlink=NULL;

					l->llink=NULL;
				for(i=next_char-1;i>=0;i--)
				{	if(pre_string[i].freq==total[k].left)
					{   l->ckey=pre_string[i].alph;
						pre_string[i].freq=0;
						break;
					}
				}
				temp->llink=l;
			}
			if(rflag&&lflag)
			{	root[++count]=temp;
				if(root[count]->llink->data==root[count]->rlink->data)
				{
					swap=root[count]->llink->ckey;
					root[count]->llink->ckey=root[count]->rlink->ckey;
					root[count]->rlink->ckey=swap;
				}
			}
			if(!rflag&&!lflag)
			root[rchange]=NULL;
		}
		k++;
	}
	printf("\nPRESS ENTER TO GET THE HUFFMAN CODES AND EFFICIENCY \n");
	getch();
	clrscr();
	printf("\nHUFFMAN CODES\n");
	m=0,i=0,j=0,k=0;
	display(root[lchange],str_len);
	printf("\n AVERAGE CODE LENGTH IS %f",avgCodeLength);
	printf("\nEntropy is %f",entropy) ;
	printf("\nEfficiency is %f",entropy/avgCodeLength);
}

void display(struct tree *disp, int str_len)
{
	float selfInfo[10];

if(disp!=NULL)
	{	if(root_check>=1)
		trav[m++]=disp->trav_val;
		root_check++;
		display(disp->llink, str_len);
		display(disp->rlink, str_len);
		if(disp->llink==NULL&&disp->rlink==NULL)
		{   enc[i].code=(int *)malloc(m*sizeof(int));
			printf("%c-",disp->ckey);
			enc[i].letter=disp->ckey;
			enc[i].length=0;
			for(m=0;m<root_check-1;m++)
			{          printf("%d",trav[m]);
				       enc[i].code[j]=trav[m];
				       enc[i].length++;
				       j++;
			}
			int k=0;
			while(k<7){
			if(disp->ckey==fixed_string[k].alph)
			{     entropy+= fixed_string[k].freq/float(str_len)*(log(str_len/float(fixed_string[k].freq))/log(2));
			avgCodeLength+=m*fixed_string[k].freq/float(str_len);

   break;
			 }	   else
				    k++;
				   }
			i++;

			printf("\n");
		}
		m--;
		root_check--;
	}

}

