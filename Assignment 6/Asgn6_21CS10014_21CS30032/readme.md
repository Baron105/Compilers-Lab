# Instruction to run the code

- To get the executable file tinyC run `make` command in the terminal.
- TO run on the test data run `make test` in the terminal.
- The outputs are located in the test-outputs folder and the .s files are also generated.
- To remove all the temporary files run `make clean` .

## Shortcomings in doing the assignment

- We were unable to modify the grammar to make it suitable to our problem statement and ended with segmentation faults while testing on test inputs . This might be due to poor semantic rules.
- A partial output of test1 is generated in the proper .s format , but due to segmentation faults , further output wasnt generated.
- We were  unable to incorporate the operations using float registers due to lack of information on the same.
