Quick Script snippets to achieve a manual function quickly using bash shell scripts.
------------------------------------------------------------------------------------

** Auto rename all file names containing 'foo' with 'bar' **

```bash
for i in ./*foo*;do mv -- "$i" "${i//foo/bar}";done
```

** Remove first N characters from each line of file NAME **

```bash
sed -i 's/\(.\{N\}\)//' NAME
```

** Auto Replace String with substitution string inside all files **

```bash
sed -i -e 's/<STRING_1>/<STRING_REPLACEMENT>/' * (Filter)
```

** Untar to a different directory **

```bash
tar xvf <filename.tgz> -C <path to extract to>
```