#include<stdio.h>
#include<string.h>
int main()
{
        char    b[50];
        char    str[500];
        int     no_of_char_printed = 0;
        int     i, m, count, a, len;
 
    // Get the input string that is to be reversed
    printf("String : ");
    gets(str);
 
    len = strlen(str);
    i = (len-1);
    
    printf("\nReversed string : ");

    while (no_of_char_printed<=len) {

        m=0;
        
        while(str[i]!=' ')
        {
            b[m++]=str[i--];

            if(i == -1) {
                
                break;
            }
        }
     
        a = m-1;
     
        while(a>=0)
        {
            printf("%c",b[a--]);
            no_of_char_printed++;
        }
      
        printf("%c",' ');
        
        no_of_char_printed++;
        i--;
    }

    printf("\n\n");
    
    return 0;
}
