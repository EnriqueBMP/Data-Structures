#include <stdio.h>
#include <stdlib.h>


float totalsale(float sales[], int linecount){
    float sum =0.0;
    for(int i = 0 ; i<linecount; i++){
        sum+= sales[i];
    }
    return sum;
}
float maxsale(float sales[], int linecount){
    for (int i = 0; i < linecount - 1; i++) {
        for (int j = 0; j < linecount - i - 1; j++) {
            if (sales[j] > sales[j + 1]) {
                float temp = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = temp;
            }
        }
    }
    return sales[linecount-1];

}



int main()
{


    FILE*fptr;
    char filename[]="sales.txt";
    char line[1000];
    fptr= fopen (filename,"r");
if (fptr == NULL) {
    printf ("ERROR IN FILE READING \n");
    exit(-1);
}
    int linecount =0;
while(fgets(line,1000,fptr) !=NULL ){
    linecount++;
}
printf ("The file contains %d lines\n",linecount);

    rewind(fptr);

    float *sales = (float *) malloc(sizeof(float) * linecount); 

    for (int i = 0; i < linecount; i++) {
        if (fgets(line, sizeof(line), fptr) != NULL) {
            sales[i] = strtof(line, NULL);
        } else {
            sales[i] = 0.0;
        }
    }

for(int i = 0 ; i<linecount; i++){
    printf("%0.2f \n", sales[i]);
}

   float total = totalsale(sales, linecount);
   printf ("The total of the sales is: %0.2f \n", total);

 float maximum = maxsale(sales, linecount);
   printf ("The max sale is: %0.2f \n", maximum);



free(sales);
    fclose(fptr);
    return 0;
}

