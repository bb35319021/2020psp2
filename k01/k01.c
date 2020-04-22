#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int i)
{return ((i-1)*ave)/i + val/i;}
extern double var_online(double val, double save,int i)
{return (((i-1)*save)i+pow(val,2)/i)-pow(((i-1)*ave/i)+(val/i));}

int main(void)
{
    double val,ave,var,save;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
int i;
i=0;

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
        i++;
        ave=ave_online(val,ave,i);
        var=var_onlaine(val,ave,save,i);


save=var_online(save,pow(val,2),i);

    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
printf("ave=%1f\n",ave);
printf("var=%1f\n",var);

    


    return 0;


}

