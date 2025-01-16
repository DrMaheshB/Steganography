#include <stdio.h>
#include "limits.h"
#include "error.h"

void print_usage()
{
    printf("\nInvalid arguments passed\n");
    printf("-E : Encrypt\n-D : Decrypt\n");
    printf("-I <image_file> : path to the image file\n");
    printf("-T <text_filr> : path to test file, nedded if -E optin is selected\n");
    printf("-P ""your_password"" : password to decrypt the file\n");
}

int main(int argc, char *argv[])
{
    printf("Request recived \nProcessing\n");
    print_usage();
    return 0;
}

