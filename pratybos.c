#include <stdio.h>
#include <limits.h>

int main(){
    long long curr_num;
    int last_num;
    int negative=0, positive=0, zeros=0;
    int check_for_new=1;
    

    printf("Veskite sveikuosius skaicius iki pasikartojancio:\n");

    while(check_for_new){
        if((scanf("%12lld", &curr_num) == 1) && (getchar() == '\n')){
            if(curr_num>INT_MIN && curr_num<INT_MAX){
                printf("Skaicius tinka!\n");
                if(curr_num>0)
                    positive++;
                else if(curr_num<0)
                    negative++;
                else
                    zeros++;
                
                if(curr_num == last_num)
                    check_for_new = 0;
                
                last_num = curr_num;
            } else
                printf("Iveskite sveikaji skaiciu telpanti i INT!!\n");
        } else{

            printf("Iveskite sveikaji skaiciu telpanti i INT!!\n");
            scanf("%*[^\n]");
        }
    }

    printf("teigiami: %d\nneigiami: %d\nnuliai: %d\n", positive, negative, zeros);

}

