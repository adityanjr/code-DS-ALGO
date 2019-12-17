#include<bits/stdc++.h>
using namespace std;
int totalways = 0;
void attack(char** board, int i, int j, int size){

      if((i-2)>=0 && (j+1)<size){
          board[i-2][j+1]='a';
      }

      if((i-2)>=0 && (j-1)>=0){
          board[i-2][j-1]='a';
      }

      if((i-1)>=0 && (j+2)<size){
          board[i-1][j+2]='a';
      }

      if((i+1)<size && (j+2)<size){
          board[i+1][j+2]='a';
      }

      if((i-1)>=0 && (j-2)>=0){
          board[i-1][j-2]='a';
      }

      if((i+1)<size && (j-2)>=0){
          board[i+1][j-2]='a';
      }

      if((i+2)<size && (j-1)>=0){
          board[i+2][j-1]='a';
      }

      if((i+2)<size && (j+1)<size){
          board[i+2][j+1]='a';
      }

}

bool isValid(char** board, int i, int j){
    if(board[i][j]=='_')
        return true;
    return false;
}

void placeboard(char **board, char** new_board,int size,int sti, int stj){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            new_board[i][j] = board[i][j];
        }
    }

    new_board[sti][stj]='k';
    attack(new_board,sti,stj,size);
}

void nKnight(char** board, int sti,int stj,int size,int placed){

    if(placed==0){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(board[i][j]=='k'){
                    cout<<"{"<<i<<"-"<<j<<"}"<<" ";
                }
            }
        }
        cout<<" ";
        totalways++;
    }

   else{

    for(int i=sti;i<size;i++){
        for(int j=stj;j<size;j++){
            if(isValid(board,i,j)){

                char** new_board = new char*[10];
                for(int x=0;x<10;x++){
                    new_board[x] = new char[10];
                }

                placeboard(board,new_board,size,i,j);
                nKnight(new_board,i,j,size,placed-1);

                for(int k=0;k<10;k++){
                    delete new_board[k];
                }
                delete[] new_board;
            }
        }
        stj=0;
    }
}
}
int main() {
    int n;
    cin>>n;

    char** board = new char*[10];
    for(int i=0;i<10;i++){
        board[i] =new char[10];
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            board[i][j] = '_';
        }
    }

    nKnight(board,0,0,n,n);
    cout<<endl<<totalways<<endl;
	return 0;
}
