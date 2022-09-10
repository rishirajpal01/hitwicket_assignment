#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<string>> &board){
    for (int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void inputA(vector<vector<string>> &board ){
    cout<<"Enter Team A bots: ";
    for (int i=0; i<5; i++){
        string temp = "A-";
        string temp2;
        cin>>temp2;
        temp += temp2;
        board[4][i] = temp2;
    }
}

void inputB(vector<vector<string>> &board){
    cout<<"Enter Team B bots: ";
    for (int i=0; i<5; i++){
        string temp = "B-";
        string temp2;
        cin>>temp2;
        temp += temp2;
        board[0][i] = temp2;
    }
}

void playerAmove(vector<vector<string>> &board){
    string bot;
    string move;
    cout<<"Which A bot to move: ";
    cin>>bot;
    cout<<"Which direction: ";
    cin>>move;
    int x=-1,y=-1;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (bot == board[i][j]){
                x = i;
                y = j;
                break;
            }
            
        }
    }
    if(x==-1 && y==-1)
        return;

    if (move == "F" && x!=0){     // L1
        board[x-1][y] = bot;    
        board [x][y] = "0";
    }
    else if (move == "HF" && x!=1){  // L2 
        board[x-2][y] = bot; 
        board[x-1][y] = "0";   
        board [x][y] = "0";
    }
    else if (move == "B" && x!=4){   // L1
        board[x+1][y] = bot;
        board [x][y] = "0";
    }
    else if (move == "HB" && x!=3){   // L2
        board[x+2][y] = bot;
        board[x+1][y] = "0";
        board [x][y] = "0";
    }
    else if (move == "L" && y!=0){   // L1
        board[x][y-1] = bot;
        board [x][y] = "0";
    }
    else if (move == "HL" && y!=1){   // L2
        board[x][y-2] = bot;
        board[x][y-1] = "0";
        board [x][y] = "0";
    }
    else if (move == "R" && y!=4){     // L1
        board[x][y+1] = bot;
        board [x][y] = "0";
    }
    else if (move == "HR" && y!=3){    // L2
        board[x][y+2] = bot;
        board[x][y+1] = "0";
        board [x][y] = "0";
    }
    else if (move == "FR" && x!=1 && y!=4 ){     // L3
        board[x-2][y+1] = bot;
        board[x][y] = "0";
    }
    else if (move == "RF" && y!=3 && x!=1 ){     // L3
        board[x-1][y+2] = bot;
        board[x][y] = "0";
    }
    else{
        cout<<"Invalid Move!!!"<<endl;
    }

}

void playerBmove(vector<vector<string>> &board){
    string bot;
    string move;
    cout<<"Which B bot to move: ";
    cin>>bot;
    cout<<"Which direction: ";
    cin>>move;
    int x=-1,y=-1;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (bot == board[i][j]){
                x = i;
                y = j;
                break;
            }
            
        }
    }
    if(x==-1 && y==-1)
        return;

    if (move == "F" && x!=4){    // L1
        board[x+1][y] = bot;
        board [x][y] = "0";
    }
    else if (move == "HF" && x!=3 ){   // L2
        board[x+2][y] = bot;
        board[x+1][y] = "0";
        board [x][y] = "0";
    }
    else if (move == "B" && x!=0){    // L1
        board[x-1][y] = bot;
        board [x][y] = "0";
    }
    else if (move == "HB" && x!=1 ){   // L2
        board[x-2][y] = bot;
        board[x-1][y] = "0";
        board [x][y] = "0";
    }
    else if (move == "L" && y!=0){    // L1
        board[x][y-1] = bot;
        board [x][y] = "0";
    }
    else if (move == "HL" && y!=1){   // L2
        board[x][y-2] = bot;
        board[x][y-1] = "0";
        board [x][y] = "0";
    }
    else if (move == "R" && y!=4){     // L1
        board[x][y+1] = bot;
        board [x][y] = "0";
    }
    else if (move == "HR" && y!=3 ){  // L2
        board[x][y+2] = bot;
        board[x][y+1] = "0";
        board [x][y] = "0";
    }
    else if (move == "FR" && x!=3 && y!=4){   // L3
        board[x+2][y+1] = bot;
        board[x][y] = "0";
    }
    else if (move == "RF" && y!=3 && x!=4){  // L3
        board[x+1][y+2] = bot;
        board[x][y] = "0";
    }
    else{
        cout<<"Invalid Move!!!"<<endl;
    }
}

int main(){
    vector<vector<string>> board = {{"0","0","0","0","0"}, {"0","0","0","0","0"}, {"0","0","0","0","0"}, {"0","0","0","0","0"}, {"0","0","0","0","0"}};
    inputA(board);
    inputB(board);
    while(true){
        display(board);
        playerAmove(board);
        display(board);
        playerBmove(board);
    }
    return 0;
}