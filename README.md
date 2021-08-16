# minishell

## Description

With a partner, we wrote a simple shell.

In this project, we use some functions from [my libft library](https://github.com/VitMarKha/libft), as well as some functions we modify.

The compilation was performed as follows: ``gcc -Wall -Wextra -Werror``.

All files pass to ``Norminette``.

No memory leaks.

## Requirements

* Not use more than one global variable, think about it and be ready to explain why you do it.
* Show a prompt when waiting for a new command. 
* Search and launch the right executable (based on the PATH variable or by using relative or absolute path) like in bash. 
* It must implement the builtins like in bash:
    * **echo** with option ’-n’. 
    * **cd** with only a relative or absolute path. 
    * **pwd** without any options. 
    * **export** without any options. 
    * **unset** without any options. 
    * **env** without any options and any arguments ◦ exit without any options. 
* **;** in the command should separate commands like in bash. 
* **’** and **"** should work like in bash except for multiline commands. 
* Redirections **<**, **>**, **>>** should work like in bash except for file descriptor aggregation. 
* Pipes **|** should work like in bash except for multiline commands. 
* Environment variables ($ followed by characters) should work like in bash. 
* **$?** should work like in bash. 
* **ctrl-C**, **ctrl-D** and **ctrl-\\** should have the same result as in bash. 
* Use up and down arrows to navigate through the command using termcap (mandatory) history which we will then be able to edit (at least like we can for classic lines) if we feel like it (the line, not the history).

## Using

``make`` and ``make all`` compile the library ``libfе.a``, placing them in the root folder.

``make re`` deletes all ``.o`` files, deletes ``libfе.a``, rebuilds the project.

``make clean`` deletes all ``.o`` files.

``make fclean`` deletes all ``.o`` files, also deletes ``libfе.a`` and ``minishell_history``.

Starting the program: ``./minishell``.
