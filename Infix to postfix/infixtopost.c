#include <stdio.h>
#include <string.h>
char stack[100];
int top=-1;
int priority(char symbol)
{
 if(symbol=='+'||symbol=='-') return 2;
 if(symbol=='*'||symbol=='/') return 4;
 if(symbol=='^'||symbol=='$'||symbol=='%') return 6;
 else return 1;
}
int isoperator(char symbol)
{
 switch(symbol)
 {
 case '+':
 case '-':
 case '*':
 case '/':
 case '^':
 case '%':
 case '$':
 case '(':
 case ')':
 return 1;
 default: return 0;
 }
}
void push(char data)
{
 stack[++top]=data;
}
char pop()
{
 return stack[top--];
}
void eval(char infix[],char postfix[])
{
 int i,j=0;
 char ch;
 for(i=0;i<strlen(infix);i++)
 {
 ch=infix[i];
 if(isoperator(ch)==0) 
 postfix[j++]=ch;
 else if(ch=='(') 
 push(ch);
 else if(ch==')')
 {
 while(stack[top]!='(') 
 postfix[j++]=pop();
 pop();
 }
 else {
 while(priority(stack[top])>=priority(ch)) 
 postfix[j++]=pop();
 push(ch);
 }
 }
 while(top!=-1) 
 postfix[j++]=pop();
 postfix[j]='\0';
}
int main()
{
 int i;
 char infix[30],postfix[30];
 printf("Enter infix expression:");
 scanf("%s",infix);
 eval(infix,postfix);
 printf("\nThe postfix expression is : %s",postfix);
 printf("\n");
 return 0;
}
