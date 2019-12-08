#include<stdio.h>
  void reverse(char s[]);
char s[100];
int c;
int i =0;
int main(){
   while ((s[i] = getchar()) != EOF&& s[i] != '\n' )
    i=i+1;
     reverse( s);
     printf("%s\n", s);
}
    void reverse(char  s[]){
        int temp;
     static int i=0;
        if (*s=='\0'){
            i=i-1;
            return;
        }
        else{
            i=i+1;
            reverse(s+1);
        }
        if (i>0)
        {
          temp=*s;
          *s=*(s-i);
          *(s-i)=temp;
          i=i-2;
        }
    }
