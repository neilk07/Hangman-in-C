/*I have taken the inspiration for the design part from a youtube video linked below:
"https://youtu.be/afBUqeSeb-I"
The file that takes the words as input for the program is also attached in the folder.*/

#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#include<stdio.h>
#include<string.h>

int main()
{
    //start screen
    printf("\n   ---HANGMAN---   \n");
    printf("Brought to you by BS-BAP!\n");
    printf("_____________   \n");
    printf("|        |      \n");
    printf("|        O      \n");
    printf("|        |      \n");
    printf("|      / | \\   \n");
    printf("|     /  |  \\  \n");
    printf("|      /   \\   \n");
    printf("|     /     \\  \n");
    printf("|               \n");
    printf("|_______________\n");
    printf("\n");
    printf("To Start The Game; Press Any Key & Enter!\n");
    char start = getchar();

    //Game Start & Variables Used!
    int tries = 6;
    char guess;
    bool correctGuess = false;
    char previousGuesses[7];
    for (int i = 0; i < 6; i++)
    {
        previousGuesses[i] = '-';
    }
    previousGuesses[6] = '\0';

    char wordList[100][100];
    int randomWord;
    srand(time(NULL));
    FILE *words = fopen("Words.txt", "r");
    if (words == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    int i = 0;
    while (fscanf(words, "%s", wordList[i]) != EOF)
    {
        i++;
    }
    fclose(words);

    randomWord = rand() % i;
    char word[100];
    strcpy(word, wordList[randomWord]);
    char mysteryWord[100];
    for (int i = 0; i < strlen(word); i++)
    {
        mysteryWord[i] = '*';
    }
    mysteryWord[strlen(word)] = '\0';

    while (tries >= 0)
    {
        //reset the bool here
        correctGuess = false;

        //information for the player related to the word here;
        printf("The Word You Have To Guess is :\n\n");
        printf("%s\n", mysteryWord);
        printf("There are %d letters in the Word\n", strlen(mysteryWord));
        printf("You have %d guess left!\n", tries);
        if (previousGuesses[0] == '-')
        {
            printf("\n");
        }
        else
        {
            printf("You have guessed : '%s'\n", previousGuesses);
        }

        //fetching the guess
        printf("\n\nGuess A Letter : \n");
        scanf(" %c", &guess);

        //checking the guess
        for (int i = 0; i < strlen(word); i++)
        {
            if (word[i] == guess){
                mysteryWord[i] = guess;
                correctGuess = true;
            }
        }
        if(strcmp(word, mysteryWord) == 0){
            printf("Congratulations! You've Guessed The word '%s' Correctly\n", mysteryWord);
            break;
        }

        if(correctGuess == false){
            tries--;
            printf("Sorry '%c' is not the part of the Word!\n", guess);
            }
            else
            {
             printf("Congratulations! '%c' is one the letters of the Word!\n", guess);
             }

   switch(tries)
   {
    case 6:
    {
     printf("_____________   \n");
     printf("|        |      \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|_______________\n");
     break;
    }

    case 5:
    {
     printf("_____________   \n");
     printf("|        |      \n");
     printf("|        O      \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|_______________\n");
     if(previousGuesses == false){

      previousGuesses[0] = guess;

     }
     break;
    }

    case 4:
    {
     printf("_____________   \n");
     printf("|        |      \n");
     printf("|        O      \n");
     printf("|        |      \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|_______________\n");
     if(previousGuesses == false){

      previousGuesses[1] == guess;

     }
     break;
    }

    case 3:
    {
     printf("_____________   \n");
     printf("|        |      \n");
     printf("|        O      \n");
     printf("|        |      \n");
     printf("|      / |      \n");
     printf("|     /  |      \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|_______________\n");
     if(previousGuesses == false){

      previousGuesses[2] == guess;
      
     }
     break;
    }

    case 2:
    {
     printf("_____________   \n");
     printf("|        |      \n");
     printf("|        O      \n");
     printf("|        |      \n");
     printf("|      / | \\   \n");
     printf("|     /  |  \\  \n");
     printf("|               \n");
     printf("|               \n");
     printf("|               \n");
     printf("|_______________\n");
     if(previousGuesses == false){

      previousGuesses[3] == guess;
      
     }
     break;
    }

    case 1:
    {
     printf("_____________   \n");
     printf("|        |      \n");
     printf("|        O      \n");
     printf("|        |      \n");
     printf("|      / | \\   \n");
     printf("|     /  |  \\  \n");
     printf("|      /        \n");
     printf("|     /         \n");
     printf("|               \n");
     printf("|_______________\n");
     if(previousGuesses == false){

      previousGuesses[4] == guess;
      
     }
     break;
    }

     case 0:
     {
      printf("_____________   \n");
      printf("|        |      \n");
      printf("|        O      \n");
      printf("|        |      \n");
      printf("|      / | \\   \n");
      printf("|     /  |  \\  \n");
      printf("|      /   \\   \n");
      printf("|     /     \\  \n");
      printf("|               \n");
      printf("|_______________\n");
      printf("\nGAME OVER!!\n");
      tries = -1;
      break;
     }

     default:
     {
      printf("There seems to be an Error!");
     }

     return 0;


   }


  }
 }
