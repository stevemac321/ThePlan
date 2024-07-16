
/*==============================================================================
 Name        : 1.5.4-KR.c - the KR version of this program on page 20
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
 Abstract    : count lines, words, characters. (behave like wc -l)
==============================================================================*/
#include <assert.h>
#include <stdio.h>

int main()
{
	FILE *pf = fopen("test.txt", "r");
	assert(pf);

  const unsigned int IN = 1;
  const unsigned int OUT = 0;

  int c=0;
  int nl = 0;
  int nw = 0;
  int nc = 0;
  int state = OUT;

  while((c = getc(pf)) != EOF) {
    ++nc;
    if(c == '\n')
      ++nl;

    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if(state == OUT) {
      state = IN;
      ++nw;
    }
  }


	fclose(pf);
	printf("lines: %d words: %d  chars: %d\n", nl, nw, nc);
}
