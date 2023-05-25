#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);//scan number of routers
    int A[N][N];//declare array to keep track of cost
    int path[N][N];
    for (int i=0;i<N;i++){
        for (int a=0;a<N;a++){
            path[i][a]==0;//intialize all to 0
        }
    }
    
    for (int i=0;i<N;i++){
        for (int a=0;a<N;a++){
            scanf("%d",&A[i][a]);//scan distances
        }
    }
    for (int i=0;i<N;i++){
        for (int a=0;a<N;a++){
           for(int k=0;k<N;k++){
               if(A[i][k]+A[k][a]<A[i][a]){
                   A[i][a]=A[i][k]+A[k][a];//update if shorter path available
                   path[i][a]=k+1;//keep track of the router used for the shortest path
               }
           }
        }
    }
    for (int i=0;i<N;i++){
        for (int a=0;a<N;a++){
            if(path[i][a]==0){
                path[i][a]=a+1;//if there is no shorter path use the direct path
            }
        }
    }
    for (int i=0;i<N;i++){
        printf("Router %d",i+1);
        printf("\n");
        for (int a=0;a<N;a++){
            printf("Router %d ",a+1);
            printf("Via %d with cost ",path[i][a]);//print the shortest path that the packet takes to reach router a
            printf("%d",A[i][a]);//print all distances
            printf(" ");
            printf("\n");
        }
        printf("\n");
    }
}