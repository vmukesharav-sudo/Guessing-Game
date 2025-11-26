#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void Survival_Mode();
void Timer_Mode();
void Check_rand_numb(int rand_numb,int attempt);
void Check_rand_numb_timer(int rand_numb,int time_limit);
int Check_input_int();
char Check_input_yn();

 
//main function

int main(){             //main function
    srand(time(NULL));
    printf("\t--------Welcome To Number Guessing Game--------\t\n");
    char loop_1;
    do{
        char loop_2;
        printf("\n\t[1] Survival Mode.\n\t[2] Timer Mode.\n\t[3] Exit.\n\n");
        printf("Enter your choice : ");
        int choice_1=Check_input_int();
        switch(choice_1){
            case 1:{
                do{
                    Survival_Mode();
                    printf("\nDo you want to continue the Survival Mode Enter (y) or Enter (n) :");
                    loop_2=Check_input_yn();
                    if(loop_2 == 'y' || loop_2 == 'Y') continue;
                    else if(loop_2 == 'n' || loop_2 == 'N') break;
                }while(1);
                break;
            }case 2:{
                do{
                    Timer_Mode();
                    printf("\nDo you want to continue the Timer Mode Enter (y) or Enter (n) :");
                    loop_2=Check_input_yn();
                    if(loop_2 == 'y' || loop_2 == 'Y') continue;
                    else if(loop_2 == 'n' || loop_2 == 'N') break;
                }while(1);
                break;
            }case 3:{
                printf("Exiting the GAME.......\n");
                break;
            }default:
                printf("\n\t...Invalid Entry...\n");
        }
        printf("\nDo you want to continue the GAME Enter (y) or Enter (n) :");
        loop_1=Check_input_yn();
        if(loop_1 == 'y' || loop_1 == 'Y') continue;
        else if(loop_1 == 'n' || loop_1 == 'N'){ 
            printf("\nPress Enter to Exit Completely....");
            getchar();
            getchar();
            break;
        }
    }while(1);
}

//Input function checks the given input is correct or not

int Check_input_int(){
    int number;
    while(1){
        if((scanf("%d",&number)==1)){   //here i gava like ==1 because if scaf gets int as a input means it returns 1.
            return number;              //for char scanf return 0.
        }else{
            printf("\nEnter VALID input : ");
            while(getchar()!='\n');     //remove the invalid input
        }
    }
}

//Input function checks the give input is y or n or other

char Check_input_yn() {
    char ch;
    while (1) {
        if (scanf(" %c", &ch) == 1) {  
            if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N') return ch;
            else printf("\nEnter VALID input (y/n): ");
        } else printf("\nEnter VALID input (y/n): ");
        while (getchar() != '\n');  
    }
}

//function 1

void Survival_Mode(){                //Survival mode function
    printf("\n\t--------You are in Survival Mode--------\t\n");
    printf("\t[1] Easy (1-40).\n\t[2] Medium (1-400).\n\t[3] Hard (1-4000).\n\t[4] Impossible(Mystry Round) (1-32767).\n\t[5] Exit.\n\n");
    printf("Enter your choice : ");
    int choice_2=Check_input_int();
    switch(choice_2){
        case 1:{
            int rand_numb_easy=(rand()%40)+1;
            int attempt_easy=10;
            Check_rand_numb(rand_numb_easy,attempt_easy);
            break;
        }case 2:{
            int rand_numb_medium=(rand()%400)+1;
            int attempt_medium=8;
            Check_rand_numb(rand_numb_medium,attempt_medium);
            break;
        }case 3:{
            int rand_numb_hard=(rand()%4000)+1;
            int attempt_hard=6;
            Check_rand_numb(rand_numb_hard,attempt_hard);
            break;
        }case 4:{
            int rand_numb_imp=(rand()%(32767))+1;
            int attempt_imp=4;
            Check_rand_numb(rand_numb_imp,attempt_imp);
            break;
        }case 5:{
            printf("Exiting the Survival Mode.......\n");
            break;
        }
    }
}

//function 2

void Timer_Mode(){               //Timer mode function
    printf("\n\t--------You are in Timer Mode--------\t\n");
    printf("\t[1] Easy (1-40).\n\t[2] Medium (1-400).\n\t[3] Hard (1-4000).\n\t[4] Impossible(Mystry Round) (1-32767).\n\t[5] Exit.\n\n");
    printf("Enter your choice : ");
    int choice_2=Check_input_int();
    switch(choice_2){
        case 1:{
            int rand_numb_easy=(rand()%40)+1;
            int time_easy=240;
            printf("\n\t----Your Time Limit is %d ----\t\n",time_easy);
            Check_rand_numb_timer(rand_numb_easy,time_easy);
            break;
        }case 2:{
            int rand_numb_medium=(rand()%400)+1;
            int time_medium=180;
            printf("\n\t----Your Time Limit is %d ----\t\n",time_medium);
            Check_rand_numb_timer(rand_numb_medium,time_medium);
            break;
        }case 3:{
            int rand_numb_hard=(rand()%4000)+1;
            int time_hard=120;
            printf("\n\t----Your Time Limit is %d ----\t\n",time_hard);
            Check_rand_numb_timer(rand_numb_hard,time_hard);
            break;
        }case 4:{
            int rand_numb_imp=rand()%(32767)+1;
            int time_imp=60;
            printf("\n\t----Your Time Limit is %d ----\t\n",time_imp);
            Check_rand_numb_timer(rand_numb_imp,time_imp);
            break;
        }case 5:{
            printf("Exiting the Timer Mode.......\n");
            break;
        }
    }
}

//function 3

void Check_rand_numb(int rand_numb,int attempt){             //it will check for Survival mode
    int user_numb;
    int s_a=attempt;
    while(attempt>0){    
        printf("\n--------ONLY %d ATTEMPTS--------\n",attempt);
        printf("Enter your guess : ");
        user_numb=Check_input_int();
        if(user_numb>rand_numb){
            printf("\n ....HIGH....\n");
        }else if(user_numb<rand_numb){printf("\n ....LOW....\n");
        }else {
            printf("\n*Excellent, You Nailed it\n");
            printf("YOUR SCORE : %d / %d\n",attempt,s_a);
            return;
        }attempt--;
    }
    printf("\nYOU LOSE...\n");
    printf("\n\t----The Answer is %d ----",rand_numb);
}

//function 4

void Check_rand_numb_timer(int rand_numb,int time_limit){                //it will check for Timer mode
    int user_numb;
    time_t start=time(NULL);
    while(1){
        time_t cur=time(NULL);
        double on_time=difftime(cur,start);
        if(on_time>=time_limit){
            printf("\n\t--------Times Up : You took too long--------\t\n");
            printf("\n\t--------    You LOSE    --------\t\n");
            printf("\n\t----The Answer is %d ----\t\n",rand_numb);
            break;
        }
        printf("Enter your guess : ");
        user_numb=Check_input_int();
        if(user_numb>rand_numb){
            printf("\n ....HIGH....\n");
        }else if(user_numb<rand_numb){printf("\n ....LOW....\n");
        }else {
            printf("\n*Excellent, You Nailed it\n");
            printf("Time Taken : %.4lf",difftime(time(NULL),start));
            break;
        }
    }
}