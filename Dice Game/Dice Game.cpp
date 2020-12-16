/*
 * Name: Sebastian Risty
 * Date: 10/13/2020
 * File: HW4.cpp
 * Description: A two player dice game.
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayDice(int num);
void rerollDice(int& d1, int& d2, int& d3, int p1, int p2, int p3);
int calculateScore(int d1, int d2, int d3);

int main() {
    int player1Score = 0;
    int player2Score = 0;
    int tempScore;

    //loop 6 times, 3 rounds for 2 players = 6 total
    for (int i = 0; i < 6; i++) {
        //update rand seed
        srand(time(NULL));
        //create dice variables
        int d1 = rand() % 6 + 1;
        int d2 = rand() % 6 + 1;
        int d3 = rand() % 6 + 1;
        int p1, p2, p3;

        //check whos turn it is, if and else blocks do the same thing for each person, just changes names in cout
        if (i % 2 == 0) {
            //for player 1
            //display dice and ask for reroll
            cout << "Player 1 lets roll! Here are your 3 dice: " << endl;
            displayDice(d1);
            displayDice(d2);
            displayDice(d3);
            cout << "Player 1 which dice would you like to reroll? Type 1 to reroll, and 0 to skip reroll for each dice with a space between each number ex: 1 0 1 to reroll first and last dice. " << endl;
            cin >> p1 >> p2 >> p3;
            rerollDice(d1, d2, d3, p1, p2, p3);
            cout << "Player 1 here are your new dice!" << endl;
            displayDice(d1);
            displayDice(d2);
            displayDice(d3);
            //calculate score based on final dice roll
            tempScore = player1Score;
            player1Score += calculateScore(d1, d2, d3);
            //show how many points were added and total score for players turn
            cout << "Points added: " << player1Score - tempScore << " \nTotal points: " << player1Score << endl;
            cout << "Player 2 it's your turn!" << endl;
        }
        else {
            //for player 2
            //display dice and ask for reroll
            cout << "Player 2 lets roll! Here are your 3 dice: " << endl;
            displayDice(d1);
            displayDice(d2);
            displayDice(d3);
            cout << "Player 2 which dice would you like to reroll? Type 1 to reroll, and 0 to skip reroll for each dice ex: 101 to reroll first and last dice. " << endl;
            cin >> p1 >> p2 >> p3;
            rerollDice(d1, d2, d3, p1, p2, p3);
            cout << "Player 2 here are your new dice!" << endl;
            displayDice(d1);
            displayDice(d2);
            displayDice(d3);
            //calculate score based on final dice roll
            tempScore = player2Score;
            player2Score += calculateScore(d1, d2, d3);
            //show how many points were added and total score for players turn
            cout << "Points added: " << player2Score - tempScore << " \nTotal points: " << player2Score << endl;
            //check to see if it's last turn 
            if (i != 5) {
                cout << "Player 1 it's your turn!" << endl;
            }
        }
    }
    //print out final score and determin who was the winner
    cout << "That's game! Here are the results: " << endl;
    cout << "Player 1 has " << player1Score << " points!" << endl;
    cout << "Player 2 has " << player2Score << " points!" << endl;

    if (player1Score > player2Score) {
        cout << "Player 1 wins!" << endl;
    }
    else if (player1Score < player2Score) {
        cout << "Player 2 wins!" << endl;
    }
    else {
        cout << "It's a tie!" << endl;
    }
    return 0;
}

//calculate scores for appropriate player
int calculateScore(int d1, int d2, int d3) {
    //check for dubs or trips
    if (d1 == d2 || d1 == d3) {
        if (d1 == d3 && d1 == d2) {
            return d1 + 20;
            cout << "Nice triple! +20 points!" << endl;
        }
        return d1 + 10;
        cout << "Nice double! +10 points!" << endl;
    }
    if (d2 == d1 || d2 == d3) {
        if (d2 == d3 && d2 == d1) {
            return d2 + 20;
            cout << "Nice triple! +20 points!" << endl;
        }
        return d2 + 10;
        cout << "Nice double! +10 points!" << endl;
    }
    //else return highest value
    if (d1 > d2 && d1 > d3) {
        return d1;
    }
    else if (d2 > d1 && d2 > d3) {
        return d2;
    }
    return d3;
}
//reroll selected dice
void rerollDice(int& d1, int& d2, int& d3, int p1, int p2, int p3) {
    //check which dice were specified to be rerolled and roll them by changing the dice value in main()
    switch (p1) {
    case 0:
        break;
    case 1:
        d1 = rand() % 6 + 1;
        break;
    }
    switch (p2) {
    case 0:
        break;
    case 1:
        d2 = rand() % 6 + 1;
        break;
    }
    switch (p3) {
    case 0:
        break;
    case 1:
        d3 = rand() % 6 + 1;
        break;
    }
}

//display ascii art of dice rolled
void displayDice(int num) {
    //print out the ascii art of the die # that is given in the argument
    switch (num) {
    case 1:
        cout << "-------" << endl;
        cout << "|     |" << endl;
        cout << "|  *  |" << endl;
        cout << "|     |" << endl;
        cout << "-------" << endl;
        break;
    case 2:
        cout << "-------" << endl;
        cout << "|   * |" << endl;
        cout << "|     |" << endl;
        cout << "| *   |" << endl;
        cout << "-------" << endl;
        break;
    case 3:
        cout << "-------" << endl;
        cout << "|   * |" << endl;
        cout << "|  *  |" << endl;
        cout << "| *   |" << endl;
        cout << "-------" << endl;
        break;
    case 4:
        cout << "-------" << endl;
        cout << "| * * |" << endl;
        cout << "|     |" << endl;
        cout << "| * * |" << endl;
        cout << "-------" << endl;
        break;
    case 5:
        cout << "-------" << endl;
        cout << "| * * |" << endl;
        cout << "|  *  |" << endl;
        cout << "| * * |" << endl;
        cout << "-------" << endl;
        break;
    case 6:
        cout << "-------" << endl;
        cout << "| * * |" << endl;
        cout << "| * * |" << endl;
        cout << "| * * |" << endl;
        cout << "-------" << endl;
        break;
    }
}
