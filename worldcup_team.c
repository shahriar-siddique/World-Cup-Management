//2211 World Cup Management Project
//Author: Shahriar Siddique
//Date: 24-11-2022
//Version: 2.0


#include"worldcup_team.h"


//Database Design Start
struct TeamDatabase
{
    int teamCode;
    char teamName[26];
    char groupSeed1;
    char groupSeed2;
    char teamColor;

    struct TeamDatabase *next;
};

//Database Design End

//Team Database indexs

struct TeamDatabase *head = NULL, *temp = NULL, *current = NULL;
//Team Database indexs






//Check Team code Start
bool check_TeamCode(int tempTeamCode)
{
   struct TeamDatabase *tempvalue;
    tempvalue = head;
    while(tempvalue!=NULL)
    {
        if(tempvalue->teamCode == tempTeamCode)
            return false;

            tempvalue = tempvalue->next;
    }

    return true;
}

//Check Team code End

//Check Team Name Start

bool check_TeamName(char tempTeamName[100])
{
    struct TeamDatabase *tempvalue;
    tempvalue = head;

    while(tempvalue != NULL)
    {
        if(strcmp(tempvalue->teamName,tempTeamName)==0)
            return true;

        tempvalue = tempvalue->next;
    }

    return false;
}





// Insert Data Function Start
void insert_data()
{

    temp = (struct TeamDatabase *)malloc(sizeof(struct TeamDatabase));     //Memory Allocate

    int tempTeamCode;
    char tempTeamName[100];
    char tempGroupSeed1,tempGroupSeed2;
    char tempColor;

    printf("Enter team code: ");
    scanf("%d",&tempTeamCode);

    if(tempTeamCode < 0)
    {
        printf("Invalid TeamCode , Try Again.....\n\n");
        insert_data();
    }


//Check Team code Avaible or not
//True = Avaible and False = Not Avaible , Already Used;
    bool check_code = check_TeamCode(tempTeamCode);

    if(check_code == false)
    {
        printf("Your Given Team code is already in Used by Another Team.\n");
        printf("Please Try Again..........\n");
        return ;
    }
    else
        temp->teamCode = tempTeamCode;                                 //team code in not added in database


    while(1)
    {
        printf("Enter team name: ");
        getchar();
        scanf("%[^\n]%*c",tempTeamName);


        if(strlen(tempTeamName)==0)
        {
            printf("You did not Enter Team name.\n");
        }
        else if(strlen(tempTeamName)>25)
        {
            printf("Your Team name length is Out of Range.\n");
        }
        else
            break;
    }

//check if teamname is Used
    while(1)
    {
        bool isUsedName = check_TeamName(tempTeamName);
        if(isUsedName == true)
        {
            printf("This Name is Already on Database. Try Anoter one.\n");
            printf("Enter team name: ");
             scanf("%[^\n]%*c",tempTeamName);
        }
        else
            break;

    }



    int len1 = strlen(tempTeamName);

    for(int i = 0; i<len1 ; i++)
    {

        temp->teamName[i] = tempTeamName[i];
    }


    while(1)
    {

        printf("Enter group seeding: ");
        scanf(" %c %c",&tempGroupSeed1,&tempGroupSeed2);

        if(tempGroupSeed1 < 'A' || tempGroupSeed1 > 'H')
        {
            printf("Your Input value is out of range.\n");
            printf("Please Try Again\n");
            continue;
        }
        if(tempGroupSeed2< '1' || tempGroupSeed2 > '4')
        {
            printf("Your Input value is out of range.\n");
            printf("Please Try Again\n");
            continue;
        }

        break;
    }

    temp->groupSeed1 = tempGroupSeed1;
    temp->groupSeed2 = tempGroupSeed2;


    while(1)
    {
        printf("Enter the kit colour: ");
        scanf(" %c",&tempColor);

        if(tempColor == 'R' || tempColor == 'O' || tempColor == 'Y' || tempColor == 'G' || tempColor == 'B' || tempColor == 'I' || tempColor == 'V')
        {
            temp->teamColor = tempColor;
            break;
        }
        else
        {
            printf("Your Input is out of range.\n");
            printf("Try Again....\n");
            continue;
        }

    }


if(head == NULL)
{
    head = temp;
    current = temp;
}
else
{
    current->next = temp;
    current = current->next;
}


return;

}

//Insert Data Function End



//Search Team function Start

