//Final Project class file
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include "final_project.h"
/*The constructor is called when the object is created.
 * Its main purpose is to create the deck pointer array
 * mentioned in the header file and set all the pointers
 * in the array to NULL to prevent memory leaks. Better
 * Safe than Sorry.
 */
CardDeck::CardDeck(){//constructor
	for(int i = 0; i < 52; i++){
		deck[i] = NULL;
	}
}
/*The deconstructor is not specifically called except when
 * the program terminates. Although it is necesary for the
 * code to run, it has no specific funtion to the code itself
 */
CardDeck::~CardDeck(){//deconstructor

}
/*The showMenu function gives you all the options available
 * in the code, including quit. It has no pre-conditions
 * and shows the menu as a post-condition.
 */
void CardDeck::showMenu(){//displays menu
    std::cout << std::endl;
	std::cout<<"1. Create Deck"<<std::endl;
	std::cout<<"2. Shuffle Deck"<<std::endl;
	std::cout<<"3. Hand Shuffle Deck"<<std::endl;
	std::cout<<"4. Sort Deck by Value"<<std::endl;
	std::cout<<"5. Sort Deck by Suit"<<std::endl;
	std::cout<<"6. Cut Deck"<<std::endl;
	std::cout<<"7. Classic Shuffle" <<std::endl;
	std::cout<<"8. Quit"<<std::endl;
}
/*the makeDeck function makes the Deck. It takes the initialized
 * array in the constructor and fills it with 52 cards of the
 * four suits and 13 values (2-Ace ace high). It has no
 * pre-conditions and shoud display ecery card in the deck in
 * order of suit and number.
 */
void CardDeck::makeDeck(){//makes a deck of Card sturctures
	for(int i = 0; i < 52; i++){
		deck[i] = new Card;
		if(i >= 0 && i < 13){
			deck[i]->value = i+2;
			deck[i]->suit = "Spades";
			//std::cout<<i<<"||"<<deck[i]->value<<" of "<<deck[i]->suit<<std::endl;
		}
		if(i >= 13 && i < 26){
			deck[i]->value = i-11;
			deck[i]->suit = "Hearts";
			//std::cout<<i<<"||"<<deck[i]->value<<" of "<<deck[i]->suit<<std::endl;
		}
		if(i >=26 && i < 39){
			deck[i]->value = i-24;
			deck[i]->suit = "Clubs";
			//std::cout<<i<<"||"<<deck[i]->value<<" of "<<deck[i]->suit<<std::endl;
		}
		if(i >=39 && i < 52){
			deck[i]->value = i-37;
			deck[i]->suit = "Diamonds";
			//std::cout<<i<<"||"<<deck[i]->value<<" of "<<deck[i]->suit<<std::endl;
		}
	}
	std::cout<<"Cards in Order"<<std::endl;
	std::cout<<"--------------"<<std::endl;
	for(int j = 0; j < 52; j++){
		if(deck[j]->value >= 2 and deck[j]->value <= 10){
			deck[j]->name = std::to_string(deck[j]->value);
		}
		if(deck[j]->value == 11){
			deck[j]->name = "Jack";
		}
		if(deck[j]->value == 12){
			deck[j]->name ="Queen";
		}
		if(deck[j]->value == 13){
			deck[j]->name ="King";
		}
		if(deck[j]->value == 14){
			deck[j]->name = "Ace";
		}

		std::cout<<deck[j]->name<<" of "<<deck[j]->suit<<std::endl;
	}
}
/*handShuffle is the closest function to an actual hand shuffle
 * there is. First, the Cards are split into two equal piles of 26,
 * then linked together in a linked list of Cards so that the
 * piles mash together as if you were perfectly shuffling a deck.
 * This function can only be used after the makeDeck function is
 * called. This should shuffle the deck with some patterns
 */
void CardDeck::handShuffle(){//cuts the deck in half and evenly mashes the cards together, similar to a normal hand shuffle. Uses a linked list
	/*ShuffleList *head = new ShuffleList;
	head->cardptr = deck[51];
	for(int i = 26; i > 0; i--){
		ShuffleList *temp = new ShuffleList;
		ShuffleList *temp2 = new ShuffleList;
		temp->cardptr = deck[24+i];
		temp2->cardptr = deck[i];
		temp->next = temp2;
		temp2->next = head;
		head = temp;
	}
	for(int j = 0; j < 52; j++){
		deck[j] = head->cardptr;
		head = head->next;
		std::cout<<deck[j]->name<<" of "<<deck[j]->suit<<std::endl;
	}*/

	//create a temporary copy of the deck
	Card* temp[52];
	for (int i = 0; i < 52; i++){
        temp[i] = deck[i];
	}

    //replace with every other value
	for (int i = 0; i < 26; i++){
        deck[2*i] = temp[i];
        deck[2*i + 1] = temp[26 + i];
	}

    //print new deck
	for (int i = 0; i < 52; i++){
        std::cout<<deck[i]->name<<" of "<<deck[i]->suit<<std::endl;
    }
	std::cout<<"--------"<<std::endl;
}
/*cutDeck takes a random card between 11 and 29, takes the cards
 * below the random card and puts them on top, then put the
 * remaining cards in order on the bottom. Once again, the deck
 * must be created and filled before this function is called,
 * and it should cut the deck randomly.
 */
