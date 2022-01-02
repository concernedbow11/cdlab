#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[20];
int top=-1;
void push(char val) {
	top++;
	stack[top]=val;
	}
void pop() {
	if(top!=-1) {
		top--;
		}
	}
int prec(char c) {
	switch(c) {
		
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '%':
			return 3;
			break;
		case '=':
			return 0;
			break;	
		default:
			return 0;
			break;
		}
	}
int main() {
	
	int i,k=0,temp,temp1;
	char op1,op2,res;
	char postfix[20];
	for(i=0;i<20;i++)
		postfix[i]='\0';
	for(;i<20;i++)
		stack[i]='\0';
	char str[20];

temp=65;
temp1=48;
	printf("enter the expression :\n");
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++) {
		
		if(str[i]=='(') {
			
			push(str[i]);
			}
		else if(str[i]==')') {
			
			while(stack[top]!='(') {
				
				postfix[k++]=stack[top];
				pop();
				}
			pop();
			}
		else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
			
			postfix[k++]=str[i];
			}
		else if(str[i]=='%' || str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='=') {
			
			if(top==-1 || stack[top]=='(') {
				
				push(str[i]);
				}
			else if(prec(str[i])>=prec(stack[top])) {
				
				push(str[i]);
				}
			else if(prec(str[i])<prec(stack[top])) {
				
				while(prec(str[i])<prec(stack[top])) {
					
					postfix[k++]=stack[top];
					pop();
					}
				push(str[i]);
				}
			}
		}
	while(top!=-1) {
		
		postfix[k++]=stack[top];
		pop();
		}
	
	printf("\nQuadruple: \n\n");
	printf("\toperator\toperand 1\toperand 2\t result\n");
	for(i=0;postfix[i]!='\0';i++) {
		
		if((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z')) {
			
			push(postfix[i]);
			}
		else if(postfix[i]=='%' || postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' ) {
			
			op2=stack[top];
			pop();
			op1=stack[top];
			pop();
			res=temp++;
			push(res);
			printf("\n\t%c\t\t%c\t\t%c\t\t%c\n",postfix[i],op1,op2,res);
			}
		else if( postfix[i]=='='){
		op2=stack[top];
			pop();
			op1=stack[top];
			pop();
		printf("\n\t%c\t\t%c\t\t\t\t%c\n",postfix[i],op2,op1);
		
		}
		}
	printf("\n\ntriple: \n\n");
	printf("index\toperator\toperand 1\toperand 2\t\n");
	for(i=0;postfix[i]!='\0';i++) {
		
		if((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z'))
			push(postfix[i]);
		else if(postfix[i]=='%' || postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/') {
			
			op2=stack[top];
			pop();
			op1=stack[top];
			pop();
			res=temp1++;
			push(res);
			printf("%c)\t\t%c\t\t%c\t\t%c\n",res,postfix[i],op1,op2);
			
			}
			else if( postfix[i]=='='){
		op2=stack[top];
			pop();
			op1=stack[top];
			pop();
		printf("%c)\t\t%c\t\t%c\t\t%c\n",temp1++,postfix[i],op1,op2);
		
		}
		}
		printf("\n\nCode generation: \n\n");
		temp1=48;
		int te=0;
	for(i=0;postfix[i]!='\0';i++) {
		
		if((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z'))
			push(postfix[i]);
		else if(postfix[i]=='+' ) {
			
			op2=stack[top];
			pop();
			if(op2>=48 && op2<=57)
			        {printf("MOV R%c,R%d\n",op2,te);}
			else{        
			printf("MOV %c,R%d\n",op2,te);}
			op1=stack[top];
			pop();
			if(op1>=48 && op1<=57)
			{printf("ADD R%d,R%c\n",te,op1);}
			else{
			printf("ADD R%d,%c\n",te,op1);}
			res=temp1++;
			push(res);
			te=te+1;
			}
			else if( postfix[i]=='-'){op2=stack[top];
			pop();
			if(op2>=48 && op2<=57)
			        {printf("MOV R%c,R%d\n",op2,te);}
			else{        
			printf("MOV %c,R%d\n",op2,te);}
			op1=stack[top];
			pop();
			if(op1>=48 && op1<=57)
			{printf("SUB R%d,R%c\n",te,op1);}
			else{
			printf("SUB R%d,%c\n",te,op1);}
			res=temp1++;
			push(res);
			te=te+1;}
			else if( postfix[i]=='*'){op2=stack[top];
			pop();
			if(op2>=48 && op2<=57)
			        {printf("MOV R%c,R%d\n",op2,te);}
			else{        
			printf("MOV %c,R%d\n",op2,te);}
			op1=stack[top];
			pop();
			if(op1>=48 && op1<=57)
			{printf("MUL R%d,R%c\n",te,op1);}
			else{
			printf("MUL R%d,%c\n",te,op1);}
			res=temp1++;
			push(res);
			te=te+1;}
			else if(postfix[i]=='/'){
			op2=stack[top];
			pop();
			if(op2>=48 && op2<=57)
			        {printf("MOV R%c,R%d\n",op2,te);}
			else{        
			printf("MOV %c,R%d\n",op2,te);}
			op1=stack[top];
			pop();
			if(op1>=48 && op1<=57)
			{printf("DIV R%d,R%c\n",te,op1);}
			else{
			printf("DIV R%d,%c\n",te,op1);}
			res=temp1++;
			push(res);
			te=te+1;
			}
			else if( postfix[i]=='='){
		op2=stack[top];
			pop();
			op1=stack[top];
			pop();
			if(op2>=48 && op2<=57)
			{
			printf("MOV R%c,%c",op2,op1);}
		
		}
		}	
	
    return 0;
}
