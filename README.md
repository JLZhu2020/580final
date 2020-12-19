# cpp-final-project Jiale Zhu ,Kangan Hu
## How to use?
### after running the command make, you should use command:
##### ./main.exe 1 S N 
### to let program use function generateSandpile to generate a SxS random sandpile, S means the size of sandpile, N means how many sand.or you use command:
##### ./main.exe 2 filename
### to let program use function readASandpile to read a file and gerenate a sandpile, for instance 
##### ./main.exe 2 data/sandpile_100x100_triangles.dat
### if your input parameter are not like above, the program will output
##### invalid parameter!
### and stop.

## Problem meet during coding
when we start to do the project, the first function we try to complete is generateSandpile. We create the sandpile by Sandpile sp(S); the vscode could compile the file to main.exe, but when we tried to use 
##### ./main.exe, 
it will output a very strange message
##### segmentation fault
we spend long time to fix it, finally we known we chould create the sandpile by Sandpile sp
