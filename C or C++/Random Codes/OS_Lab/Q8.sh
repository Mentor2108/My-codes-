echo -n "Enter name of first file: "
read file1
echo -n "Enter name of second file: "
read file2
cmp -s $file1 $file2 && echo "Files are Identical" || echo "Files are NOT Identical"
