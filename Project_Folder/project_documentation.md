
		CardDeck();
		/*The constructor is called when the object is created.
		 * Its main purpose is to create the deck pointer array
		 * mentioned in the header file and set all the pointers 
		 * in the array to NULL to prevent memory leaks. Better
		 * Safe than Sorry.
		 */
		virtual ~CardDeck();
		/*The deconstructor is not specifically called except when
		 * the program terminates. Although it is necesary for the 
		 * code to run, it has no specific funtion to the code itself
		 */
		void showMenu();
		/*The showMenu function gives you all the options available
		 * in the code, including quit. It has no pre-conditions
		 * and shows the menu as a post-condition.
		 */
		void makeDeck();
		/*the makeDeck function makes the Deck. It takes the initialized
		 * array in the constructor and fills it with 52 cards of the
		 * four suits and 13 values (2-Ace ace high). It has no
		 * pre-conditions and shoud display ecery card in the deck in 
		 * order of suit and number.
		 */
		void shuffleDeck();
		/*shuffleDeck is a combination of handShuffle and cutDeck. It 
		 * handShuffles and cuts the deck a random number of times between 
		 * one and six. it requires the handShuffle and cutDeck functions
		 * to be made as well as the deck to be created and filled. it shuffles
		 * the entire deck quite well.
		 */
		void handShuffle();
		/*handShuffle is the closest function to an actual hand shuffle 
		 * there is. First, the Cards are split into two equal piles of 26,
		 * then linked together in a linked list of Cards so that the 
		 * piles mash together as if you were perfectly shuffling a deck.
		 * This function can only be used after the makeDeck function is 
		 * called. This should shuffle the deck with some patterns
		 */
		void sortBySuit();
		/*the sortBySuit function sorts the entire deck by suit with
		 * a single pass. It requires the makeDeck function to be called
		 * and sorts the deck by suit, ignoring value.
		 */
		void sortByValue();
		/*sortbyValue is the opposite of sortBySuit in that it ignores
		 * suit and only adressed value. It requires the makeDeck function
		 * as well as only being called within the first three methods due 
		 * to some internal errors. If called soon after makeDeck is called
		 * it should print the entire deck sorted by value (Ace High).
		 */
		void cutDeck();
		/*cutDeck takes a random card between 11 and 29, takes the cards
		 * below the random card and puts them on top, then put the
		 * remaining cards in order on the bottom. Once again, the deck
		 * must be created and filled before this function is called,
		 * and it should cut the deck randomly.
		 */
		void classicShuffle();
		/*classicShuffle uses a classic randomizing algorith to randomly pairs of
		 * cards throughout the deck. It is a fairly efficient shuffling algorithm.
		 * it requres the deck to be filled and the swap function to have been 
		 * created, as it directly calles the swap function.
		 */
		void swap(Card *a, Card *b);
		/*swap is simply a helper function to classicShuffle. It takes two cards
		 * and switches them. It is never directly called, and only requires the 
		 * two cards to switch. It takes a min and max of two argumants.
		 */