void CardDeck::cutDeck(){//cuts the deck at a random card around half
	int cut = rand()% 11 + 29;
	Card *newDeck[52];
	//std::cout<<cut<<std::endl;
	for(int k = 0; k < 52-cut; k++){//0 to 16
		newDeck[k] = deck[cut+k];
	}
	for(int i = 0; i < cut; i++){//0 to 34
		newDeck[52-cut+i] = deck[i];//17 to 51
	}
	for(int j = 0; j < 52; j++){
		deck[j] = newDeck[j];
		std::cout<<deck[j]->name<<" of "<<deck[j]->suit<<std::endl;
	}
}
/*the sortBySuit function sorts the entire deck by suit with
 * a single pass. It requires the makeDeck function to be called
 * and sorts the deck by suit, ignoring value.
 */
void CardDeck::sortBySuit(){//sorts cards by suit only, ignoring value
	Card *suitArr[52];
	int spade_count = 0;
	int heart_count = 13;
	int diam_count = 26;
	int club_count = 39;
	for(int i = 0; i < 52; i++){
		if(deck[i]->suit == "Spades"){
			suitArr[spade_count] = deck[i];
			spade_count++;
		}
		if(deck[i]->suit == "Hearts"){
			suitArr[heart_count] = deck[i];
			heart_count++;
		}
		if(deck[i]->suit == "Clubs"){
			suitArr[diam_count] = deck[i];
			diam_count++;
		}
		if(deck[i]->suit == "Diamonds"){
			suitArr[club_count] = deck[i];
			club_count++;
		}
	}
	for(int j = 0; j < 52; j++){
		deck[j] = suitArr[j];
		std::cout<<deck[j]->name<<" of "<<deck[j]->suit<<std::endl;
	}
}
/*sortbyValue is the opposite of sortBySuit in that it ignores
 * suit and only adressed value. It requires the makeDeck function
 * as well as only being called within the first three methods due
 * to some internal errors. If called soon after makeDeck is called
 * it should print the entire deck sorted by value (Ace High).
 */
void CardDeck::sortByValue(){//sorts cards by value only, ignoring suit
	Card *valDeck[52];
	int ace_count = 0;
	int king_count = 4;
	int queen_count = 8;
	int jack_count = 12;
	int ten_count = 16;
	int nine_count = 20;
	int eight_count = 24;
	int seven_count = 28;
	int six_count = 32;
	int five_count = 36;
	int four_count = 40;
	int three_count = 44;
	int two_count = 48;
	/*for(int i = 0; i < 52; i++){
        std::cout << deck[i]->value << std::endl;
	}*/

	for(int i = 0; i < 52; i++){

	//std::cout << i <<" " << deck[i]->value << std::endl;
		if(deck[i]->value == 14){
			valDeck[ace_count] = deck[i];
			ace_count++;
		}
		if(deck[i]->value == 13){
			valDeck[king_count] = deck[i];
			king_count++;
		}
		if(deck[i]->value == 12){
			valDeck[queen_count] = deck[i];
			queen_count++;
		}
		if(deck[i]->value == 11){
			valDeck[jack_count] = deck[i];
			jack_count++;
		}
		if(deck[i]->value == 10){
			valDeck[ten_count] = deck[i];
			ten_count++;
		}
		if(deck[i]->value == 9){
			valDeck[nine_count] = deck[i];
			nine_count++;
		}
		if(deck[i]->value == 8){
			valDeck[eight_count] = deck[i];
			eight_count++;
		}
		if(deck[i]->value == 7){
			valDeck[seven_count] = deck[i];
			seven_count++;
		}
		if(deck[i]->value == 6){
			valDeck[six_count] = deck[i];
			six_count++;
		}
		if(deck[i]->value == 5){
			valDeck[five_count] = deck[i];
			five_count++;
		}
		if(deck[i]->value == 4){
			valDeck[four_count] = deck[i];
			four_count++;
		}
		if(deck[i]->value == 3){
			valDeck[three_count] = deck[i];
			three_count++;
		}
		if(deck[i]->value == 2){
			valDeck[two_count] = deck[i];
			two_count++;
		}
	}


	for(int j = 0; j < 52; j++){
		deck[j] = valDeck[j];
		std::cout<<deck[j]->name<<" of "<<deck[j]->suit<<std::endl;
	}
}
/*shuffleDeck is a combination of handShuffle and cutDeck. It
 * handShuffles and cuts the deck a random number of times between
 * one and six. it requires the handShuffle and cutDeck functions
 * to be made as well as the deck to be created and filled. it shuffles
 * the entire deck quite well.
 */
void CardDeck::shuffleDeck(){
    //rand()%1+5 is always five. I changed it to 10 so now it will be between 5 and 15
	int shuffle = rand()% 10 + 5;
	for(int i = 0; i < shuffle; i++){
		handShuffle();
		cutDeck();
	}
}
/*swap is simply a helper function to classicShuffle. It takes two cards
 * and switches them. It is never directly called, and only requires the
 * two cards to switch. It takes a min and max of two argumants.
 */
void CardDeck::swap(Card *a, Card *b){//swaps two cards, used in Classic Shuffle
	Card temp = *a;
	*a = *b;
	*b = temp;
}
/*classicShuffle uses a classic randomizing algorith to randomly pairs of
 * cards throughout the deck. It is a fairly efficient shuffling algorithm.
 * it requres the deck to be filled and the swap function to have been
 * created, as it directly calles the swap function.
 */
void CardDeck::classicShuffle(){
	int n = sizeof(deck)/sizeof(deck[0]);
	srand(time(NULL));
	for(int i = n-1; i > 0; i--){
		int j = rand()% (i+1);
		swap(deck[i], deck[j]);
	}
	for(int j = 0; j < 52; j++){
		std::cout<<deck[j]->name<<" of "<<deck[j]->suit<<std::endl;
	}
}
