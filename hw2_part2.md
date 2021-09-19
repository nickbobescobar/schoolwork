Nicolas Escobar

CAAM 519, Homework 1

Part 2

# Q1: Explain Commands

    cat <file> | less
Read the contents of a file. Use <i>less</i> for added scrolling functionality.

    cat <file> 2>&1| less
Reads the contents of a file and appends the error message if <i>cat</i> throws an error.

    cat <file> > /dev/null
Reads the contents of a file into the void, basically discarding the output.

    cat <file> 1> out 2>err
Copies the contents of a file into another file called <i>out</i> and any error message thrown into a separate file called <i>err.</i> 

    cat <file> &> out
Copies the contents of a file and any error message thrown into another file called <i>out.</i>

    cat <file> > /dev/null &
Reads the contents of a file into the void, but do it in the background.

    cat <file> > /dev/null && echo "cleaning done!"
Reads the contents of a file into the void, then print "cleaning done!" to the terminal.
