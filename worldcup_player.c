//2211 World Cup Management Project
//Author: Shahriar Siddique
//Date: 24-11-2022
//Version: 2.0

#include"worldcup_player.h"


//Database Design Start
struct PlayerDatabase
{
    int playerCode;
    char playerName[26];
    int playerAge;
    char playerClub[26];

    struct PlayerDatabase *next;
};

//Database Design End

//Player Database indexs

struct PlayerDatabase *Playerhead = NULL, *Playertemp = NULL, *Playercurrent = NULL;
//Player Database indexs




//Check Player code Start
bool check_PlayerCode(int tempPlayerCode)
{
   struct PlayerDatabase *tempvalue;
    tempvalue = Playerhead;
    while(tempvalue!=NULL)
    {
        if(tempvalue->playerCode == tempPlayerCode)
            return false;

            tempvalue = tempvalue->next;
    }

    return true;
}

//Check Player code End





// Insert Data Function Start
void insert_player_data()
{

    Playertemp = (struct PlayerDatabase *) malloc(sizeof(struct PlayerDatabase));     //Memory Allocate

    int tempPlayerCode;
    char tempPlayerName[100];
    int tempPlayerAge;
    char tempPlayerClub[100];

    printf("Enter Player code: ");
    scanf("%d",&tempPlayerCode);

    if(tempPlayerCode < 0)
    {
        printf("Invalid TeamCode.\n\n");
        return;
    }


//Check Player code Avaible or not
//True = Avaible and False = Not Avaible , Already Used;
    bool check_code = check_PlayerCode(tempPlayerCode);

    if(check_code == false)
    {
        printf("Your Given Player code is already used.\n");
        return;
    }
                                      


  
        printf("Enter Player name: ");
        getchar();
        scanf(" %[^\n]%*c",&tempPlayerName);




        printf("Enter Player Age: ");
        scanf("%d",&tempPlayerAge);

        if(tempPlayerAge < 17 || tempPlayerAge > 99)
        {
            printf("Your Input age is invalid.\n");
            
            return;
        }



//Enter Player Club


        printf("Enter Player Club: ");
        getchar();
        scanf(" %[^\n]%*c",&tempPlayerClub);

//Player Club end


// Data Insert
Playertemp->playerCode = tempPlayerCode;  
  int len1 = strlen(tempPlayerName);

    for(int i = 0; i<len1 ; i++)
    {
        if(i == 24)
        break;

        Playertemp->playerName[i] = tempPlayerName[i];
    }
Playertemp->playerAge = tempPlayerAge;
int len2 = strlen(tempPlayerClub);

    for(int i = 0; i<len2 ; i++)
    {
            if(i == 24)
            break;

        Playertemp->playerClub[i] = tempPlayerClub[i];
    }




if(Playerhead == NULL)
{
    Playerhead = Playertemp;
    Playercurrent = Playertemp;
    return;
}
else
{
    Playercurrent->next = Playertemp;
    Playercurrent = Playercurrent->next;
    return;

}




}

//Insert Data Function End



//Search Player function Start

void search_player_data()
{
    int number;
    char options;

    while(1)
    {

        printf("Enter Player Code: ");
        scanf("%d",&number);

        if(number < 0)
        {
            printf("Invalid Player Code, Try Again.......\n\n");
            search_player_data();
        }


        struct PlayerDatabase *temphead;
        temphead = Playerhead;

        while(temphead != NULL)
        {
            if(temphead->playerCode == number)
            {
                printf("\n\nPlayer Code   Player Name               Player Age              Player Club\n");
                printf("%d            %s                   %d          %s\n",temphead->playerCode, temphead->playerName, temphead->playerAge, temphead->playerClub);

                return ;
            }

                temphead = temphead->next;
        }

        printf("Player Not Found in Database.\n\n");
        printf("Try Again? (Yes = Y, No = N)\n");

        scanf(" %c",&options);
        if(options == 'Y' || options == 'y')
            continue;
        else
            return ;

    }

}

