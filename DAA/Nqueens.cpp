#include<bits/stdc++.h>
using namespace std;

int COL;
int ROW;
bool flag;

void printBoard(vector<vector<int>>board){

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==1){
                cout<<"Q  ";
            }
            else{
                cout<<"*  ";
            }
        }

        cout<<endl;
    }
}

bool isSafeBasic(vector<vector<int>>&board,int row, int col){
    int n=board.size();
    // int m=board[0].size();
    for(int i=0;i<col;i++){
        if(board[row][i]==1) return false;
    }

    for(int i=row,j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]==1) return false;
    }

    for(int i=row,j=col; i<n && j>=0; i++,j--){
        if(board[i][j]==1) return false;
    }

    return true;
}

bool isSafeFirstPlaced(vector<vector<int>>&board,int row, int col){
    int n=board.size();

    for(int i=0;i<n;i++){
        if(i!=col && board[row][i]==1) return false;
    }

    for(int i=row,j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]==1) return false;
    }

    for(int i=row,j=col; i<n && j>=0; i++,j--){
        if(board[i][j]==1) return false;
    }

    for(int i=row,j=col; i>=0 && j<n; i--,j++){
        if(board[i][j]==1) return false;
    }

    for(int i=row,j=col; i<n && j<n; i++,j++){
        if(board[i][j]==1) return false;
    }

    return true;
}

bool solveUtil(vector<vector<int>>&board, int col){
    int n=board.size();

    if(col>=n){
        // printBoard(board);
        return true;
    }

    for(int i=0;i<board.size();i++){

    if(isSafeBasic(board,i,col)){
        board[i][col]=1;

        if(solveUtil(board,col+1)){
            return true;
        }

        board[i][col]=0;
    }

}

    return false;

}


bool solveUtilFirstPlaced(vector<vector<int>>&board, int col){
    int n=board.size();

    if(col>=n){
        // printBoard(board);
        return true;
    }

    if(col==COL){
        if(solveUtilFirstPlaced(board,col+1)) return true;

        else return false;
    }

    else{

    for(int i=0;i<board.size();i++){

    if(isSafeFirstPlaced(board,i,col)){
        board[i][col]=1;

        if(solveUtilFirstPlaced(board,col+1)){
            return true;
        }

        board[i][col]=0;
     }

    }
}

    return false;

}

void solve(vector<vector<int>>&board){
    if(solveUtil(board,0)){
        printBoard(board);
    }

    else{
        cout<<"Solution Does not exist!"<<endl;
    }
}

void solveFirstPlaced(vector<vector<int>>&board){
    if(solveUtilFirstPlaced(board,0)){
        printBoard(board);
    }

    else{
        cout<<"Solution Does not exist!"<<endl;
    }
}


void solveUtilPrintAll(vector<vector<int>>&board, int col){
    int n=board.size();

    if(col>=n){
        flag=true;
        printBoard(board);
        cout<<endl;
    }

    for(int i=0;i<board.size();i++){

    if(isSafeBasic(board,i,col)){
        board[i][col]=1;

        solveUtilPrintAll(board,col+1);

        board[i][col]=0;
    }

}



}

int main(){
    int k=1;
    while(k){
    cout<<"\nEnter size of board: ";
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    cout<<"Enter choice:\n1. Single solution\n2. Single solution with 1st Queen placed\n3. All solutions\n=> ";
    cin>>k;

    switch (k)
    {
    case 1:
        solve(board);
        break;
    case 2:
        cout<<"First Queen row: ";
        cin>>ROW;
        cout<<"First Queen column: ";
        cin>>COL;
        board[ROW][COL]=1;
        cout<<"========= Start Board ========="<<endl;
        printBoard(board);
        cout<<endl<<endl;
        cout<<"========== Solution =========="<<endl;
        solveFirstPlaced(board);
        break;
    case 3:
        flag=false;
        solveUtilPrintAll(board,0);
        if(!flag) cout<<"No solution exists!"<<endl;
        break;

    
    default:
        break;
    }

    
    }
}
