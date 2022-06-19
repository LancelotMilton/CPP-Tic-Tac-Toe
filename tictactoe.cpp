#include <iostream>
#include <string>
//I think I'm a lazy programmer sometimes...

char safhe[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
std::string name1;
std::string name2;
int chs;
int row, column;
char turn='X';
bool draw=false;
	void namayesh(){
	std::cout<<"\n\n "<<name1<<" :[X]"<<"  &  "<<name2<<" :[O]\n\n";
	std::cout<<"\t|\t|"<<std::endl<<"\t|\t|"<<std::endl<<"   "<<safhe[0][0]<<"\t|"<<"   "<<safhe[0][1]<<"\t|"<<"   "<<safhe[0][2]<<std::endl;
	std::cout<<"________|_______|________"<<std::endl;
	std::cout<<"\t|\t|"<<std::endl<<"\t|\t|"<<std::endl<<"   "<<safhe[1][0]<<"\t|"<<"   "<<safhe[1][1]<<"\t|"<<"   "<<safhe[1][2]<<std::endl;
	std::cout<<"________|_______|________"<<std::endl;
	std::cout<<"\t|\t|"<<std::endl<<"\t|\t|"<<std::endl<<"   "<<safhe[2][0]<<"\t|"<<"   "<<safhe[2][1]<<"\t|"<<"   "<<safhe[2][2]<<std::endl<<"\t|\t|"<<std::endl;
}

void nobat(){
 if(turn == 'X')
 	{
        std::cout<<"\n "<<name1<<"'s [X] turn : ";
    }
    else if(turn == 'O'){
        std::cout<<"\n "<<name2<<"'s [O] turn : ";
    }
    std::cin>>chs;
    std::cin.clear();
	std::cin.ignore();

	
  	switch(chs){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default: std::cout<<"Invalid Move\a";
        nobat();
}
 if(turn == 'X' && safhe[row][column] != 'X' && safhe[row][column] != 'O'){
safhe[row][column] = 'X';
turn = 'O';
    }
    else if(turn == 'O' && safhe[row][column] != 'X' && safhe[row][column] != 'O'){
    	safhe[row][column] = 'O';
    	turn = 'X';
    }
    else {
        std::cout<<"Place is already taken!\n Please choose another!\a\n\n\n";
        nobat();
    }
}

bool gameover()
{
    for(int i=0; i<3; i++)
    if(safhe[i][0] == safhe[i][1] && safhe[i][0] == safhe[i][2] || safhe[0][i] == safhe[1][i] && safhe[0][i] == safhe[2][i])
    return false;

    if(safhe[0][0] == safhe[1][1] && safhe[0][0] == safhe[2][2] || safhe[0][2] == safhe[1][1] && safhe[0][2] == safhe[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(safhe[i][j] != 'X' && safhe[i][j] != 'O')
    return true;

    draw = true;
    return false;
}


int main()
{
	std::cout<<"\t\t\tWelcome to the Tic Tac Toe game (A.K.A XO) By Alireza Shojaei\n";
	std::cout<<"Player #1 Please introduce youself\nwhat is your name?\n";
    std::getline(std::cin,name1);
    std::cout<<"Hello "<<name1<<", And Welcome\n\n";
	std::cout<<"And What about you Player #2? Why won't you introduce yourself as well?\nWhat is your name?\n\n"; 
	 std::getline(std::cin,name2);    
	  std::cout<<"greetings "<<name2<<" And nice to meet you. ^_^\n So shall we begin, then?";
while(gameover()){
        namayesh();
        nobat();
        gameover();
    }
    namayesh();
    if(turn == 'X' && draw == false){
    	std::cout<<"Congragulations! "<<name2<<" has won the game ^o^\a";
    }
     else if(turn == 'O' && draw == false){
        std::cout<<"Congratulations! "<<name1<<" has won the game ^_*\a";
    }
    else
    std::cout<<"GAME is a draw!!! =_= \a\n";
}

