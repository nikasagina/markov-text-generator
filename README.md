# C++ Markov Model Text Generator

This is a C++ project that generates text based on a Markov model. The program reads in a text file, and builds a model of the text. It then generates new text based on this model.

## Requirements

1. C++ compiler
2. Text file to use as input

## Usage

1. Clone the repository or download the source code.
2. Open the terminal and navigate to the directory containing the source code.
3. Compile the source code using a C++ compiler.
4. Run the compiled executable in the terminal.
5. Enter the path of the text file to use as input.
6. Enter the value of k (an integer between 1 and 10) to specify the length of the sequence used in the Markov model.
7. The program will generate a text of 2000 characters based on the input text and display it in the terminal.

## How it works

The program reads in a text file and builds a Markov model. The model consists of a map where the keys are sequences of k characters and the values are vectors of characters that follow the key sequence in the text. The program then uses this model to generate a new text by starting with the most frequently occurring sequence in the input text and randomly choosing the next character based on the probabilities of the characters that follow the sequence in the input text.

## License

This project is licensed under the [MIT license](https://github.com/github/choosealicense.com/blob/gh-pages/LICENSE.md).
