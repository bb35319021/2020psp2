#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

#define MU_A 170.8
#define MU_B 169.7
#define sigma_A 5.43
#define sigma_B 5.5
int main(void)
{
    double val,z1,z2,x1,x2,yudo_A=1,yudo_B=1;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    
   
    
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


        z1=(val-MU_A)/sigma_A;
        z2=(val-MU_B)/sigma_B;
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

