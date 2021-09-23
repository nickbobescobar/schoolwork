# Nicolas Escobar
# CAAM 519, Homework 1
# Part 3

# Functions to find largest and smallest files in home dir
alias homeBiggest='ls -s ~ | sort -nr | head -n'
alias homeSmallest='ls -s ~ | sort -n | head -n'
# Demo: biggest and smallest 3 files
homeBiggest 3
homeSmallest 3

# Get IPv6 address
ifconfig | grep inet6 | awk '{print $2}' | grep -v ^[:]

# List all users
cat /etc/passwd | cut -d ":" -f 1

# File permissions
ls -la ~
# That second column refers to the number of links pointing to that particular file.
cat > poetry.txt
Roses are red,
Violets are blue. 
Flag is win,
Baba is you!
# You need to Ctrl+C here
chmod a=rw-
chmod 666 poetry.txt

