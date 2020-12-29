#include<stdio.h>
int sq[50][50],n,i,j,count=0,value,sum;
void filldown()
{
    if(i==n-1)
    {
        sq[0][j]=++value;
        count++;
        i=0;
    }
    else
    {
        sq[i+1][j]=++value;
        count++;
        i=i+1;
    }
}
int free1(int i,int j)
{
        if(sq[i][j]==0)
            return 1;
        else
            return 0;
}
void generate()
{
    i=0,j=n/2,value=1;
    sq[i][j]=value;
    count=1;
    while(count!=n*n)
    {
        if((i!=0)&&(j!=(n-1)))
        {
            if(free1(i-1,j+1))
            {
                sq[i-1][j+1]=++value;
                count++;
                i=i-1,j=j+1;
            }
            else
            {
                filldown();
            }
        }
        else
        {
           if((i-1)<0&&(j+1)==n)
           {
               if(free1(n-1,0))
               {
                   sq[n-1][0]=++value;
                   count++;
                   i=n-1,j=0;
               }
               else
               {
                   filldown();
               }
           }
           else if((i-1)<0&&(j+1)>0&&(j+1)<=n)
           {
               if(free1(n-1,j+1))
               {
                   sq[n-1][j+1]=++value;
                   count++;
                   i=n-1,j=j+1;
               }
               else
               {
                   filldown();
               }
           }
           else
           {
               if(free1(i-1,0))
               {
                   sq[i-1][0]=++value;
                   count++;
                   i=i-1,j=0;
               }
               else
               {
                   filldown();
               }
           }
        }
    }
}
int main()
{

   printf("Enter the size (odd) of the magic square :  ");
   scanf("%d",&n);

   generate();

   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           printf("%d\t",sq[i][j]);
       }
       printf("\n");
   }
   for(i=0;i<n;i++)
    sum+=sq[0][i];
   printf("\nSum across any line : %d ",sum);
   return 0;
}
=======
#include<stdio.h>
int sq[50][50],n,i,j,count=0,value,sum;
void filldown()
{
    if(i==n-1)
    {
        sq[0][j]=++value;
        count++;
        i=0;
    }
    else
    {
        sq[i+1][j]=++value;
        count++;
        i=i+1;
    }
}
int free(int i,int j)
{
        if(sq[i][j]==0)
            return 1;
        else
            return 0;
}
void generate()
{
    i=0,j=n/2,value=1;
    sq[i][j]=value;
    count=1;
    while(count!=n*n)
    {
        if((i!=0)&&(j!=(n-1)))
        {
            if(free(i-1,j+1))
            {
                sq[i-1][j+1]=++value;
                count++;
                i=i-1,j=j+1;
            }
            else
            {
                filldown();
            }
        }
        else
        {
           if((i-1)<0&&(j+1)==n)
           {
               if(free(n-1,0))
               {
                   sq[n-1][0]=++value;
                   count++;
                   i=n-1,j=0;
               }
               else
               {
                   filldown();
               }
           }
           else if((i-1)<0&&(j+1)>0&&(j+1)<=n)
           {
               if(free(n-1,j+1))
               {
                   sq[n-1][j+1]=++value;
                   count++;
                   i=n-1,j=j+1;
               }
               else
               {
                   filldown();
               }
           }
           else
           {
               if(free(i-1,0))
               {
                   sq[i-1][0]=++value;
                   count++;
                   i=i-1,j=0;
               }
               else
               {
                   filldown();
               }
           }
        }
    }
}
int main()
{

   printf("Enter the size (odd) of the magic square :  ");
   scanf("%d",&n);

   generate();

   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           printf("%d\t",sq[i][j]);
       }
       printf("\n");
   }
   for(i=0;i<n;i++)
    sum+=sq[0][i];
   printf("\nSum across any line : %d ",sum);
   return 0;
}
