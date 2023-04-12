#include<bits/stdc++.h>
using namespace std;
char kKjudge(char c){
    if(islower(c))  return 'K';
    else    return 'k';
}

void check(char c, bool *black, bool *white){
    if(islower(c))  *white = true;
    else    *black = true;
}

int main(){
  bool exit = true, blackcheck = false, whitecheck = false;
  char board[15][15] = {0}, kKchar;
  int gamenum = 1, step;

  while(1){
    for(int i = 2; i <= 9; i++){
        for(int j = 2; j <= 9; j++){
            cin>>board[i][j];
            if(board[i][j] != '.')
                exit = false;
        }
    }
    if(exit) break;

    for(int i = 2; i <= 9; i++){
        for(int j = 2; j <= 9; j++){
            kKchar = kKjudge(board[i][j]);
            switch(board[i][j]){
                case 'p':
                if( board[i + 1][j + 1] == kKchar ||
                    board[i + 1][j - 1] == kKchar)
                    whitecheck = true;
                break;

                case 'P':
                if( board[i - 1][j + 1] == kKchar ||
                    board[i - 1][j - 1] == kKchar)
                    blackcheck = true;
                break;

                case 'n':
                case 'N':
                if( board[i + 1][j + 2] == kKchar ||
                    board[i + 1][j - 2] == kKchar ||
                    board[i - 1][j + 2] == kKchar ||
                    board[i - 1][j - 2] == kKchar ||
                    board[i + 2][j + 1] == kKchar ||
                    board[i + 2][j - 1] == kKchar ||
                    board[i - 2][j + 1] == kKchar ||
                    board[i - 2][j - 1] == kKchar)
                    check(board[i][j], &blackcheck, &whitecheck);
                break;

                case 'r':   case 'q':
                case 'R':   case 'Q':
                step = 1;
                while(board[i + step][j] == '.')    step++;
                if(board[i + step][j] == kKchar)
                    check(board[i][j], &blackcheck, &whitecheck);
                step = 1;
                while(board[i - step][j] == '.')    step++;
                if(board[i - step][j] == kKchar)
                    check(board[i][j], &blackcheck, &whitecheck);
                step = 1;
                while(board[i][j + step] == '.')    step++;
                if(board[i][j + step] == kKchar)
                    check(board[i][j], &blackcheck, &whitecheck);
                step = 1;
                while(board[i][j - step] == '.')    step++;
                if(board[i][j - step] == kKchar)
                    check(board[i][j], &blackcheck, &whitecheck );
                if(board[i][j] == 'r' || board[i][j] == 'R')    break;

                case 'b':   case 'B':
                step = 1;
                while(board[i + step][j + step] == '.')     step++;
                if(board[i + step][j + step] == kKchar)
                    check(board[i][j], &blackcheck, &whitecheck);
                step = 1;
                while(board[i - step][j + step] == '.')     step++;
                if(board[i - step][j + step] == kKchar)
                    check(board[i][j], &blackcheck, &whitecheck);
                step = 1;
                while(board[i + step][j - step] == '.')     step++;
                if(board[i + step][j - step] == kKchar)
                    check(board[i][j], &blackcheck, &whitecheck);
                step = 1;
                while(board[i - step][j - step] == '.')     step++;
                if(board[i - step][j - step] == kKchar)
                    check(board[i][j], &blackcheck, &whitecheck);
                break;
            }
            if(blackcheck || whitecheck)    break;
        }
        if(blackcheck || whitecheck)    break;
    }

    printf("Game #%d: ", gamenum++);
    if(blackcheck)
        printf("black king is in check.\n");
    else if(whitecheck)
        printf("white king is in check.\n");
    else
        printf("no king is in check.\n");
        
    blackcheck = false;
    whitecheck = false;
    exit = true;
    }
}