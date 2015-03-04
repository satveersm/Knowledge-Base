http://www.drdobbs.com/security/anatomy-of-a-stack-smashing-attack-and-h/240001832

At termination of the subroutine, when the program retrieves the return address, 
that address has changed. Under normal circumstances, the program flow jumps to 
an unpredictable address. Chances are very good that the jump leads into a segment
outside the program's own memory. The system detects a segmentation violation and 
kills the process with signal number 11 (SIGSEGV). The program crashes and leaves 
a core file.

So far, so good. But what happens if the target of the changed return address is not 
outside the program's own memory? In this case, the jump might succeed and execution 
will go on. If there is valid machine code, it will be executed. If not, the processor
will create an illegal instruction exception.


Footprint of a Stack Overflow Attack

Attackers change the return address via a buffer overflow — not to an unpredictable location, 
but to a specific address. In other words: They can control where the jump goes.
A classic attack includes a so-called "payload" (also called a "cuckoo's egg") in the 
overflowing data, which consists of three parts:

An NOP sled
A shell code
A new return address
