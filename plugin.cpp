http://www.bogotobogo.com/cplusplus/libraries.php
=================================================

How plugin are different than dynamic lib

In dynamic lib we ship lib along application

Plug-ins enable customizing the functionality of an application.
For example, plug-ins are commonly used in web browsers to play video, scan for viruses,
and display new file types. Well-known plug-ins examples include Adobe Flash Player, 
QuickTime, and Microsoft Silverlight.

Dynamic libraries are usually linked against an application and then distributed with
that application so that the OS can load the library when the application is launched. 
However, it is also possible for an application to load a dynamic library on demand 
without the application having been compiled and linked against that library.

This can be used to create plugin interface, when the application can load additional 
code at run time that extends the basic capabilities of the program.

