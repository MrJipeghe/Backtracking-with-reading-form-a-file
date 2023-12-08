#include <stdio.h>
#include <stdlib.h>
#define size 3
#define size_vector 6






x[size]={0};
void solutie(int x[])
{
    for(int i=1;i<=size;++i)
        printf("%d ",x[i]);
    printf("\n");
}
int conditie(int  numar,int k)
{
    for(int i=0;i<k;++i)
        if(numar<=x[i])
            return 0;
    return 1;
}


void backtracking(int k,int v[])
{

    for(int i=0;i<size_vector;++i)
    {
        x[k]=v[i];
        if(conditie(v[i],k))
        {
            if(k<size)
                backtracking(k+1,v);
            else solutie(x);
        }
    }




}


int main()
{
    FILE *f = fopen("fisier.txt", "r");

    if (!f)
    {
        printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
        return -1;
    }

    int v[size_vector];
    for(int i=0;i<size_vector;++i)
    {
        fscanf(f, "%d", &v[i]);
    }

    printf("\n");



    backtracking(1,v);


}
