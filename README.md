> [!NOTE]
> *This project is IN PROGRESS and is done by Zsofia A. Palotas as part of the 42 School common core curriculum*

# Summary
There are three separate projects in this module.
1. Lookup the value of bitcoin on a  certain day - *Not started*
2. Reverse Polish Notation calculator - *Testing*
3. Ford-Johonson algorithm - *In progress*
<br />

## Notes
- The algorithm takes non-negative integers as input 
- Uses two kinds of STL containers and compares time-performance
- It has to make comparisons under the maximum limit, otherwise the implementation would be incorrect (explained on the Miro board)

# Current state
For typical case the algorithm performs well, however it has issues with duplicates, and high element count.<br />
There is no parsing implemented yet to check for invalid inputs. 

# Tester
Tests for these projects are located in the tests/ directory and corresponding subdirectory<br />
Run from the root directory: 
```
./tester.sh
```
> This will make the executable for this project<br />
> Generate the expected output for each test (based on STL::sort)<br />
> Compare the outputs<br />
> Validate the comparison count against the max limit<br />