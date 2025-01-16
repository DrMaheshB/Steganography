#include <stdlib.h>

/* 
The functions validates if the called when encode option is selected.
It verifies weather the size image size is less than 1MB and is large enough to store the
text and the password. 
*/
int validate_enc_args(FILE *img, FILE *txt);

/* 
The functions validates if the called when decode option is selected.
It verifies weather the size image size is less than 1MB. 
*/
int validate_dec_args(FILE *img);