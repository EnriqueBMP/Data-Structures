#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE*fptr;
    char filename[]="sales.txt";
    fptr= fopen (filename,"w");
if (fptr == NULL) {
    exit(-1);
}
printf ("ERROR IN FILE CREATION");

fprintf(fptr, "120.50\n450.75\n89.00 \n230.40 \n465.25 \n789.02 \n123.58 \n789.24 \n420.69\n 69.69");


    return 0;
}
