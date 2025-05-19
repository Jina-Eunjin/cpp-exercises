#include <iostream>
#include <cstring>
#include <random>

using namespace std;

const int kMaxStr = 100;

const char *fruitwWordList[] = {"apple", "banana", "grape", "lemon", "strawberry", "blueberry", "peach"}; // 여러 개의 문자열(문자 배열)을 담고 싶을 때는 포인터 배열이 필요
const int wordCount = sizeof(fruitwWordList) / sizeof(fruitwWordList[0]);                                       // char*의 크기는 8바이트

bool IsEqual(const char str1[], char str2[]);

int main()
{

    char str1[kMaxStr]; // 문자들의 배열" → 단순한 문자열 하나 ("hello" 등)
    char str2[kMaxStr];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, wordCount -1);
    int randomIndex = distrib(gen);
    strncpy(str1, fruitwWordList[randomIndex], kMaxStr); // 복사 시 \0 누락 가능

    str1[kMaxStr - 1] = '\0';  // 안전하게 문자열 종료

    cout << "Let's play a game! You have 5 attempts. To quit at any time, enter -1." << endl;

    for (int count = 5; count > 0; count--)
    {
        cout << "You have " << count << (count == 1 ? " try" : " tries") << " left." << endl;
        cout << "Enter a word: ";
        cin >> str2;

        if (strcmp(str2, "-1") == 0)
        {
            cout << "Exiting..." << endl;
            break;
        }

        if (IsEqual(str1, str2))
        {

            cout << "Match!" << endl;
            break;
        }

        else if (count == 1)
        {
            cout << "You lose the game!" << endl;
        }
        else
        {
            cout << "Try again!" << endl;
        }
    };

    return 0;
}

bool IsEqual(const char str1[], char str2[])
{

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (tolower(str1[i]) != tolower(str2[i]))
        {
            return false;
        }
    }

    return true;

    // if (strlen(str1) == strlen(str2))
    // {
    //     cout << "Match!" << endl;
    //     return true;
    // }
    // else
    // {
    //     cout << "Try again!" << endl;

    //     return false;
    // }
}
