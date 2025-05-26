#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

void greetMessage();
void results(int score, int numOfQuestions, float percentage);
int main()
{
    char option;
    int score = 0, option2, gamechoice = 1;
    greetMessage();
    std::fstream file("quiz_questions.txt", std::ios::app);
    std::string arrayOfQuestions[5] = {
        "1. What is the capital of France?",
        "2. What is 2 + 2?",
        "3. Who wrote 'To Kill a Mockingbird'?",
        "4. What is the largest planet in our solar system?",
        "5. What is the boiling point of water in Celsius?"};
    std::string arrayOfOptions[5][4] = {
        {"A. Paris", "B. London", "C. Berlin", "D. Madrid"},
        {"A. 3", "B. 4", "C. 5", "D. 6"},
        {"A. Harper Lee", "B. Mark Twain", "C. F. Scott Fitzgerald", "D. Ernest Hemingway"},
        {"A. Earth", "B. Jupiter", "C. Saturn", "D. Mars"},
        {"A. 90 degree celcius", "B. 100 degree celcius", "C. 80 degree celcius", "D. 120 degree celcius"}};
    char arrayOfAnswers[5] = {
        'A',
        'B',
        'A',
        'B',
        'B'};
    if (file.is_open())
    {
        file << "Quiz Questions:\n";
        file << "1. What is the capital of France?\n";
        file << "2. What is 2 + 2?\n";
        file << "3. Who wrote 'To Kill a Mockingbird'?\n";
        file << "4. What is the largest planet in our solar system?\n";
        file << "5. What is the boiling point of water in Celsius?\n";
        file.close();
    }
    else
    {
        std::cerr << "Error opening file!" << std::endl;
    }
    do

    {
        score = 0;
        for (int i = 0; i < 5; i++)
        {
            system("cls");
            std::cout << arrayOfQuestions[i] << std::endl;
            for (int k = 0; k < sizeof(arrayOfOptions[i]) / sizeof(arrayOfOptions[i][0]); k++)
            {
                std::cout << "  " << arrayOfOptions[i][k];
                std::cout << std::endl;
            }
            printf("Answer:");
            std::cin >> option;

            option = toupper(option);
            printf("Confirm And ");
            system("pause");
            if (option == arrayOfAnswers[i])
            {

                std::cout << "____________________\n";
                printf("Correct Answer\n");
                std::cout << "____________________\n";
                score++;
            }
            else
            {
                std::cout << "____________________\n";
                printf("Incorrect Answer\n");
                std::cout << "____________________\n";
            }
            printf("To Go To The Next Question ");
            system("pause");
        }
        float percentage = ((float)score / (sizeof(arrayOfQuestions) / sizeof(arrayOfQuestions[0]))) * 100.00;
        system("cls");
        printf("Thank You For Answering, Choose Below\n 1. View Results \n 2. Exit Application\n  Option:");
        std::cin >> option2;
        switch (option2)
        {
        case 1:
        {
            system("cls");
            printf("__________Results__________\n");
            results(score, (sizeof(arrayOfQuestions) / sizeof(arrayOfQuestions[0])), percentage);
            printf("___________________________\n");
            printf("Press 1 to play again or 2 to exit: ");
            std::cin >> gamechoice;
            if (gamechoice != 1 && gamechoice != 2)
            {
                printf("Invalid choice, exiting the game...\n");

                return 0;
            }
            else
            {
                system("cls");
                printf("Thank you for playing!\n");
                printf("Press Enter to exit...");
                std::cin.ignore();
                std::cin.get();
            }
        }
        break;
        case 2:
        {
            system("cls");
            return 0;
        }
        break;

        default:
            printf("invalid Response\n");
            std::cout << "Please try again." << std::endl;
            printf("Choose Below:\n 1. Play Again \n 2. Exit Application\n  Option:");
            std::cin >> gamechoice;
            system("pause>0");
            break;
        }
    } while (gamechoice == 1);
}
void greetMessage()
{
    system("cls");
    std::cout << "Welcome to the Quiz App!" << std::endl;
    std::cout << "This is a simple quiz application." << std::endl;
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.get();
    system("cls");
    std::cout << "You will be asked a series of questions." << std::endl;
    std::cout << "Answer them to the best of your ability." << std::endl;
    std::cout << "Let's get started!" << std::endl;
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.get();
    system("cls");
}
void results(int score, int numOfquestions, float percentage)
{
    printf(" Score: %d \n Questions: %d \n Percentage: %.2f%\n ", score, numOfquestions, percentage);
    if (score >= 3)
    {
        printf("Status: PASS\n");
    }
    else
    {
        printf("Status: FAIL\n");
    }
};
