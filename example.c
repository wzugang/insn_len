#include <stdio.h>
#include "insn_len.h"


int main() {
    int pos = 0, len, i;
    unsigned char *p = (unsigned char*)insn_len_x86_32;


    while (1) {
        len = insn_len(p);

        printf("length: %2d   pos: %4x    bytes:  ", len, pos);

        for (i=0; i < len; i++)
            printf("%02x ", p[i]);
        printf("\n");

        if (*p == 0xc3)
            break;

        pos += len;
        p += len;
    }
}
