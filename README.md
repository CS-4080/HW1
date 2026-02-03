# HW1
Hasti Abbasi Kenarsari<br>
Professor Rick Ramirez<br>
CS 4080.03<br>
2 February 2026<br>

### Ch1
1. There are at least six domain-specific languages used in the little system I cobbled together to write and publish this book. What are they?
    - Markdown, Jinja2, Makefile, SASS, CSS, and HTML.
2. Get a “Hello, world!” program written and running in Java. Set up whatever makefiles or IDE projects you need to get it working. If you have a debugger, get comfortable with it and step through your program as it runs.
    - [code for ch1 q2](https://github.com/CS-4080/HW1/blob/main/ch1_q2.java) 
3. Do the same thing for C. To get some practice with pointers, define a doubly linked list of heap-allocated strings. Write functions to insert, find, and delete items from it. Test them.
    - [code for ch1 q3](https://github.com/CS-4080/HW1/tree/main/ch1_q3)

### Ch2
1. Pick an open source implementation of a language you like. Download the source code and poke around in it. Try to find the code that implements the scanner and parser. Are they handwritten, or generated using tools like Lex and Yacc? (.l or .y file usually imply the latter.)
    - I analysed the source code for Lua. The scanner (llex.c) and the parser (lparser.c) are handwritten. There are no .l or .y grammar/lexer spec files.
2. Just-in-time compilation tends to be the fastest way to implement dynamically typed languages, but not all of them use it. What reasons are there to not JIT?
    - Not all dynamically typed languages utilize JIT because of the increased runtime and performance overhead. This is a result of compilation on the end user’s side. Additionally, JIT compilers are highly complex and require significant maintenance efforts. They also introduce security concerns, given that executing machine code at runtime can risk code injection attacks.
3. Most Lisp implementations that compile to C also contain an interpreter that lets them execute Lisp code on the fly as well. Why?
    - The interpreter is a critical part of the Lisp runtime environment. It provides the infrastructure for its dynamic features. It enables interactive development/debugging of Lisp code. It serves as a fallback option for running Lisp programs without a compiler. Additionally, it provides portability.
      
### Ch3
1. Write some sample Lox programs and run them (you can use the implementations of Lox in my [repository](https://github.com/munificent/craftinginterpreters)). Try to come up with edge case behavior I didn’t specify here. Does it do what you expect? Why or why not?
    - I wrote two sample Lox programs. The first one tests what happens when dividing by zero. I expected a runtime error that warned against dividing by 0. Instead, I got “inf” and “Infity” from printing the result of 1 / 0 and “-inf” and “-Infinity” (with clox and jlox respectively) from printing the result of -1 / 0. The second one tests what happens if I try adding two sets of operands. In the first set, both are strings and I get no error. In the second, one is a string and the other is a number. I expected to see the error “Operands must be two numbers or two strings” when using clox and jlox because that is what the presentation in class mentioned.
    - [code for ch3 q1](https://github.com/CS-4080/HW1/tree/main/ch3_q1)
2. The informal introduction leaves a lot unspecified. List several open questions you have about the language’s syntax and semantics. What do you think the answers should be?
    - What happens if a variable is declared but never initialized?
      - The variable should be initialized to nil  
    - What happens if I declare two functions with the same name?
      - I would expect to get an error. However, after testing it appears that the second declaration overrides the first one.
    - [code for ch3 q2](https://github.com/CS-4080/HW1/tree/main/ch3_q2)

3. Lox is a pretty tiny language. What features do you think it is missing that would make it annoying to use for real programs? (Aside from the standard library, of course.)
    - Lox lacks namespaces, data structures, static typing, and immutability support. All these factors make it difficult to use the language to do more than create small, relatively simple programs.



