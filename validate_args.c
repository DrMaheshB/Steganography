#include <stdio.h>
#include <error.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "interface.h"
#include "limits.h"
#include "error.h"


int validate_enc_args(FILE *img, FILE *txt) {
    long img_size, txt_size;

    /* Get image file size*/
    fseek(img, 0L, SEEK_END);
    img_size = ftell(img);
    fseek(img, 0L, SEEK_SET);

    /* Get txt file size*/
    fseek(txt, 0L, SEEK_END);
    txt_size = ftell(txt);
    fseek(txt, 0L, SEEK_SET);

    if (txt_size > MAX_TXT_SIZE) {
        printf("Text file execeeds 1024 characters\n");
        return MAX_TXT_FILE_SIZE_EXCEEDED;
    }

    if (img_size <= MAX_IMG_SIZE) {
        if (img_size < (txt_size + MIN_PASS_LEN + 1024U)) {
            printf("image file size insufficient\n");
            return INSUFFICIENT_IMG_SIZE;
        }
    }

    return EOK;
}

int validate_dec_args(FILE *img) {
    long img_size;

    /* Get image file size*/
    fseek(img, 0L, SEEK_END);
    img_size = ftell(img);
    fseek(img, 0L, SEEK_SET);

    if (img_size >= MAX_IMG_SIZE) {
        return MAX_IMG_FILE_SIZE_EXCEEDED;
    } else {
        return EOK;
    }
}