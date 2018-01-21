[Bulls and Cows](https://en.wikipedia.org/wiki/Bulls_and_Cows) is the game predating the Mastermind,
also very similar to it but with 10 digits instead of 6 colors.

This project is about an implementation of the game on C++, along with a hard-coded AI for it,
attempting to break the chosen random code intelligently with the least amount of moves.
It utilizes a custom made strategy, and probably isn't as good as the known best algorithm.

This version of the game also does not allow repeated digits. All the digits you or the AI enters
must be unique.

## Quick Start

I have added compiled and built two versions of the game for the ones who just want to see or play it:

1) One for playing the game as a human, called `GuessTheNumber (human player).exe`
2) One for seeing my algorithm playing it, called `GuessTheNumber (AI player).exe`

Feel free to just download and play them.

**Note:** If the console window immediately closes as the game finishes, run it from
the console window you have opened yourself to examine the results. On Windows, you do it by:

1) Go to wherever the EXE file is.
2) Hold shift key, right-click to the containing folder (or the desktop if it is on the desktop).
3) Select "Open PowerShell window here" (might be Command Line, too) or its translations to your OS language.
4) Type the name of the application, or just some of its first letters and hit the tab key.
5) Hit enter.

## Rules of the Game

Instead of "cows" and "bulls", the program talks about plusses and minusses.
This is because my friend who had shown me the game for the first time back then in
the Autumn of 2015, told me that this is how we play the game.
As mentioned before, the digits also need to be unique, for the same reason.

If you already know the Mastermind or the Cows and Bulls, you may skip this part.
For the rest, here's how you play this game:

1) You choose any code of 4 digits, each one from 0 to 9.
2) Your opponent tries to guess your 4 digits in the proper order.
3) For each guess of them, you give a feedback as follows:
    1) Plus, the amount of digits that are truly correct, both in position and digit, such as **+2**.
    2) For the remaining digits, minus, the amount of digits that are existent in the code, but at a different position, such as **-1**.
4) Go back to step 2, until the opponent receives a **+4**.

Two players may play simultaneously against each other, turn based, for the game to be more social and fun.

For some example feedbacks, you may compile and run the solution in this repository,
and see some example feedbacks for some guesses, given a pre-determined random code.

## Running the Application

Running the application, you can see the guesses of the AI and the feedbacks of the game to them.
The AI considers its previous guesses and the feedbacks given to them, and tries to find its way
through to the 4-digit-code the game has picked initially.

The `source.cpp` can be modified slightly to change the amount of digits on the code from 4 to anything
else, and to make the game human-playable. The repository already includes a human-playable or
AI-player variants for 4 digits built for Windows as executables.

As a human player, you may enter your digits as you wish, separated by spaces or not.
The game will then give you a feedback, and then you can keep on playing and guessing.
