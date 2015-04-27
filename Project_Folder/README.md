# Myers_CSCI2270_FinalProject
Final Project
  This project is a Deck of Cards, and has various methods of shuffling and sorting. There are six different functions to choose from within the program, all described in the main menu. You can make a deck of 52 standard playing cards of 4 suits and 13 values (2 through ace). Aces are high. you can shuffle the deck using handShuffle, which cuts the deck and evenly mashes it together; cutDeck, which cuts the deck; shuffleDeck, which combines handShuffle and cut; and classicShuffle, which randomizes the deck. You can also sort the deck by value (ignoring suit) and by suit (ignoring value)
  To run the program, download the Project_Folder in the repo, and put all the files int the same folder in your VM. Run project_driver.cpp to launch the main menu. From there, follow the menus instructions and press the number of the option you would like to choose. You must press 1 before any other numbers.
  There are no specific third party dependencies other than the c++ <time.h> library, included in most IDE's inlucing CodeBlocks and Geany. As wel there are also no specific system requirements for this file. if your computer can run the VM, it can run this program.
  I was alone on this project, but help was given by Michael Vinneau and advice from Tyler Scott.
  There is only one known bug in the code, which is a segmentation fault along with some strange symbols. It only occurs after shuffling the deck more than two or three times, then calling sortByValue(). Any help or recommendations would be greatly appreciated.
  To whom it may concern, this program was written in Geany
  Enjoy!
