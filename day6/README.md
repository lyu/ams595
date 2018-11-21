## GDB - The GNU C/C++ Debugger

* To compile a program for the debugger, add the `-g` flag

    `g++ -std=c++11 -g foo.cpp -o foo`

* Launch the debugger (with a graphical interface)

    `gdb -tui ./foo`

You can try gdb with `day6_test.cpp`, set a breakpoint at `main`, then step over each line of the program.

## Basic GDB commands

`b <function_name>`: Set a breakpoint at the entry of some function, so your program will pause there

`b <line_number>`: Set a breakpoint at a given line number

`info break`: To see all the breakpoints and their IDs

`del <ID>`: Remove a breakpoint using its ID

`r`: Run the program (start the execution)

`s`: Execute the line under the cursor when the execution is paused (single step)

`c`: Continue the execution after a breakpoint

`info locals`: Print info about local variables

`p <variable_name>`: Print the value of some variable

`set variable <variable_name> = <new_value>`: Modify a variable's value
