
/*==============================================================================
 Name        : files.cpp 
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
 
==============================================================================*/
#include "test.h"
#define OUT 0
#define IN  1

int word_count()
{
	FILE *pf = fopen("kmod.c", "r");
    if(!pf) {
        perror("failed to open kmod.c");
        return -1;
    }
	
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
	return words;
}
