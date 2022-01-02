#include<stdio.h>
#include<string.h>
char input[30];
char l;
int pos=0;
void match(char t)
{
	if (l == t) {
	        pos=pos+1;
		l=input[pos];
	}
	else
		printf("Error");
}
void E(),F(),Y(),T(),Z();
void Y(){
if(l=='*')
 {
 match('*');
 F();
 Y();
 }
 
}
void T(){
  F();
  Y();
}
void Z()
{
	if (l == '+') {
		match('+');
		T();
		Z();
	}
	
		
}
void E()
{       T();
        Z();
	
}
void F(){
    if(l=='(')
         {
           match('(');
           E();
           match(')');        
         }
    else if(l=='i')
            {
            match('i');
            }  
    else{
          printf("Error");
    }           

}


int main()
{       printf("Enter input string\n");
        scanf("%s",input);
        l=input[pos];

	E();
  
	if (l == '$')
		printf("Parsing Successful");
	else
	    printf("Error");	
}

/* E –> T Z 
Z –> + T Z | e 
T –> F Y 
Y –> * F Y | e 
F –> ( E ) | i */

