Quick Script snippets to achieve a manual function quickly using bash shell scripts.
------------------------------------------------------------------------------------

###Replace all tabs by white spaces in all files with given extension in the folder and subfolders
```bash
find . -type f -name "*\.[ch]" -exec sed -i.orig 's/\t/    /g' {} +
```

###Rename all files in folders with a different naming convention
```bash
rename 's/<prev_name>/<new_name>/' *.[ch]
```
or
```
find . -name '<pattern>' -exec bash -c 'mv $0 ${0/<pattern>/<new pattern>}' {} \;
```

find substitutes `{}` with the found things. `\;` causes the exec to be invoked per file, whereas using `+` would 
pass everything at once

### Auto rename all file names containing 'foo' with 'bar'

```bash
for i in ./*foo*;do mv -- "$i" "${i//foo/bar}";done
```

### Remove first N characters from each line of file NAME

```bash
sed -i 's/\(.\{N\}\)//' NAME
```

### Auto Replace String with substitution string inside all files

```bash
sed -i -e 's/<STRING_1>/<STRING_REPLACEMENT>/' * (Filter)
```

### Untar to a different directory

```bash
tar xvf <filename.tgz> -C <path to extract to>
```

### Remove all files of certain type `*.foo` from the directory subtree

__Variant 1__: User confirmation needed

```bash
find . -type f -name "*.foo" -exec rm -i {} \;
```

__Variant 2__: No confirmation

```bash
find . -type f -name "*.foo" -exec rm -f {} \;
``` 

### Set date and time from terminal
```bash
sudo date _MMDDhhmmYYYY.ss_
```

### Change terminal prompt (for example when in a virtual-env)

Set `$PS1` variable to what you want.

example:

````bash
PS1="(sandbox)$PS1"
````

### Turn off all monitors for sleep mode:

```
xset -display :0.0 dpms force off
```

Pressing `enter` turns them back on.

For a single monitor, this will also do:

```
sudo vbetool dpms off

sudo vbetool dpms on
```

To allow returning to normal state on pressing enter:

```
sudo sh -c 'vbetool dpms off; read ans; vbetool dpms on'
```

## GDB

### Separate debug symbols and binary

[Stackoverflow](http://stackoverflow.com/questions/866721/how-to-generate-gcc-debug-symbol-outside-the-build-target)

```
Compile with debug information:

gcc -g -o main main.c
Separate the debug information:

objcopy --only-keep-debug main main.debug
or

cp main main.debug
strip --only-keep-debug main.debug
Strip debug information from origin file:

objcopy --strip-debug main
or

strip --strip-debug --strip-unneeded main
debug by debuglink mode:

objcopy --add-gnu-debuglink main.debug main
gdb main
You can also use exec file and symbol file separatly:

gdb -s main.debug -e main
```

## Code diff 

### Remove all comments from a C/C++ code so that we can do a diff on actual meat and not on fluff
```
gcc -fpreprocessed -dD -E test.c
```

For a full folder, use it with find
```
find . -name "*.c" -exec bash -c 'gcc -fpreprocessed -dD -E $0 > $0.new' {} \;
find . -name "*.new" -exec bash -c 'mv $0 ${0/%.new/}' {} \;
```

## Valgrind

### Using a suppression file

```
valgrind --leak-check=full --show-reachable=yes --error-limit=no --max-stackframe=8388608 --gen-suppresions=all --log-file=6wad.log.supp --suppressions=/usr/lib/valgrind/6wad.supp /usr/bin/metacli/6wad/6wad
```

```
valgrind --leak-check=full --show-reachable=yes --error-limit=no --max-stackframe=8388608 --gen-suppressions=all --log-file=nbase-stub.log.supp --suppressions=/usr/lib/valgrind/nbase-stub.supp $NBASE_STUB_DIR/$NBASE_STUB_BIN > $NBASE_STUB_RUN_DIR/"$NBASE_STUB_BIN.log" 2>&1 &
```
