# Notes about the input redirection and output redirection.
```c
while (1) {
    /* take the input if the it has '>' operator then process the string and 
     * for that process close the stdin or stout based on type of redirection.
     * after all extract the file and accordingly close the appropriate file.
     */ then accordingly use the execl in that.
}
```

---

System call called pipe()

it creates an internal operating system queue like data structure. 

pipe() return an array of 2 file descriptor i.e 0th and 1st 

- Oth is used for the as an argument to read() to read from the queue/pipe 
- 1st is used as an argument to write() to write to the pipe/ queue 

---
pipe inside the shell
usage 
$ ls | grep

Obviously the shell has to run two programs at the time.
So it needs to do 2 forks and 2 execs

the two processes will run concurrently.

and then connect the stdout of first as stdin of second

caution:
ls | grep | head -> you cannot have the same pipe for this set of commands. you need to have the two seperate pipes for that.
