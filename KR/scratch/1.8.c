#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    FILE *pf = fopen("/mnt/big/code/KR/ch01/1.10.c", "r");
    assert(pf);

    int blanks = 0;
    int lines = 0;
    int tabs = 0;

	int c = 0;
	while ((c = getc(pf)) != EOF) {
        if(c == ' ')
            blanks++;
        else if(c == '\n')
            lines++;
        else if(c == '\t')
            tabs++;
            
    }
    fclose(pf);

    printf("blanks: %d lines: %d tabs: %d", blanks, lines, tabs);
}
