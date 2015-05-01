//project driver
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "project_file1.cpp"
using namespace std;
int main(){
	CardDeck DeckObj;
	int input;
	while(input != 8){
        DeckObj.showMenu();
		cin>>input;
		if(input == 1){
			cin.ignore();
			DeckObj.makeDeck();
			input = 0;
		}
		else if(input == 2){
			cin.ignore();
			DeckObj.shuffleDeck();
			input = 0;
		}
		else if(input == 3){
			cin.ignore();
			DeckObj.handShuffle();
			input = 0;
		}
		else if(input == 4){
			cin.ignore();
			DeckObj.sortByValue();
			input = 0;
		}
		else if(input == 5){
			cin.ignore();
			DeckObj.sortBySuit();
			input = 0;
		}
		else if(input == 6){
			cin.ignore();
			DeckObj.cutDeck();
			input = 0;
		}
		else if(input == 7){
			cin.ignore();
			DeckObj.classicShuffle();
			input = 0;
		}
		else if(input == 8){
			cin.ignore();
			input = 0;
			return 0;
		}
	}
	return 0;
}
