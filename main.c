#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "interface.h"
#include "limits.h"
#include "error.h"

void print_usage()
{
    printf("\nInvalid arguments passed\n\n");
    // printf("-E : Encrypt\n-D : Decrypt\n");
    // printf("-I <image_file> : path to the image file\n");
    // printf("-T <text_filr> : path to test file, nedded if -E optin is selected\n");
    // printf("-P ""your_password"" : password to decrypt the file, should be between 8 and 16 characters\n");
}

int main(int argc, char *argv[])
{
    FILE *img, *txt;
    int is_args_valid;

    if (argc  > 8) {
        print_usage();
        return 1;
    }

    if ((strcmp(argv[1], "-E") != 0) && (strcmp(argv[1], "-D") != 0)) {
        printf("No operation selected or invalid option  entered\n");
        print_usage();

        return 1;
    }

    if ((strcmp(argv[1], "-E") == 0) && (argc != 8U)) {
        print_usage();

        return 1;
    } else if (((strcmp(argv[1], "-D") == 0) && (argc != 6U))) {
        print_usage();

        return 1;
    }

    if (strlen(argv[7]) < 8U || (strlen(argv[7]) > 16U)) {
        printf("Invalid Password\n");
        print_usage();

        return INVALID_PASS_LEN;
    }

    if (strcmp(argv[1], "-E") == 0) {
        img = fopen(argv[3], "rw");
        txt = fopen(argv[5], "r");
        if ((img != NULL) && (txt != NULL)) {
            is_args_valid = validate_enc_args(img, txt);
        } else {
            printf("Error openig file\n");
        }
    }

    if (is_args_valid != EOK) {
        printf("operation failed\n");
        return 1;
    }

    return 0;
}