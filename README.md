![Banner](assets/banner.png)

# Working tree
|Theme|Ressource|State|
|--|--|--|
[Prompt](#Prompt)|[readline](https://man7.org/linux/man-pages/man3/readline.3.html)|todo|
[Lexer](#Lexer)|[wikipedia](https://en.wikipedia.org/wiki/Lexical_analysis)|todo|
[Ast](#Ast)|[wikipedia](https://en.wikipedia.org/wiki/Abstract_syntax_tree)|todo|
[Path](#Path)|[wikipedia](https://en.wikipedia.org/wiki/Path_(computing))|todo|
[Signals](#Signals)|[wikipedia](https://en.wikipedia.org/wiki/Bash_(Unix_shell))|todo|
[Builtins](#Builtins)|[manual](https://www.man7.org/linux/man-pages/)|todo|
[Leaks](#Leaks)|[wikipedia](https://en.wikipedia.org/wiki/Valgrind)|todo|
[Norm](#Norm)|[github](https://github.com/42School/norminette)|todo|

## Prompt
> [!NOTE]
> The readline() function can cause memory leaks. We don’t have to fix them
 - handling prompt
 - handling history

## Lexer
> [!NOTE]
> We have to handle '$'VAR and '$'?
- tokens creation
- text spliting
- token assignment

## Ast
- linked list creation
- linked list reading method

## Path
- using path variable 
- using relative path
- using absolute path

## Signals
- ctrl-c
	- in interactive, displays a new prompt on a new line
- ctrl-d
	- in interactive, exits the shell
- ctrl-\
	- in interactive, does nothing

## Builtins
- echo with option -n
- cd with only a relative or absolute path
- pwd with no options
- export with no options
- unset with no options
- env with no options or arguments
- exit with no options

## Leaks
- valgrind

## Norm
- 42 norminette
