strace is used to invoke an application, and reports every system call invoked
by the process and each signal received by the process until the process exits.
This information is displayed in real time on stderr.  Obviously, that means it 
seriously degrades performance, but in many cases, the issue you may be chasing 
is readily apparent using strace.  Have you ever launched a Linux process and 
have it just die without providing any error messages nor log output? I pull out
strace as the first order of business in these cases.  Many times, the file or 
condition that the failing application requires is readily apparent.  strace
has many options to control its behavior.  For example, if you suspect a failure 
due to a missing or nonexistent file, strace can be run to filter its output 
showing only open calls:

$ strace -e trace=open your-application

But strace can be used for much more.  The -c flag to strace is used to provide a 
summary report of each system call including the time, number of times called, and 
the number of errors recorded for each system call. 

Do you want to discover where the instruction pointer is at the time of the system call?

$ strace -i your-program

Or maybe you want to determine which system calls take the longest time:

$ strace -r your-program

Or maybe you want to learn how much time was spent in each system call:

$ strace -T your-program

