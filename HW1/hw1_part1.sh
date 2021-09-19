# Nicolas Escobar
# CAAM 519, Homework 1
# Part 1

# Make directory in whatever folder this script is run in and cd into it
mkdir ./hw_part1
cd ./hw_part1

# Download and unpack archive
wget https://msarrafj.github.io/CAAM519-FA21/Homeworks/HW1/hw1_materials.tar.gz
tar -xf hw1_materials.tar.gz
cd ./hw1_materials

# Default sort numbers into phone list
sort numbers > phone_list

# Translate {} and [] to ()
# Use backslashes for [ and ] to mean the literal characters
sed 's/\[/(/g' add.c | sed 's/{/(/g' | sed 's/\]/)/g' | sed 's/}/)/g' > add_translated.c
# I tried: 
    # sed 's/\[/(/g'; 's/{/(/g'; 's/\]/)/g'; 's/}/)/g'; add.c > add_translated.c
# but it never terminated and I had to kill the process. Not sure why.

# Make book.txt
cat part1.txt part2.txt > book.txt
# What does it mean to sort book.txt by its second column? There's only one column.
# The command below has the same output as default sort.
sort -k 2 book.txt > book_sorted.txt

# input.old to INPUT.new
# Gonna put these in a separate folder just for organization
mkdir ./q5
touch q5/input{1..50}.old
# Rename to each file to new style
for input in q5/*.old;
    do mv $input $( echo $input | sed 's/input/INPUT/g' | sed 's/old/new/g' );
done

# us-states.csv
# head has 3 rows to account for header row and then first 2 data rows
head -n 3 us-states.csv && tail -n 2 us-states.csv
wc -l us-states.csv
grep -n Texas us-states.csv
awk -F "," '{print $1,$3,$2,$4,$5}' us-states.csv > us-states-new.csv