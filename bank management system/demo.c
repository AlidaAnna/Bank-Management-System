#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct bank
{
char uname[50];
char password[50];
int balances;
};
FILE *fp;
int fbal;
void choices(struct bank *b);
void deposite(struct bank *b);
void withdraw(struct bank *b);
void balance(struct bank *b);
void accountcreate(struct bank *b);
void login(struct bank *b);
void main()
{
struct bank b;
int d;
printf("\nBANK MANAGEMENT SYSTEM");
printf("\n***********************");
b.balances=0;
while(1)
{
printf("\n1:Create Account");
printf("\n2:Login");
printf("\n3.Exit");
printf("\nEnter your choices:");
scanf("%d",&d);
switch(d)
{
case 1:
accountcreate(&b);
break;
case 2:
login(&b);
break;
case 3:
exit(0);
break;
default:
printf("Invalid:");
}
}
}
void accountcreate(struct bank *b)
{
char name[50],pass[50];
fp=fopen("Bank.txt","a");
printf("\nEnter your username:");
scanf("%s",b->uname);
printf("Enter a password:");
scanf("%s",b->password);
printf("Account created successfully");
fprintf(fp,"%20s%20s%8d",b->uname,b->password,b->balances);
fclose(fp);
}
void login(struct bank *b)
{
char name[50],pass[50];
char fname[50],fpass[50];
int flag=0;
printf("\nLOGIN");
printf("\n*******");
printf("\nEnter your username:");
scanf("%s",name);
printf("\nEnter your password:");
scanf("%s",pass);
fp=fopen("Bank.txt","r+");
while(!feof(fp))
{
fscanf(fp,"%s%s%d",fname,fpass,&fbal);
if(strcmp(fname,name)==0&&strcmp(fpass,pass)==0)
{
printf("\nLogin successfully:");
flag=1;
choices(b);
break;
}
}
if(flag==0)
{
printf("\nLogin failed:");
exit(0);
}
fclose(fp);
}
void choices(struct bank *b)
{
int c;
while(1)
{
printf("\n1:deposite");
printf("\n2:withdraw");
printf("\n3:check current balances");
printf("\n4.Exit");
printf("\nEnter your choices:");
scanf("%d",&c);
switch(c)
{
case 1:
deposite(b);
break;
case 2:
withdraw(b);
break;
case 3:
balance(b);
break;
case 4:
exit(0);
break;
default:
printf("Invalid:");
}
}
}
void deposite(struct  bank *b)
{
float am;
fseek(fp,-8L,1);
printf("\nDEPOSIT");
printf("\n********");
printf("\nCurrent balance=%d\n",fbal);
printf("\nEnter the amount to deposit:");
scanf("%f",&am);
if(am>0)
{
fbal=fbal+am;
fprintf(fp,"%8d",fbal);
}
else
{
 printf("\nerror occur:");
}
}
void withdraw(struct bank *b)
{
float am;
fseek(fp,-8L,1);
printf("\nWithdraw:");
printf("\n*********");
printf("\nCurrent balance=%d\n",fbal);
printf("\nEnter the amount to be withdraw:");
scanf("%f",&am);
if(fbal>0&&am>0)
{
fbal=fbal-am;
fprintf(fp,"%8d",fbal);
}
else
{
printf("\nError occured");
}
}
void balance(struct bank *b)
{
printf("\nCheck bank balances:");
printf("\n********************");
printf("\nYour current Bank balances:%d",fbal);
}

