#define MAXVAL 100 /* Максимальная глубина стека val. */

int sp = 0; /* Следущая свободная позиция в стеке. */ 
double val[MAXVAL]; /* Стек операндов.*/

/*push: помещает число f в стек операндов. */
void push(){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/*pop: извлекает и возвращает верхнее число из стека. */
double pop(void){
	if (sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}