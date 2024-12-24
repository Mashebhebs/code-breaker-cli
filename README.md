# Code Breaker CLI

A simple command-line-based Codebreaker game implemented in C++. This game challenges the player to guess a randomly generated 4-digit secret code within 12 attempts.

# Features

  - Random generation of a 4-digit code with unique digits.
  - Feedback on:
    - Correct digits in the correct position.
    - Correct digits in the incorrect position.
  - User-friendly interface with input validation.
  - Limited attempts to increase the challenge.

# How to Play

  1. Run the program to start the game.
  2. Enter a 4-digit number as your guess (digits range from 1 to 8, and all digits are unique).
  3. The program will provide feedback after each guess:
     - How many digits are correct and in the correct position.
     - How many digits are correct but in the wrong position.
  4. You have 12 attempts to guess the correct code.
  5. If you fail, the program will reveal the secret code.

# Example Gameplay

      4-digit Code has been set. Digits in range 1 to 8. You have 12 turns to break it.
      Input 4-digit code: 1234
      Number of correct digits in correct place:     1
      Number of correct digits not in correct place: 2
      Turns left: 11
      Input 4-digit code: 5678
      Number of correct digits in correct place:     0
      Number of correct digits not in correct place: 1
      Turns left: 10
      Input 4-digit code: 5732
      Congratulations! You are a codebreaker!
      The code was: 5732

# Requirements 
      - C++ compiler (e.g., GCC, Clang, MSVC) with support for C++11 or higher.)

# How to Build and Run
  ## Clone this repository:
    git clone https://github.com/Mashebhebs/code-breaker-cli.git
    cd code-breaker-cli/src

# Compile the program:
    g++ -o codebreaker codebreaker.cpp`

# Run the program:

    ./codebreaker

# File Structure
    code-breaker-cli/
    ├── src/
    │   └── codebreaker.cpp  
    └── README.md    

# Future Improvements
Add a difficulty selection option (e.g., longer codes or more attempts).
Enhance the game logic with hints for the user.
Implement a scoring system based on performance.






