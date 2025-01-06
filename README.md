# Simple Shell Project

## Project Overview
The **Simple Shell** project is a custom implementation of a Unix shell. It replicates the behavior of `/bin/sh` and allows users to execute commands interactively or non-interactively. This project is part of the curriculum at Holberton School and aims to strengthen the understanding of system calls, memory management, and process handling.

### Purpose
The purpose of this project is to:
- Understand how a Unix shell works internally.
- Gain hands-on experience with system calls, process management, and I/O redirection.
- Improve programming skills in C by building a functional shell.

### Main Features
1. Displays a prompt and waits for user input.
2. Executes commands with or without arguments.
3. Resolves commands using the `PATH` environment variable.
4. Handles errors gracefully and supports `Ctrl+D` (EOF).
5. Implements built-in commands like `exit` and `env`.

### Current Implementation
1. **Task 0**:
   - Created `README.md`, `man_1_simple_shell`, and `AUTHORS` files.
2. **Task 1**:
   - Code complies with the Betty coding style guidelines.
3. **Task 2**:
   - Displays a prompt and waits for user commands.
   - Executes simple commands without arguments.
   - Handles errors gracefully.
   - Supports the `Ctrl+D` EOF condition.
4. **Task 3**:
   - Executes commands with arguments.
5. **Task 4**:
   - Resolves commands using the `PATH` variable.
   - Ensures `fork()` is not called if a command doesn’t exist.
6. **Task 5**:
   - Implements the `exit` built-in command to terminate the shell.
7. **Task 6**:
   - Implements the `env` built-in to display the current environment.

### Intended Audience
This project is designed for:
- Students and professionals interested in system programming.
- Individuals seeking to deepen their knowledge of Unix-like operating systems.
- Developers exploring how command-line interfaces work.


---


### Compilation Instructions
To compile the shell, use:
-```bash
'gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh' on Ubuntu 20.04 LTS.

## Language
The creation of the Simple Shell project is written in C and adheres to the GNU89 standard.

## Contributors
This project was completed as a team effort by:

**Judith Espinal:** [GitHub Profile](https://github.com/judiihh)
[LinkedIn Profile](https://www.linkedin.com/in/judithespinal12)

Hello, I'm Judith Espinal, one of the developers behind this project. I invite you to explore my work and connect with me professionally on LinkedIn. I look forward to networking and sharing ideas with you!

**Adolfo Rodriguez:** [GitHub Profile](https://github.com/Adolfo2231)
[LinkedIn Profile](https://www.linkedin.com/in/adolfo-rodr%C3%ADguez-06393b339/)
