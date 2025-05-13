#include <iostream>
#include <random>
#include <limits>

using namespace std;

int main()
{
    random_device rd; // Seed generator
    mt19937 gen(rd()); // Mersenne Twister engine initialization
    uniform_int_distribution<> distrib(1, 10); // Uniform distribution between 1 and 10

    int randomNumber = distrib(gen);

    int guess;
    cout << "Let's start the random number game!" << endl;

    while (true)
    {
        cout << "Enter a number between 1 and 10: ";
        cin >> guess;

        // Check for invalid input
        if (cin.fail() || guess < 1 || guess > 10)
        {
            cin.clear(); // Reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 10." << endl;
            continue;
        }

        if (guess == randomNumber)
        {
            cout << "Congratulations! You guessed the correct number!" << endl;
            break;
        }
        else if (guess > randomNumber)
        {
            cout << "Your guess is higher than the correct number. Try a smaller number." << endl;
        }
        else
        {
            cout << "Your guess is lower than the correct number. Try a larger number." << endl;
        }
    }

    return 0;
}
