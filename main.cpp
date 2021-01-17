#include <iostream>

using namespace std;
   char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
   char gamer='X';
    void affichematrix(){
           system("cls");
          for(int i = 0; i < 3 ; i++){
                cout << " \n ";
            for(int j = 0; j < 3 ;j++){
                cout <<  matrix[i][j]  << "       ";
            }
         }
         cout <<endl;
        }
    void game_player(){
       char position;
       cout << "choisiez votre position: "<< " gamer1 ";
       cin >> position;
       for(int i=0; i<3 ; i++){
            for(int j=0; j<3 ;j++){
               if(matrix[i][j]==position){
                matrix[i][j]=gamer;
               }
            }
          }
          if(gamer=='X'){
            gamer='O';
        }
        else{
            gamer='X';
        }
    }
    char winner(){
        int x=0, o=0;
         int cont=0;
          for(int i=0; i<3 ; i++){
            for(int j=0; j<3 ;j++){
                if(matrix[i][j]!='X' || matrix[i][j]!='O'){
                    cont++;
                }
                if(matrix[i][j]!='X' || matrix[i][j]!='O'){
                    cont++;
                }
                if(matrix[i][j]=='X'){
                    x++;
                }
                if(matrix[i][j]=='O'){
                    o++;
                }
                if(x==3 || o==3){
                    return x>o ?'X' : 'O';
                }
            }
            x=0;
            o=0;
          }
         for(int i=0; i<3 ; i++){
            for(int j=0; j<3 ;j++){
                if(matrix[j][i]=='X'){
                    x++;
                }
                else if(matrix[j][i]=='O'){
                    o++;
                }
                if(x==3 || o==3){
                    return x>o ?'X' : 'O';
                }
            }
            x=0;
            o=0;
          }
          if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') return 'X';
          if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') return 'O';
          if(matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') return 'X';
          if(matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') return 'O';
          if(cont==0) return 'Z';
      return '.';
    }

int main()
{
    while(winner()=='.'){
        affichematrix();
        game_player();
    }

    if(winner()=='Z'){
        cout << "\n Game Over \n" << endl;
    }
    else{
        cout << "\n the winner is : (" << winner() << ") FELICITATIONS !! \n\n";
    }
    system("pause");
    return 0;
}
