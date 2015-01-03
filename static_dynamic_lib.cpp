http://www.bogotobogo.com/cplusplus/images/libraries/static_vs_dynamic_2.png

There are two types of libraries we can make. The decision on which one we take can
have a significant impact on our clients' applications, such as executable size, load time, etc.

A static library contains object code linked with an end-user application, and then becomes part 
of that executable. A static library is sometimes called an archive since it is just a package 
of compiled object files. These libraries are in directories such as /lib, /usr/lib or /usr/local/lib.

After resolving the various function references from the main program to the modules in the static 
library, a linker extracts copies of the required object modules from the library and copies these 
into the resulting executable file. When linking is done during the creation of an executable, it is
known as static linking or early binding. In this case, the linking is usually done by a linker, but 
may also be done by the compiler. A static library, also known as an archive, is intended to be 
statically linked. Originally, only static libraries existed. Static linking must be performed
when any modules are recompiled.

Facts abt static lib
1.)
A static library is only needed to link an application. It is not needed to run that application because 
the library code is already embedded inside the application. So, our clients can distribute their 
applications without any additional run-time dependencies.
2)
If our clients want to link our library into multiple executables, each one will embed a copy of our code. 
If our library is 100MB in size, and our client wishes to link this into three separate programs, then we 
could be adding up to 300MB to the total size of their product. Notice that only the object files in the
static library that are actually used are copied to the application. Thus, in reality, the total size of 
each application could be less than this worst case.
3)
But if our clients want to be able to hot patch their application, in other words, they want to update 
the version of our library used by their application, they must replace the entire executable to achieve
this. If this is done as an internet-based update, the end user may have to download a much larger 
update and hence wait longer for the update to complete.



Dynamic Lib

In other words, dynamic libraries are files linked against at compile time to resolve undefined 
references and then distributed with the end-user application so that the application can load the 
library code at run time. Usually, this requires use of a dynamic linker on the end user's machine 
to determine and load all dynamic library dependencies at run time, perform the necessary symbol 
relocations, and then pass control to the application.

Dynamic libraries may also be more efficient in terms of memory.
Most modern OS will attempt to only load the dynamic library code into memory once, and share 
it across all applications that depend upon it. This may also lead to better cache utilization. 
By comparison, every application that is linked against a static library will load duplicate 
copies of the library code into memory.

If our clients want to hot patch their application with a new (backward compatible) version of our
shared library, they can simply drop in the replacement library file and all of their applications 
will use this new library without having to recompile or relink.



