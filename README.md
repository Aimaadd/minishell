
# Minishell

A minimalist shell implementation created as part of the [42 School](https://www.42.fr/) curriculum. **Minishell** replicates core functionalities of a Unix shell while adhering to the project specifications.

## Table of Contents
- [About the Project](#about-the-project)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Technologies Used](#technologies-used)
- [Acknowledgments](#acknowledgments)

---

## About the Project

**Minishell** is a custom-built Unix shell designed to help developers understand the inner workings of command-line interpreters. It provides a hands-on approach to learning how a shell processes and executes user commands while managing system resources.

This project emphasizes:
- Parsing user inputs.
- Implementing built-in shell commands.
- Handling process creation and inter-process communication.
- Managing signals and memory effectively.

---

## Features

- **Command Execution**: Executes common Unix commands such as `ls`, `cat`, etc.
- **Built-in Commands**: Implements shell-specific commands like `cd`, `echo`, `exit`, and more.
- **Input Parsing**: Properly handles quotes, special characters, and redirections (`<`, `>`, `|`).
- **Environment Variables**: Expands variables like `$PATH` or user-defined variables.
- **Signal Handling**: Gracefully manages signals such as `CTRL+C` and `CTRL+D`.
- **Error Management**: Provides meaningful error messages for invalid inputs or system issues.

---

## Installation

### Prerequisites
Ensure the following are installed on your system:
- **GCC** (or any compatible C compiler)
- **Make**

### Clone the Repository
```bash
git clone https://github.com/Aimaadd/minishell.git
cd minishell
```

### Build the Project
Run the following command to compile the program:
```bash
make
```

This will generate the `minishell` executable in the project directory.

---

## Usage

### Launch the Shell
Start **Minishell** by running:
```bash
./minishell
```

### Example Commands
Once the shell is launched, you can execute commands like:
```bash
echo "Hello, world!"
cd /path/to/directory
ls -la
export VAR=value
exit
```

### Exiting the Shell
Type `exit` or press `CTRL+D` to exit.

---

## Technologies Used

- **C Programming Language**
- Unix system calls and libraries
- Custom-built parser and lexer

---

## Acknowledgments

This project was created as part of the **42 School** curriculum. Special thanks to the 42 community and my collaborators for their support and insights.
