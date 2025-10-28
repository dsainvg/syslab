#!/bin/sh

# 1. FOR loop: List file details and count lines for each text file
echo "=== FOR LOOP: Line counts of *.txt files ==="
for file in *.txt *.log; do
  if [ -f "$file" ]; then
    linecount=$(wc -l < "$file")
    echo "File: $file has $linecount lines"
  fi
done

# 2. WHILE loop: Read a file line by line, print lines with their number
echo "\n=== WHILE LOOP: Numbered lines in bc.man (first 5 lines) ==="
count=1
while IFS= read -r line && [ $count -le 5 ]; do
  echo "Line $count: $line"
  count=$((count + 1))
done < bc.man

# 3. UNTIL loop: Find a writable, non-empty log file
echo "\n=== UNTIL LOOP: First writable, non-empty *.log file ==="
set -- *.log
idx=1
until [ $idx -gt $# ]; do
  candidate=$(eval "echo \$$idx")
  if [ -w "$candidate" ] && [ -s "$candidate" ]; then
    echo "Writable & non-empty log file found: $candidate"
    break
  fi
  idx=$((idx + 1))
done
if [ $idx -gt $# ]; then
  echo "No writable, non-empty .log file found."
fi
