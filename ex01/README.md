> [!NOTE]
> *This project is done by Zsofia A. Palotas as part of the 42 School common core curriculum*

# Summary
This porject is a [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) calculator.<br />
You can try it out [here](https://www.rpn-calc.com/) and also see a breakdown of the operations.<br />
The purpose of this notation is to write mathematical expressions **without the need for parentheses**. Placing operators after operands, makes it easy to process unambiguously in a stack-based manner.<br />

## Notes
Enter your expression as a single argument
```
./RPN "1 1 +" 
```

# Tester
Tests for this projects are located in the tests/tests_ex01 subdirectory<br />
More tests can be added with arbitrary name and *.input* extension<br />
Write your expected result in an *.expected* file with the same name<br />
Run from the root directory: 
```
./tester.sh
```
> - This will make the executable for this project<br />
> - Compare the outputs<br />