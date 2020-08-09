#include<stdio.h>
#include<math.h>
#include<cs50.h>
#include<string.h>
int count_words(char *Text);
int count_sentences(char *Text);
int count_letters(char *Text);
float coleman(float l,float s);
int main(void)
{
    float l, s;
    int W, L, S;

    string Text=get_string("Text:");
    W=count_words(Text);
    L= count_letters(Text);
    S=count_sentences(Text);
    l= (float)L /W *100;
    s= (float)S/W *100;
    int result=round(coleman(l,s));
    if(result<1)
    {
        printf("Before Grade 1\n");
    }
    else if(result>16)
    {
        printf("Grade 16+\n");
    }
    else
    {
    printf("Grade %d\n ",result);
    }
    return 0;
}
int count_words(char *Text)
{
    int w=1,i=0;    // the sentences always starts with a word
    while(Text[i]!='\0')
    {
        if(Text[i]==' '|| Text[i]=='\n')
        {
            w++;
        }
        i++;

    }
    return w;
}
int count_sentences(char *Text)
{
    int s=0,i=0;
    while(Text[i]!='\0')
    {
        if(Text[i]=='.'||Text[i]=='!'||Text[i]=='?')
        {
            s++;
        }
        i++;

    }
    return s;
}

int count_letters(char *text)
{
    int i=0,l=0;
    while(text[i]!='\0')
    {
        if((text[i]>='a'&&text[i]<='z')||(text[i]>='A'&&text[i]<='Z'))
        {
            {
                l++;
            }
        }
        i++;

    }
    return l;
}

float coleman (float l, float s)
{
    float index;
    index =( 0.0588 * l - 0.296 * s - 15.8);
    return index;
}