//Search Player function End


//Update Player Data Function start

void update_player_data()
{

    int playerCode;


    printf("Enter Player Code: ");
    scanf("%d",&playerCode);

    struct PlayerDatabase *temphead;
    temphead = Playerhead;

    while(temphead!= NULL)
    {
        if(temphead->playerCode == playerCode)
        {

            int tempPlayerCode;
            char tempPlayerName[100];
            int tempAge;
            char tempClub[26];




            while(1)
            {
                printf("Enter Updated Player name: ");
                getchar();
                 scanf("%[^\n]%*c",tempPlayerName);

                if(strcmp(tempPlayerName,"")==0)
                {
                    printf("You did not Enter Updated Player name.\n");
                }
                else
                    break;
            }


            strcpy(temphead->playerName, tempPlayerName);





            while(1)
            {
                printf("Enter the Updated Player Age: ");
                scanf("%d",&tempAge);

                if(tempAge >=17 && tempAge <= 99)
                {
                    temphead->playerAge = tempAge;
                    break;
                }
                else
                {
                    printf("Your Given Age is out of range.\n");
                    printf("Try Again....\n");
                    continue;
                }

            }



            while(1)
                {
                    printf("Enter Updated Player Club: ");
                    getchar();
                    scanf("%[^\n]%*c",&tempClub);


                    if(strlen(tempClub)==0)
                    {
                        printf("You did not Enter Player Club.\n");
                    }
                    else if(strlen(tempClub)>25)
                    {
                        printf("Your Player club name length is Out of Range.\n");
                        printf("Try Again......\n");
                    }
                    else
                        break;
                }




    int len1 = strlen(tempClub);

    for(int i = 0; i<len1 ; i++)
    {
        temphead->playerClub[i] = tempClub[i];
    }



        }

    temphead = temphead->next;

    }


    return;

}


//Update Player Data Function End


//Show Data function start


void show_player_data()
{
    printf("\n\nPlayer Code   Player Name             Player Age            Player Club\n");

    struct PlayerDatabase *tempHead;
    tempHead = Playerhead;
    
    while(tempHead != NULL)
    {
        printf("%d            %s                     %d                     %s\n",tempHead->playerCode, tempHead->playerName,tempHead->playerAge, tempHead->playerClub);

    tempHead = tempHead->next;

    }
    return ;
}


//Show Player Data function End



//Delete Player Function working start

void delete_player_data()
{
int tempPlayerCode;
printf("Enter your Player code to delete \n\n");
scanf("%d",&tempPlayerCode);


struct PlayerDatabase *temp = Playerhead, *prev;
 
    if (temp != NULL && temp->playerCode == tempPlayerCode) {
        Playerhead = temp->next; 
        free(temp); 
        printf("Delete Player Successfully.\n\n");
        return;
    }
 

    while (temp != NULL && temp->playerCode != tempPlayerCode) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Player Code not found in database.\n\n"); 
        return;
    }

    prev->next = temp->next;
 
    free(temp);

    return;
}



//Delete Player Function working end



void worldcup_player()
{
//Homescreen Design Start
    printf("******************\n");
    printf("*World Cup Player*\n");
    printf("******************\n");
    printf("\n\n\n");
//Homescreen Design End


    char input;

    printf("Enter operation code: ");

    while(scanf(" %c",&input))
    {

        if(input == 'i')
            insert_player_data();
       else if(input == 's')
            search_player_data();
       else if(input == 'u')
            update_player_data();
        else if(input == 'p')
            show_player_data();
        else if(input == 'd')
            delete_player_data();
        else if(input == 'q')
            {
                printf("Exit From Player Menu");
                return;
            }

        printf("\n\n\n");

//Homescreen Design Start
    printf("******************\n");
    printf("*World Cup Player*\n");
    printf("******************\n");
    printf("\n\n\n");
//Homescreen Design End



        printf("Enter operation code: ");
    }



    return;
}
