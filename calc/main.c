#include <stdio.h>
#include <stdlib.h>  /* Для объявления atof() */

#define MAXOP 100    /* Максимальный размер операнда или знака. */
#define NUMBER '0'   /* Сигнал, что обнаружено число. */

int getop();
void push(double);
double pop(void);

/* Калькулятор с обратной польской записью */
int main(int argc, char const *argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    while((type=getop(s)) != EOF){
    	switch(type) {
    		case NUMBER:
    		    push(atof(s));
    		    break;
    		case '+':
    		    push(pop() + pop());
    		    break;
    		case '*':
    		    push(pop() * pop());
    		    break;
    		case '-':
    		    op2 = pop();
    		    push(pop() - op2);
    		    break;
    		case '/':
    		    op2 = pop();
    		    if(op2 != 0.0)
    		    	push(pop() / op2);
    		    else
    		    	printf("error: zero divisor\n");
    		    break;
    		case '\n':
    		    printf("\t%.8g\n", pop());
    		    break;
    		default:
    		    printf("error: unknown command %s\n", s);
    		    break;
    	}
    }

	return 0;
}