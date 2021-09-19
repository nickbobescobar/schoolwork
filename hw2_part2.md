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

# Q2: Hard versus Symbolic Links

A hard link refers to the physical address of the file on the hard disk and will continue to work even if the file is moved in the directory system. Running <i>ls -i</i> will return the <i>inode</i> of each file, which is the direct reference to an address on the hard disk. For example, the current inodes for my <i>hw1_materials</i> folder:

    ompl@ompl-VirtualBox:~/Documents/hw_part1/hw1_materials$
    >>> ls -i| cat
    301355 add.c
    271622 add_translated.c
    289096 book.txt
    289441 err
    301350 grades.txt
    301344 numbers
    301360 part1.txt
    301358 part2.txt
    288134 phone_list
    303122 q5
    289436 us-states-new.csv


A symbolic link references the location of the file through the directory system. If a file is moved in the directory system, then the symbolic link will break. This is how file locations are typically referred to, e.g.

    /Documents/myFolder/myFile.txt

# Q3: Assignment versus Export

A normal assignment (a=5) will initialize the variable locally, i.e. only in the context of this shell. Exporting the assignment (export a=5) will define the variable globally and make it accessible from other shells.