# Display-Board
A display board which can display alphabets and numbers with some limited effects.

## How To Run
1. Compiled by g++ main.cpp
2. Run exe file

## External File(.dat)
The program reads command from external file.

Description for each line in file:
1. Drawing character (optional, defaults to ‘#’)
2. Speed of refresh cycle
3. Phrase (max 25 chars), input can be of any case
4. Anchor point
5. Board size (optional, defaults to 20, 40)
6. Direction Wrap-around Rotation

- Direction: lr, rl, ud, du, st
- Wrap-around: wr (optional)
- Rotation: rot90, rot-90,mr (optional) 

## Input 
Type in the external filename.

![input]()

s_mr.dat content:

![dat file]()

## Output
The board will display a mirrored 'FANTASTIC' font (vertical reflection) by using symbol @

![output]()