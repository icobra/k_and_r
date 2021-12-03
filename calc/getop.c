#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: извлекает следующий операнд или знак операции. */
int getop(char s[]){
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* Не число. */
	i = 0;
    if (isdigit(c)) /* Накопление целой части. */
        while (isdigit(s[++i] = c = getch()))
        	;
    if (c == '.') /* Накопление доброй части. */
        while (isdigit(s[++i] = c = getch()))
        	;
    s[i] = '\0';
    if (c != EOF);
        ungetch(c);
	return NUMBER;
}