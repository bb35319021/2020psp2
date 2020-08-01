#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


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
        ave=((i-1)*ave+val)/i;
        squared_ave=((i-1)*squared_ave+val*val)/i;

        samplevariance=squared_ave-ave*ave;
        
    }
    samplemean=ave;
    populationmean=samplemean;
    populationvariance=i*samplevariance/(i-1);
    std_err=pow(populationvariance/i,0.5);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
        }
    printf("sample mean=%.2lf\n",samplemean);
    printf("sample variance=%.2lf\n",samplevariance);
    printf("population mean=%.2lf, std_err=%.2lf\n",populationmean,std_err);
    printf("population variance=%.2lf\n", populationvariance);
        

    return 0;

}


