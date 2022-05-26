#include <stdio.h>
#include <string.h>
char st[20]; //Declaring variables
int top = -1;
//Declarinmg functions
void push(char);
char pop();
int main()
{
    char a[20], t;
    int i, f = 1;
    printf("Please Enter your equation: ");
    scanf("%s", a);
    for (i = 0; i < strlen(a); i++) 
    {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[') //Checking for paranthesis
            push(a[i]);//calling push function
        if (a[i] == ')' || a[i] == '}' || a[i] == ']')
        {
            if (top == -1) //checking if stack is empty or not
                f = 0;
            else
            {
                t = pop(); //calling pop function
                if (a[i] == ')' && (t == '[' || t == '{'))
                    f = 0;
                if (a[i] == '}' && (t == '(' || t == '['))
                    f = 0;
                if (a[i] == ']' && (t == '{' || t == '('))
                    f = 0;
            }
        }
    }
   
    if (f == 0)
        printf("The equation is Unbalanced\n");
    else
        printf("The equation is Balanced\n");
    return 0;
}
void push(char a) //Push function
{
    st[++top] = a;
}
char pop() //Pop Function
{
    return st[top--]; 
}