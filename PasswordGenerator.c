#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define BUFFER_SIZE 4096

void PasswordGenerator(int total, char *strings[])
{

    int count = 0;
    int nums[4];
    char password[total];
    for (int j = 1; j < 5; j++)
    {
        if (strings[j - 1][0] == 'y')
        {
            count = count + 1;
            nums[count - 1] = j;
        }
    }

    srand(time(0));
    // Array of NUmbers
    char numbers[] = "0123456789";

    // Array of small alphabets
    char letter[] = "abcdefghijklmnoqprstuvwyzx";

    // Array of capital alphabets
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

    // Array of all the special symbols
    char symbols[] = "!%$&\'()*\"+,-./:<=>?@[\\]^_`{|}~;";

    printf("\t \tYour Generated Password is:");
    printf("\033[1;31m");
    for (int k = 0; k < total; k++)
    {
        int random = nums[rand() % (count)];

        if (random == 1)
        {

            printf("%c", LETTER[rand() % 26]);
        }
        else if (random == 2)
        {
            
                printf("%c", letter[rand() % 26]);
        }
        else if (random == 3)
        {

            printf("%c", numbers[rand() % 10]);
        }
        else
        {

            printf("%c", symbols[rand() % 32]);
        }
    }
    printf("\033[0m");
    printf("\n");
    printf("Thank you!");
    printf("\n");
}

int main()
{

    char detail[4][50] = {
        "Do you want to include Capital Letter?",
        "Do you want to include Small Letter?",
        "Do you want to include Numbers?",
        "Do you want to include Special Symbols?"

    };
    char ErrorMsg[80]="Sorry wrong input !! Please enter y for Yes and n for No next time.";
    char **strings;
    int total = 0;
    printf("\n");
    printf("\033[1;31m");
    printf("\t \t Welcome To Strong Random Password Generator!!\n");
    printf("\033[0m");
    printf("\033[1;34m");
    printf("\t \t*********************************************** \n\n");
    printf("\033[0m");
    printf("\t \tEnter length of password to be generate(6-50): ");
    scanf("%d", &total);
    if (total >= 6 && total <= 50)
    {
        strings = malloc(total * sizeof(char *));
    }
    else
    {
        printf("\t \tSorry!! Length is out of scope,try between 6 and 50 next time. \n");
        return -1;
    }
    char buffer[BUFFER_SIZE];

    int length = 0;
    while (getchar() != '\n')
        ;

    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        char string[2];
        printf("\t \t----->%s(y|n): ", detail[i]);
        fgets(buffer, BUFFER_SIZE, stdin);
        length = strlen(buffer);
        if(length==2){
        if (buffer[0] == 'y' || buffer[0] == 'n')
        {
            printf("\n");
            sprintf(string, "%d", i + 1);

            
            buffer[length - 1] = '\0';
            strings[i] = malloc(length * sizeof(char));

            strcat(buffer, string);
            strcpy(strings[i], buffer);
        }
        else
        {
            printf("\t \t%s \n",ErrorMsg);
            return -1;
        }
        }
        else{
            printf("\t \t%s \n",ErrorMsg);
            return -1;
        }
    }
    PasswordGenerator(total, strings);

    return 0;
}
