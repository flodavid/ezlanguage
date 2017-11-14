Sources
=======

Folder that contains lex and bison files, with the main.cpp. `global.h` defines data structures and settings that may be shared between lex and bison.

Don't move these files, they are needed in the makefile !

Subfolders contains C++ files and classes.

+ [`modules`](modules) contains classes used to translate EZ instructions into C++*
+ [`declarations`](declarations) contains modules that may be stored into the hash table
+ [`hash_table`](hash_table) contains hash table related classes
+ [`addons`](addons) contains C++ files useful in several files

For more informations on each folder role, check `README.md` files into those folders.

-----

### Generic classes :
 + **Node** : Abstract class which represent a node of the tree
 + **TranslatedNode** : Abstract class which represent a node of the tree

### Implemented modules :
 + **ArrayAccess** : Array access operator `[..]`
 + **ConditionalExpression** : Expression of a condition (ex : (a or b) and (b and c) )
 + **For** : `for` loop
 + **If** : `if` instruction
 + **Operator** : All operators : `or, and, not, xor, ||, &&, ^, !, abs, -, +, /, *, mod, pow, <, >, ==, =, ++, --, ...`
 + **Program** : `program PROGRAM_NAME`. The root node of each program. All others nodes instances are successors (direct of indirect) of it.
 + **Repeat** : `repeat ... until` loop
 + **While** : `while` loop

### Implemented declarations :
 + **Class** : Class declaration
 + **Container** : Declaration of all container (vector, set, map, list and array)
 + **Function** : Function declaration
 + **MultipleVariable** : Multiple variables declarations
 + **Procedure** : Procedure declaration
 + **Variable** : Variable declaration