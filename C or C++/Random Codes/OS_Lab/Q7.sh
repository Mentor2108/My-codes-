# "find" finds all the "c" files in the current folder.
# Then parallel command runs all those files and gcc compiles all those files and gives them names
# "executable1" "executable2" etc...

find -name "*.c" |parallel gcc {} -o executable{#};

#Then this next command finds all those files made and executes them one by one

find -name "executable*" -exec ./{} \;

