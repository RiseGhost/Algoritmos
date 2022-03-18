#include<stdio.h>
double s(double n);


double soma(double k, double n){
    if(k == n - 2){
        return s(k) * s(n-k-1);
    }   else{
        return s(k)*s(n-k-1) + soma(k + 1, n);
    }
}

double s(double n){
    if(n == 0){
        return 1;
    }   if(n == 1){
        return 2;
    }   if(n == 2){
        return 6;
    }   else{
        return 3*s(n-1) + soma(1, n);
    }
}

double s2(double n){
    if (n == 0)
    {
        return 1;
    }else{
        if (n == 1)
        {
            return 2;
        }else{
            return (((6 * (n-2) + 9) / (n + 1)) * s2(n - 1)) - (((n - 2) / (n + 1)) * s2(n - 2));
        }    
    }   
}

int main(void){
    for (int i = 0; i <= 25; i++)
    {
        printf("S1 %i -> %.0f\n", i,s(i));
        printf("S2 %i -> %.0f\n", i, s2(i));
    }
}