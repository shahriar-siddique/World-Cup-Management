#include"worldCupDB.h"



void help()
{

printf("Enter 'h' for help menu.\n");
printf("Enter 'q' if you want to quit this program. All your Data will be lost\n");
printf("Enter 't' for go to World cup team section\n");
printf("Enter 'p' for go to World cup player section\n\n\n");
}




int main()
{

//Homescreen Design Start
    printf("************************\n");
    printf("*  World Cup Database  *\n");
    printf("************************\n");
    printf("\n\n\n");
//Homescreen Design End


    char input;

    printf("Enter operation code: ");

    while(scanf(" %c",&input))
    {

        if(input == 'h')
            help();
       else if(input == 'q')
       {
        printf("Program Exit Successfully\n");
        return 0;
       }
       else if(input == 'p')
            worldcup_player();
        else if(input == 't')
            worldcup_team();
   
    printf("\n\n\n");

//Homescreen Design Start
    printf("************************\n");
    printf("*  World Cup Database  *\n");
    printf("************************\n");
    printf("\n\n\n");
//Homescreen Design End



       
        printf("Enter operation code: ");
    }




    return 0;



}
