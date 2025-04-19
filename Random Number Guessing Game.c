#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void showGuide();
int generateRandomNumber();
void playGames(int generateRandomNumber, const char *playerName);
void saveScore(const char *playerName, int attempts);
void displayScores();

struct Player{
    char name[50];
    int score;
};

int main()
{
    char playAgain;
    struct Player player ;
	
	 do{
	     showGuide();
	     
	     printf("\nEnter Your name : ");
	     scanf("%s", player.name);
	     
	     int randomNumber = generateRandomNumber();
	     
	     playGames(randomNumber,player.name);
	     
	     printf("\nDo You Want To Play Again? [Y/N] : ");
	     scanf(" %c", &playAgain);   
	 } while (playAgain == 'Y'|| playAgain == 'y');
	 printf("Thank You For Playing");
	 
	 displayScores();
	 
	return 0;
}

void showGuide()
{
    printf("\nWelcome To Our Guessing Games\n");
    printf("You Will Be Given 3 Attempts To Guess\n");
	printf("Guess A Random Number Between 1-10,Guess Wisely :)\n");
}

int generateRandomNumber()
{
    srand(time(0));
    return rand() % 10 + 1;
}

void playGames(int randomNumber, const char *playerName)
{
    int guess,attempts = 0;
    
    do{
        printf("\nEnter Your Guess (1-10): ");
        scanf("%d", &guess);
        
        if (guess<1 || guess >10)
        {
            printf("Please Enter Number Between 1-10.\n");
            continue;
        }
        if (guess < randomNumber)
        {
            printf("Too Low! Please Try Again.\n");
        }
        else if(guess > randomNumber)
        {
             printf("Too High ! Please Try Again\n");
        }
         
        attempts ++;    
    } while (guess != randomNumber && attempts < 3);
    
	if(guess == randomNumber)
	{
        printf("Congratulations, %s! You guessed the number in %d attempts.\n" , playerName, attempts);
    }
	else
	{
        printf("Sorry, %s, you have run out of attempts.The correct number was %d.\n", playerName, randomNumber);
    }
    
    saveScore(playerName, attempts);
    void displayScores();   
}

void saveScore(const char *playerName, int attempts) 
	{
    FILE *file = fopen("scores.txt", "a");

    if (file == 0) 
	{
        printf("Error opening file.\n");
        return;
    }

    struct Player player;
    strcpy(player.name, playerName);
    player.score = attempts;

    fprintf(file, "Player: %s, Score: %d attempts\n", player.name, player.score);

    fclose(file);
}

void displayScores() {
    FILE *file = fopen("scores.txt", "r");

    if (file == 0) 
	{
        printf("Error opening file.\n");
        return;
    }

    printf("\nScores:\n");

    char line[100];
    while (fgets(line, sizeof(line), file)) 
	{
        printf("%s", line);
    }
	
	fclose(file);
}