void search_team()
{
    int number;
    char options;

    while(1)
    {

        printf("Enter Team Number: ");
        scanf("%d",&number);

        if(number < 0)
        {
            printf("Invalid Team Number, Try Again.......\n\n");
            search_team();
        }


        struct TeamDatabase *temphead;
        temphead = head;

        while(temphead != NULL)
        {
            if(temphead->teamCode == number)
            {
                printf("\n\nTeam Code   Team Name                 Group Seeding               Primary Kit Colour\n");
                printf("%d            %s                        %c%c                             %c\n",temphead->teamCode, temphead->teamName, temphead->groupSeed1, temphead->groupSeed2, temphead->teamColor);

                return ;
            }

                temphead = temphead->next;
        }

        printf("Team Not Found in Database.\n\n");
        printf("Try Again? (Yes = Y, No = N)\n");

        scanf(" %c",&options);
        if(options == 'Y' || options == 'y')
            continue;
        else
            return ;

    }

}

//Search Team function End


//Update Data Function start

void update_data()
{

    int teamCode;


    printf("Enter Team Code: ");
    scanf("%d",&teamCode);

    struct TeamDatabase *temphead;
    temphead = head;

    while(temphead!= NULL)
    {
        if(temphead->teamCode == teamCode)
        {

            int tempTeamCode;
            char tempTeamName[100];
            char tempGroupSeed1,tempGroupSeed2;
            char tempColor;




            while(1)
            {
                printf("Enter Updated team name: ");
                getchar();
                 scanf("%[^\n]%*c",tempTeamName);

                if(strcmp(tempTeamName,"")==0)
                {
                    printf("You did not Enter Updated Team name.\n");
                }
                else
                    break;
            }

//check if teamname is Used
            while(1)
            {
                bool isUsedName = check_TeamName(tempTeamName);
                if(isUsedName == true)
                {
                    printf("This Name is Already on Database. Try Anoter one.\n");
                    printf("Enter Updated team name: ");
                    scanf("%[^\n]%*c",tempTeamName);
                }
                else
                    break;

            }

            strcpy(temphead->teamName, tempTeamName);



            while(1)
            {

                printf("Enter Updated Group Seed: ");
                scanf(" %c %c",&tempGroupSeed1,&tempGroupSeed2);

                if(tempGroupSeed1 < 'A' || tempGroupSeed1 > 'H')
                {
                    printf("Your Input value is out of range.\n");
                    printf("Please Try Again\n");
                    continue;
                }
                if(tempGroupSeed2< '1' || tempGroupSeed2 > '4')
                {
                    printf("Your Input value is out of range.\n");
                    printf("Please Try Again\n");
                    continue;
                }

                break;
            }

            temphead->groupSeed1 = tempGroupSeed1;
            temphead->groupSeed2 = tempGroupSeed2;


            while(1)
            {
                printf("Enter the Updated kit colour: ");
                scanf(" %c",&tempColor);

                if(tempColor == 'R' || tempColor == 'O' || tempColor == 'Y' || tempColor == 'G' || tempColor == 'B' || tempColor == 'I' || tempColor == 'V')
                {
                    temphead->teamColor = tempColor;
                    break;
                }
                else
                {
                    printf("Your Input is out of range.\n");
                    printf("Try Again....\n");
                    continue;
                }

            }




        }

    temphead = temphead->next;

    }


    return ;

}


//Update Data Function End


//Show Data function start


void show_data()
{
    printf("\n\nTeam Code   Team Name                 Group Seeding               Primary Kit Colour\n");

    struct TeamDatabase *tempHead;
    tempHead = head;
    
    while(tempHead != NULL)
    {
        printf("%d            %s                        %c%c                             %c\n",tempHead->teamCode, tempHead->teamName, tempHead->groupSeed1, tempHead->groupSeed2, tempHead->teamColor);

    tempHead = tempHead->next;
    }
    return ;
}


//Show Data function End



//Delete Team Function working start

void delete_team()
{
int tempteamcode;
printf("Enter your team code to delete \n\n");
scanf("%d",&tempteamcode);


struct TeamDatabase *temp = head, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->teamCode == tempteamcode) {
        head = temp->next; // Changed head
        free(temp); // free old head
        printf("Delete Team Successfully.\n\n");
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->teamCode != tempteamcode) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
    {
        printf("Team Code not found in database.\n\n"); 
        return;
    }
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp); // Free memory

    return;
}



//Delete Team Function working end

















void worldcup_team()
{
//Homescreen Design Start
    printf("******************\n");
    printf("* World Cup Team *\n");
    printf("******************\n");
    printf("\n\n\n");
//Homescreen Design End


    char input;

    printf("Enter operation code: ");

    while(scanf(" %c",&input))
    {

        if(input == 'i')
            insert_data();
       else if(input == 's')
            search_team();
       else if(input == 'u')
            update_data();
        else if(input == 'p')
            show_data();
        else if(input == 'd')
            delete_team();
        else if(input == 'q')
            {
                printf("Exit From Team Menu");
                return;
            }


        printf("\n\n\n");

//Homescreen Design Start
    printf("******************\n");
    printf("* World Cup Team *\n");
    printf("******************\n");
    printf("\n\n\n");
//Homescreen Design End

        printf("Enter operation code: ");
    }



    return;
}
