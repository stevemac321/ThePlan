/*==============================================================================
 Name        : KR.1.10.c
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
Abstract     : Replace \t \b and \ rith visible marker
==============================================================================*/
#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define OUT 0
#define IN 1

int main()
{
	FILE *pf = fopen("/mnt/big/kmod.c", "r");
	assert(pf);
    int state = OUT;
    int words = 0;
	int c = 0;
	while ((c = getc(pf)) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t' ) {
            state = OUT;
        }else if(state == OUT){
            state = IN;
            words++;
        }
        
	}

	fclose(pf);
    printf("words: %d\n", words);
}
