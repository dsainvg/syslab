#!/bin/bash

echo "Enter the filename to check:"
read FILENAME

if [ ! -e "$FILENAME" ]; then
    echo "$FILENAME does not exist."
    exit 1
fi

echo ""
echo "Choose an operation:"
echo "1) Check file type"
echo "2) Check file size"
echo "3) Check read permission"
echo "4) Check write permission"
echo "5) Check execute permission"
echo "6) Check all attributes"
read CHOICE

case $CHOICE in
    1)
        if [ -d "$FILENAME" ]; then
            echo "$FILENAME is a directory."
        elif [ -f "$FILENAME" ]; then
            echo "$FILENAME is a regular file."
        else
            echo "$FILENAME is a special file."
        fi
        ;;
    2)
        if [ -s "$FILENAME" ]; then
            echo "$FILENAME is non-empty."
        else
            echo "$FILENAME is empty."
        fi
        ;;
    3)
        if [ -r "$FILENAME" ]; then
            echo "You have read permission on $FILENAME."
        else
            echo "You do not have read permission on $FILENAME."
        fi
        ;;
    4)
        if [ -w "$FILENAME" ]; then
            echo "You have write permission on $FILENAME."
        else
            echo "You do not have write permission on $FILENAME."
        fi
        ;;
    5)
        if [ -x "$FILENAME" ]; then
            echo "You have execute permission on $FILENAME."
        else
            echo "You do not have execute permission on $FILENAME."
        fi
        ;;
    6)
        echo "Complete file analysis:"
        [ -d "$FILENAME" ] && echo "- Directory" || echo "- Regular file"
        [ -s "$FILENAME" ] && echo "- Non-empty" || echo "- Empty"
        [ -r "$FILENAME" ] && echo "- Readable" || echo "- Not readable"
        [ -w "$FILENAME" ] && echo "- Writable" || echo "- Not writable"
        [ -x "$FILENAME" ] && echo "- Executable" || echo "- Not executable"
        ;;
    *)
        echo "Invalid choice. Please select 1-6."
        exit 1
        ;;
esac
