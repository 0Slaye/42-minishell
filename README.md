![Banner](assets/banner.png)

# Working tree
|Theme|Ressource|State|
|--|--|--|
[Prompt](#Prompt)|[readline](https://man7.org/linux/man-pages/man3/readline.3.html)|need clear history on exit|
[Lexer](#Lexer)|[wikipedia](https://en.wikipedia.org/wiki/Lexical_analysis)|done|
[Parser](#Parser)|[booleanworld](https://www.booleanworld.com/building-recursive-descent-parsers-definitive-guide/)|done|
[Interpreter](#Interpreter)|[wikipedia](https://en.wikipedia.org/wiki/Interpreter_(computing))|done|
[Builtins](#Builtins)|[manual](https://www.man7.org/linux/man-pages/)|doing|
[Signals](#Signals)|[wikipedia](https://en.wikipedia.org/wiki/Bash_(Unix_shell))|todo|
[Leaks](#Leaks)|[wikipedia](https://en.wikipedia.org/wiki/Valgrind)|todo|
[Norm](#Norm)|[github](https://github.com/42School/norminette)|todo|

## Prompt
> [!NOTE]
> The readline() function can cause memory leaks. We don’t have to fix them
 - handling prompt
 - handling history

## Lexer
> [!NOTE]
> We have to handle '$' with environment variables and '?'
>
> We don't have to handle unclosed quotes or special characters which are not required by the subject such as '\\' or ';'
- text spliting
- tokens creation
- token assignment

## Parser
- linked list creation
- linked list reading method

## Interpreter
- main execution from linked list (ast in recursive descent)

## Builtins
- echo with option -n
- cd with only a relative or absolute path
- pwd with no options
- export with no options
- unset with no options
- env with no options or arguments
- exit with no options

## Signals
- ctrl-c
	- in interactive, displays a new prompt on a new line
- ctrl-d
	- in interactive, exits the shell
- ctrl-\
	- in interactive, does nothing

## Leaks
- valgrind

## Norm
- 42 norminette
