#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
    return sin(x)/x;
}

float f_der(float x, float delta){
    return ((f(x) - delta) - (f(x) + delta))/(2*delta);
}

int main() {
    //TEMPORARY CREATION OF FILE
    FILE* output;
    output = fopen("values.txt", "w");
    if(!output){
        printf("\nError creating file.");
    }
    fprintf(output,"0.0\n1.0\n2.0\n0.223\n123.11");
    fclose(output);
    //TEMPORARY CREATION OF FILE

    FILE* input;
    input = fopen("values.txt","r+");
    if(!input){
        printf("\nError opening file.");
    }


    float delta = 0;
    printf("\nInsert delta: ");
    scanf("%f", &delta);
    fseek(input,0,SEEK_END);
    int dim = (int) ftell(input) / sizeof(float);
    rewind(input);

    //Parse values
    float x_values[dim];
    int ctr = 0;
    while(!feof(input) && ctr <= dim){
        fscanf(input, "%f", &x_values[ctr]);    //Expecting error here, left on purpose
        ctr++;
    }

    fclose(input);

    //Print values
    for(int loop_ctr = 0; loop_ctr < ctr; loop_ctr++){
        printf("\nValue of x: %f, value of f'(x): %f", x_values[loop_ctr], f_der(x_values[loop_ctr], delta));
    }

    return 0;
}
