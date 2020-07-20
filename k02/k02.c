#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

int main(void)
{
    double val,u1,s1,u2,s2,z1,z2,x1,x2,yudo_A=1,yudo_B=1;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;

    u1=170.8;
    s1=5.43;
    u2=169.7;
    s2=5.5;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);


        z1=(val-u1)/s1;
        z2=(val-u2)/s2;
        x1=p_stdnorm(z1);
        x2=p_stdnorm(z2);
        yudo_A=yudo_A*x1;
        yudo_B=yudo_B*x2;


    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",yudo_A);
    printf("L_B: %f\n",yudo_B);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

