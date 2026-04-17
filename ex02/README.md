> [!NOTE]
> *This project is IN PROGRESS and is done by Zsofia A. Palotas as part of the 42 School common core curriculum*

# Summary
This porject is an implementation of the Ford-Johonson sorting algorithm.<br />
The aim is to make the least amount of comparisons during the sorting.
A visual explanation af what is happening can be viewed on this [Miro board](https://miro.com/app/board/uXjVGqjDL_s=/?share_link_id=910364214413) created by me
<br />

## Notes
- The algorithm takes non-negative integers as input 
- Uses two kinds of STL containers and compares time-performance
- It has to make comparisons under the maximum limit, otherwise the implementation would be incorrect (explained on the Miro board)

# Current state
The tasks requires to compare how two different containers would perform. This is not implemented yet.<br />
1 test (empty input) seemingly fails because of how the tester script processes.   

# Tester
Tests for this projects are located in the tests/tests_ex02 subdirectory<br />
More tests can be added with arbitrary name and *.input* extension<br />
Run from the root directory: 
```
./tester.sh
```
> This will make the executable for this project<br />
> Generate the expected output for each test (based on STL::sort)<br />
> Compare the outputs<br />
> Validate the comparison count against the max limit<br />