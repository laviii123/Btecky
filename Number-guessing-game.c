#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	char name[30],ch='y';
	int a,b,n1,n2;	  
	printf("\t\t\t$~~~~NUMBER GUESSING GAME~~~~$");
	printf("\n\nKindly enter your name : ");
	gets(name);
	printf("\nHi, %s! It's good to see you here. Welcome to this number guessing game!! \nThe rules are quite simple.",name);
	printf("\n\nFirst of all,\nyou will have to think of two numbers and perform the operations as instructed.\n\nAt last I will guess those numbers which you thought of. Sound's interesting, isn't it?");
    getch();
	do
	{ 
	  system("cls");
	  printf("\n\n\t\t\t\t$ So let's start $");
	  printf("\n\n[Press enter to start]");
      getch();
	  printf("\n\nStep 1 : Think of 2 numbers \t\t\t[Press enter after doing each step]");
	  getch();
	  printf("\nStep 2 : Multiply the 1st number by 2 ");
	  getch();
	  printf("\nStep 3 : Add 5 to the product ");
	  getch();
	  printf("\nStep 4 : Multiply the result by 5 ");
	  getch();
	  printf("\nStep 5 : Finally add the 2nd number to it");
	  getch();
	  printf("\n\nEnter your final result : ");
	  scanf("%d",&a);
	  b=a-25;
	  n1=b/10;
	  n2=b%10;
	  printf("\nYour 1st number is %d",n1);
	  printf("\nYour 2nd number is %d",n2);
	  printf("\n\nHey am I correct? Yes I know I am!");
	  fflush(stdin);
	  printf("\n\nOkay, if you have enjoyed, let's play again?(Y/N) : ");
	  scanf("%c",&ch);
	  //printf("\n\n");
    }while(ch=='y' || ch=='Y');
}
