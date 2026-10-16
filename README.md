# FT_Printf

*This project was created as part of the 42 curriculum by spaccaud.*

## Description  
In this project, I recoded the standard `printf` function. It was a great challenge to discover and learn how to use variadic functions in C. This function will be very useful for my upcoming projects at 42.

I have implemented theses function :
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

## Instructions  
To compile the library, you can use the provided `Makefile` with the following rules:

### make  
Compiles the C files into object files using the flags `-Wall -Wextra -Werror -g`, and then creates the library file (`libftprintf.a`).

### clean  
Removes all generated object files.

### fclean  
Removes the compiled library file along with all object files.

### re  
Cleans the entire project and recompiles it from scratch (runs `fclean` followed by `make`).

## Resources   
I used the `man` pages for technical information regarding `printf`. I also used the original `printf` function to compare its outputs and behavior against my own implementation.

### AI Use  
I did not use AI to write any of the code.
