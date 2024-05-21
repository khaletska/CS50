# CS50

## Problem Set 0 - Scratch

Simple brick breaker game created in Scratch. Press green flag to start the game, move the platform with right/left arrow keys. Break all the bricks to win the game. [Play here](https://scratch.mit.edu/projects/1019545862).

## Problem Set 1 - C

1. [_Hello, world._](/Week_1_C/world/hello.c)

2. [_Hello, it's me!_](/Week_1_C/me/hello.c) Asks for your name and prints "hello, \<name\>".

3. [_Mario._](/Week_1_C/mario-more/mario.c) Recreates that pyramid of given size between 1 and 8 using hashes (#) for bricks, as in the below:

```
   #  #
  ##  ##
 ###  ###
####  ####
```

4. [_Credit._](/Week_1_C/credit/credit.c) Checks the validity of a given credit card number.

## Problem Set 2 - Arrays

1. [_Scrabble._](/Week_2_Arrays/scrabble/scrabble.c) The program prompts for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. Then, depending on which player scores the most points, it either prints “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).
2. [_Readability._](/Week_2_Arrays/readability/readability.c) A program that prompts user for some text and calculates the approximate grade level needed to comprehend it.

#### Usage:

`./readability <text>`

3. [_Substitution._](/Week_2_Arrays/substitution/substitution.c) The program “encrypts” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it.

#### Usage:

`./substitution <key>`

## Problem Set 3 - Algorithms

1. [_Sort._](/Week_3_Algorithms/sort/answers.txt) The task was to analyse three sorting programs and their performance for different arrays. Then conclude which one of three is Bubble sort, Selection sort or Merge sort.
2. [_Plurality._](/Week_3_Algorithms/plurality/plurality.c) The program simulates voting process: every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

#### Usage:

`./plurality <candidates names>`

3. [_Tideman._](/Week_3_Algorithms/tideman/tideman.c) Tideman is a voting system algorithm that determines the winner of an election using a ranked-choice voting method. In this system, voters can rank candidates in order of preference. The Tideman algorithm pairs every candidate against every other candidate and counts the number of voters who prefer one candidate over the other. The candidate who wins the most pairings is declared the winner. This algorithm is designed to provide a fair and democratic election outcome.

#### Usage:

`./tideman <candidates names>`
