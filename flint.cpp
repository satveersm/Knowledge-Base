A lint program typically scans software code to look for issues that a compiler
does not catch, a process called static code analysis. Linters can be handy for
enforcing organizational best practices in code development, or to look for code 
patterns that could cause security or performance issues.

Although there are a number of static analysis programs already available for C++,
Facebook found them mostly unsuitable for its own needs. Many were too slow or 
weren't updated to understand C++11, which Facebook is in the process of adopting.
Flint reviews code and flags any potential issues in Facebook's code review system

