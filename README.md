Dictionary Using C++

A console-based dictionary and word-gaming application built with C++. This project allows users to search for word definitions, find synonyms, and play interactive games like "Guess the Word" and a Text-to-Speech (TTS) enabled "Spelling Bee".
Features

 Word Search: Quickly find the definition of a word from a large database of nearly 90,000 entries.

 Synonym Lookup: Retrieve synonyms for words to expand your vocabulary.

 Word of the Day: Displays a random word, its definition, and synonyms to help you learn something new each time.

 Guess the Word Quiz: An interactive challenge where you must identify a word based on its definition, with hints provided after incorrect attempts.

 Spelling Bee (Linux only): A voice-enabled game that uses the festival Text-to-Speech engine to pronounce words for you to spell.

 Cross-Platform Support: Includes logic to clear the terminal screen on both Windows and Linux systems.

File Structure

   dictionary.cpp: The main source code containing all program logic and interactive menus.

   wordlist.txt: The primary database containing words and their definitions.

   synons.txt: A secondary data file containing synonyms for the dictionary entries.

Prerequisites

   Compiler: A C++ compiler (supporting at least C++23 is recommended based on project settings).

   Linux Dependencies: For the "Spelling Bee" feature, the festival TTS engine must be installed on your system.

Installation & Setup

   Clone the Repository:
    Bash

    git clone https://github.com/haggai333/dictionary-using-cpp.git
    cd dictionary-using-cpp

   Compile the Application:
   Using G++, run:
   Bash

    g++ -o dictionary dictionary.cpp

   Run the Program:
    Bash

    ./dictionary

   Note: Ensure wordlist.txt and synons.txt are in the same directory as the executable.

How to Use

When the program starts, it loads the data files and displays a main menu with the following options:

   Search a word: Enter a word to see its full definition.

   Get synonym: Look up synonyms for a specific word.

   Get word of the day: Displays a random entry from the database.

   Play guess the word quiz: You have 3 tries to guess a word based on its definition.

   Play spelling bee quiz: Listen to the word and type the correct spelling (requires Linux and festival).

    Exit: Closes the application.
