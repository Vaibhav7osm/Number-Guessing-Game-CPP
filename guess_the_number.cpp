#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int chooseDifficulty()
{
    int level;

    cout << "\nChoose Difficulty Level\n";
    cout << " Enter 1 for Easy (1 - 50)\n";
    cout << "Enter 2 for Medium (1 - 100)\n";
    cout << "Entrr 3 for Hard (1 - 500)\n";

    cin >> level;

    while(level < 1 || level > 3)
    {
        cout << "Invalid choice. Enter again: ";
        cin >> level;
    }

    if(level == 1)
        return 50;
    else if(level == 2)
        return 100;
    else
        return 500;
}

void playGame(int max)
{
    int number = rand() % max + 1;
    int guess;
    int attempts = 0;
    int maxAttempts = 10;
    int score = 100;

    cout << "Guess a number between 1 and " << max << endl;
    cout << "You have " << maxAttempts << " attempts\n";

    while(attempts < maxAttempts)
    {
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if(guess > number)
        {
            cout << "Too high\n";
            score -= 10;
        }
        else if(guess < number)
        {
            cout << "Too low\n";
            score -= 10;
        }
        else
        {
            cout << "Correct!  Congratulations You guessed it."<<endl; 
            cout<<"Attempts used: " << attempts << endl;
            cout << "Your score: " << score << endl;
            return;
        }

        if(score < 0)
            score = 0;
    }

    cout << "Game Over! The number was " << number << endl;
}

int main()
{
    srand(time(0));
    char playAgain;

    do
    {
        cout << "\n===== Guess The Number Game =====\n";

        int max = chooseDifficulty();

        playGame(max);

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}
