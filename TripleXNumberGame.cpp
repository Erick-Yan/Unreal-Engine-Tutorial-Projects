#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{
    cout << "\n\nISIS has planted bombs all over Mississauga..\n";
    cout << "Begin level " << Difficulty << endl;
    cout << "Enter the correct set of numbers to diffuse the 1st bomb..\n\n";
}

bool PlayGame(int Difficulty){

    // Print welcome messages to the terminal
    PrintIntroduction(Difficulty);

    //Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product to the terminal
    cout << "+ there are 3 numbers in this code\n";
    cout << "+ the codes add up to " << CodeSum << endl;
    cout << "+ the codes multiply up to " << CodeProduct << endl;

    int GuessA, GuessB, GuessC;
    cin >> GuessA;
    cin >> GuessB;
    cin >> GuessC;
    cout << "You Entered: " << GuessA << GuessB << GuessC << endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\nthe bomb has diffused" << endl;
        return true;
    } else{
        cout << "\nyou dead" << endl;
        return false;
    }

}

int main()
{
    srand(time(0));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5; 
    while(LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();
    
        if(bLevelComplete && LevelDifficulty < MaxDifficulty)
        {
            cout << "moving on" << endl;
            ++LevelDifficulty;
        } else if(bLevelComplete && LevelDifficulty == MaxDifficulty)
        {
            cout << "its finally over" << endl;
            exit(0);
        } else
        {
            cout << "keep trying" << endl;
        }

    }
    return 0;
}
