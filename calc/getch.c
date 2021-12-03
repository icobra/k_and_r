#define BUFSIZE 100

char buf[BUFSIZE]; /*буфер для ungetch.*/
int bufp = 0; /* следущая свободная позиция в nbuf */

/* Ввод символа (возможно, возвращенного в поток). */
int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* Возвращение символа в поток ввода.*/
void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}