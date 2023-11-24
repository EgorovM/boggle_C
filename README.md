# Boggle Solver in C
## Overview
This Boggle Solver is a C program designed to find words in a Boggle game grid. Boggle is a word game where players attempt to find words in sequences of adjacent letters within a grid. In this implementation, the program takes a pre-defined grid and a word to search for within that grid. If the word is found, it displays the grid with the word highlighted in uppercase letters; if not, it outputs an error message.

## How to Compile and Run
### Prerequisites
- GCC compiler (or any standard C compiler)
- Make (optional for compilation)
### Compilation
To compile the program, you can use the following command if you have a Makefile:
```bash
make
```

### Running the Program
Usage: ./boggle -g GRID [-s SIZE] [-w WORD]
- -s SIZE defines the size of a side of the grid (def: 4)
- -g GRID specifies a hard-coded grid (MANDATORY). If the grid does not contain the
correct number of characters, you must display an error.
- -w WORD force the word to be looked for.

## Examples:

```bash
$ ./boggle -g "lqnelooelbtelqte" -w stem
The word "stem" is not in the grid.
```

```bash
$ ./boggle -g "lqnelooelbtelqte" -w noob
+++++++++++
| l q N e |
| l O O e |
| l B t e |
| l q t e |
+++++++++++
```

```bash
$ ./boggle -g "lqnelooelbtelqte"        
+++++++++++
| l q n e |
| l o o e |
| l b t e |
| l q t e |
+++++++++++
> stem
The word "stem" is not in the grid.
> noob
+++++++++++
| l q N e |
| l O O e |
| l B t e |
| l q t e |
+++++++++++
```