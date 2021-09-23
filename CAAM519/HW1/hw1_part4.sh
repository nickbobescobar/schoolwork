# Nicolas Escobar
# CAAM 519, Homework 1
# Part 4

# Print lines 3 and 4
awk '{print $3,$4}' grades.txt

# Print lines over 15 characters (all of them)
awk 'length>15' grades.txt

# Print lines with John
awk '$2 == "John"' grades.txt