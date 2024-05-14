#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printQuestion(const char *quiz[][3], int question);
int checkAnswer(const char *quiz[][3], char buffer[256], int question);
void printStats(int question, int correct);
void introduce();

int main()
{
    const char *quiz[][3] = {
        // Question format:
        // Question, Possible answers, Answer in lower case.
        {"1. ", "A. , B. , C. , D. ", "a"},
        {"2. ", "A. , B. , C. , D. ", "a"},
        {"3. ", "A. , B. , C. , D. ", "a"},
        {"4. ", "A. , B. , C. , D. ", "a"},
    };
    int question = 0;
    int correct = 0;
    char buffer[256];

    introduce();
    while(true)
    {
        // Checks if the user reaches the end of the quiz!
        if(question >= sizeof(quiz) / sizeof(quiz[0]))
        {
            printf("\nYou've reached the end of this quiz!\n");
            break;
        }

        // Fetches the user's input and cleans it.
        printQuestion(quiz, question);
        fgets(buffer, 256, stdin);

        if(strlen(buffer) > 2)
        {
            printf("Sorry! We only accept characters!\n");
            break;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        strlwr(buffer);

        correct += checkAnswer(quiz, buffer, question);

        question++;
    }
    printStats(question, correct);
    
    return 0;
}
void printQuestion(const char *quiz[][3], int question)
{
    printf("%s %s\n", quiz[question][0], quiz[question][1]);
}
int checkAnswer(const char *quiz[][3], char buffer[256], int question)
{
    // Checks if the answer is correct!
    if(strcmp(buffer, quiz[question][2]) == 0)
    {
        printf("\nCorrect!\n");
        return 1;
    }
    printf("\nIncorrect!\n");
    return 0;
}
void printStats(int question, int correct)
{
    float percentage = (float) correct / question * 100;
    printf("You got: %.2f%% of the quiz correct!\n", percentage);
}
void introduce()
{
    printf("Welcome to this Quiz!\n");
    printf("Let's see how many questions you get correct!\n\n");
}