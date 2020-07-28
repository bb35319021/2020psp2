#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int i)
{
    ave=((i-1)*ave+val)/i;
return ave;
}
extern double var_online(int i,double val,double squared_ave,double ave)
{
    return ((i-1)*squared_ave+val*val)/i-pow((((i-1)*ave+val)/i),2);
}

int main(void)
{
    double val,ave=0,std_err,samplemean,samplevariance,populationmean,populationvariance,squared_ave=0;
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
        samplevariance=var_online(i,val,squared_ave,ave);
        squared_ave=((i-1)*squared_ave+val*val)/i;
        

    samplemean=ave;

    populationvariance=i*samplevariance/(i-1);
    populationmean=samplemean;

    std_err=pow(populationvariance/i,0.5);



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
        }
    printf("sample mean=%.2lf\n",samplemean);
    printf("sample variance=%.2lf\n",samplevariance);
    printf("population mean=%.2lf, pm=%.2lf\n",populationmean,std_err);
    printf("population variance=%.2lf\n", populationvariance);
        

    return 0;


}

