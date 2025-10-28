#!/bin/bash

# --------------------------
# Indexed Array operations
# --------------------------

# Declare and initialize
fruits=("apple" "banana" "cherry" "dates")

echo "Indexed array contents: ${fruits[@]}"
echo "First element: ${fruits[0]}"
echo "All indices: ${!fruits[@]}"
echo "Array length: ${#fruits[@]}"

# Update an element
fruits[2]="grape"
echo "After update: ${fruits[@]}"

# Slice array (from index 1, length 2)
echo "Sliced array: ${fruits[@]:1:2}"

# Add new element
fruits+=("elderberry")
echo "After append: ${fruits[@]}"

# Loop using elements
for fruit in "${fruits[@]}"; do
  echo "Fruit: $fruit"
done

# Loop using indices
for i in "${!fruits[@]}"; do
  echo "Index $i: ${fruits[$i]}"
done

# Unset (delete) an element by index
unset fruits[1]
echo "After unsetting index 1: ${fruits[@]}"
echo "Array length after unset: ${#fruits[@]}"
echo "Indices after unset: ${!fruits[@]}"

# Unset (delete) entire array
unset fruits
echo "After unsetting entire array: ${fruits[@]}"

# --------------------------
# Associative Array operations
# --------------------------

# Declare (must use -A!)
declare -A colors

# Set values
colors["apple"]="red"
colors["banana"]="yellow"
colors["grape"]="purple"

echo "Associative array keys: ${!colors[@]}"
echo "Associative array values: ${colors[@]}"
echo "Color of apple: ${colors[apple]}"
echo "Associative array length: ${#colors[@]}"

# Update a value
colors["grape"]="green"
echo "After update: ${colors["grape"]}"

# Add a new key-value
colors["dates"]="brown"

# Loop over keys
for fruit in "${!colors[@]}"; do
  echo "$fruit is ${colors[$fruit]}"
done

# Unset a single key
unset colors["banana"]
echo "After unsetting 'banana': ${colors[@]}"

# Unset entire associative array
unset colors
echo "After unsetting all colors: ${colors[@]}"

# --------------------------
# Special referencing & symbols
# --------------------------

# Re-create an indexed array to show length & keys
myarr=("x" "y" "z")
echo "Length via #: ${#myarr[@]}"
echo "All elements via *: ${myarr[*]}"
echo "All elements via @: ${myarr[@]}"
echo "All indices via !: ${!myarr[@]}"
unset myarr[0]
echo "After unsetting index 0: ${myarr[@]}, indices: ${!myarr[@]}"

# Relative index access (Bash >=4.3)
sport=("football" "cricket" "hockey" "basketball")
echo "Normal access: ${sport[1]}"         # cricket
echo "Relative (from end) -3: ${sport[-3]}" # cricket

arr=(a b c d e f)
echo "${arr[@]:2}"     # Output: c d e f
echo "${arr[@]:1:3}"   # Output: b c d
echo "${arr[@]::2}"    # Output: a b
echo "${arr[@]: -2}"   # Output: e f
echo "${arr[@]: -4:2}" # Output: c d

# End of script
arr=(dog cat fish)
idx=1
ref='arr[${idx}]'
echo "${!ref}"         # Output: cat