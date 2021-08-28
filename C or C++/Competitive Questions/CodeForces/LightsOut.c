#include<stdio.h>

int change_val(int a) //changes value from 0 to 1 and vice versa
{
    if (a==1)
        return 0;
    else    
        return 1;
}

int main()
{ 
    int i,j,a[3][3], b[3][3];
    /* 1 1 1 
       1 1 1   Original Matrix
       1 1 1 */     
    for (i=0;i<3;i++)   //inputting 2d matrix      
        for (j=0;j<3;j++)
            {
                scanf("%d",&a[i][j]); //inputs the matrix 
                a[i][j] = (a[i][j]%2);  //makes the input either 1 or 0 (all others are just a waste of iterations)
                b[i][j] = 1; //makes all elements of the matrix 1 (ie, switched on)
            }
            
    for (i=0;i<3;i++) 
        for(j=0;j<3;j++)   
        {
            while(a[i][j]--)
            {
                b[i][j]= change_val(b[i][j]);   //self 
                
                if(i<2) 
                    b[i+1][j] = change_val(b[i+1][j]); //Number below selected 
                
                if (j<2) //Number on right of selected
                    b[i][j+1] = change_val(b[i][j+1]);
                
                if(i>0) //Number above selected
                    b[i-1][j] = change_val(b[i-1][j]);
                
                if (j>0) //Number of left of selected
                    b[i][j-1] = change_val(b[i][j-1]);  
            }
        }
    
    for (i=0;i<3;i++) //prints the answer
    {
        for(j=0;j<3;j++)
            printf("%d",b[i][j]);
        printf("\n");
    }
}