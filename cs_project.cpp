#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void ticTacToe() {
    srand(time(0));
    char b[3][3] = { {' ', ' ', ' '},
                     {' ', ' ', ' '},
                     {' ', ' ', ' '} };

    while (true) {

        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " " << b[i][0] << " | " << b[i][1] << " | " << b[i][2] << "\n";
            if (i < 2) cout << "---|---|---\n";
        }
        cout << "\n";


        int r, c;
        cout << "Row (1-3): ";
        cin >> r;
        cout << "Col (1-3): ";
        cin >> c;
        r--; c--;

        if (r < 0 || r > 2 || c < 0 || c > 2 || b[r][c] != ' ') {
            cout << "Invalid move!\n";
            continue;
        }

        b[r][c] = 'X';


        if ((b[0][0] == 'X' && b[0][1] == 'X' && b[0][2] == 'X') ||
            (b[1][0] == 'X' && b[1][1] == 'X' && b[1][2] == 'X') ||
            (b[2][0] == 'X' && b[2][1] == 'X' && b[2][2] == 'X') ||
            (b[0][0] == 'X' && b[1][0] == 'X' && b[2][0] == 'X') ||
            (b[0][1] == 'X' && b[1][1] == 'X' && b[2][1] == 'X') ||
            (b[0][2] == 'X' && b[1][2] == 'X' && b[2][2] == 'X') ||
            (b[0][0] == 'X' && b[1][1] == 'X' && b[2][2] == 'X') ||
            (b[0][2] == 'X' && b[1][1] == 'X' && b[2][0] == 'X'))
        {
            cout << "You win!\n";
            return;
        }


        int rr, cc;
        do {
            rr = rand() % 3;
            cc = rand() % 3;
        } while (b[rr][cc] != ' ');
        b[rr][cc] = 'O';

        if ((b[0][0] == 'O' && b[0][1] == 'O' && b[0][2] == 'O') ||
            (b[1][0] == 'O' && b[1][1] == 'O' && b[1][2] == 'O') ||
            (b[2][0] == 'O' && b[2][1] == 'O' && b[2][2] == 'O') ||
            (b[0][0] == 'O' && b[1][0] == 'O' && b[2][0] == 'O') ||
            (b[0][1] == 'O' && b[1][1] == 'O' && b[2][1] == 'O') ||
            (b[0][2] == 'O' && b[1][2] == 'O' && b[2][2] == 'O') ||
            (b[0][0] == 'O' && b[1][1] == 'O' && b[2][2] == 'O') ||
            (b[0][2] == 'O' && b[1][1] == 'O' && b[2][0] == 'O'))
        {
            cout << "Computer wins!\n";
            return;
        }
    }
}

void rockPaperScissors() {
    int user, comp;

    cout << "1) Rock\n2) Scissors\n3) Paper\nChoose: ";
    cin >> user;

    comp = rand() % 3 + 1;

    if (user == comp) {
        cout << "Draw!\n";
    } else if ((user == 1 && comp == 2) || (user == 2 && comp == 3) || (user == 3 && comp == 1)) {
        cout << "You win!\n";
    } else {
        cout << "You lose!\n";
    } cout << "Computer chose: " << comp << "\n";
}



void guessNumber() {
    int maxN, guess, secret;

    cout << "Enter max number: ";
    cin >> maxN;

    secret = rand() % maxN + 1;

    cout << "Your guess: ";
    cin >> guess;

    if (guess == secret) cout << "Correct!\n";
    else cout << "Wrong! Number was: " << secret << "\n";
}

int main() {
    while (true) {
        cout << "\n--- Game Menu ---\n";
        cout << "1) Tic Tac Toe\n";
        cout << "2) Rock Paper Scissors\n";
        cout << "3) Guess Number\n";
        cout << "4) Exit\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;

        if (choice == 1) ticTacToe();
        else if (choice == 2) rockPaperScissors();
        else if (choice == 3) guessNumber();
        else if (choice == 4) break;
    }

    return 0;
}
