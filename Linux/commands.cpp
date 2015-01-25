1)What command is used to count the total number of lines, words, and characters contained in a file?

wc  -c file_name print bytes in a file
wc  -m file_name char count in file
wc -l  file_name new line count in file
wc -L file_name longest line length
wc -w file_name word count

2)What TCP/IP protocol is used for remote terminal connection service?
telnet
3)What service is used to translate domain names to IP addresses?
dns
4)What command is used to sort the lines of data in a file in alphabetical order?
sort
5)What command is used with vi editor to search a pattern in the forward direction?
/
6)What command is used to save the standard output in a file, as well as display it on the terminal?
tee -a filename
7)What command is used to sort the lines of data in a file in reverse order?
sort -r
8)What command is used with vi editor to move forward to the end of a word?
e
9)What can he used to set up a firewall on a Linux system?
ipchains
iptables
10)Which of the following command lists the last 10 lines of a file?
tail n file_name
11)What command is used with vi editor to delete three words?
3 dw
12) how to delete a line
dd
13)What command is used to summarize the disk usage?
du
14)How to access Linux systems remotely from Windows machine? 
SSH Secure Shell Client or putty
15)Vi commands
create file  vi hello.txt
to start writing data press insert or i
to save  esc and wq!
to quit without saving q!
16) To display contents of file
cat filename
17) to copy contents of one file to other file
cp file1 file2
mkdir junk
cp file1 ./junk/file2.txt

18) to go one level up from current dir
cd ..
19) to remove a file
rm file1
20) to remove a dir
rm -r dirname
21) rename a file
mv file  newname
22) man command_name to get help abt any command
23)Use the diff command to see the differences in two files 
diff test.txt newtest3.txt
24)Previously executed commands in a shell can be 
viewed by using the history command
history
25)If the contents to display are more than one page, 
you could use the more/less command for paging 
through text a screenful at a time
more test.txt 
less test.txt
26) TAR(Tape archive or tapball)
Tar bundles files and subdir together and create an archive
tar -cvf tar_file_name.tar  * c mean creat a tar 
go to that dir and execute this

27) Extract using x flag
tar -xvf xyz.tar
28) Creating a compressed tar file
use z option along c
tar -cvzf my.tar.gz *
we can extract using smae command
tar -xvf my.tar.gz

Note: the c, v, and f flags mean create a new archive, be verbose 
so that the files being archived are listed, and write the archive to 
a file.

c- create a archive
v -be verbose so all files which archived are listed
f - write archive to a file

29)By default, the output is displayed on the screen 
“ > ” symbol can be used to redirect the output to a file or a 
utility (e.g., ls). Example: 
ls -ltr > myContent 
30)
• The “ | “ symbol is used to connect the output of one process 
to the input of another process 
 ls -l | wc -l 
wc counts the number of lines 
31)
“ < ” symbol is used for input redirection 
mail -s "SSC 222/292" rauta@tacc.utexas.edu < test.txt
32)
“ >> ” symbol is used for appending output to a file 
cat test3.txt >> test.txt 
33)
“ ; ” is used to execute multiple commands in one step
34)
You can add content to a file as follows 
cat > test.txt //add >
This is what I am entering from the console 
CTRL-D
cat test.txt //display
This is what I am entering from the console 
35)
• You can append content to a file as follows
cat >> test.txt 
Appending more lines 
CTRL-D 
cat test.txt
36)
To check the login name use the command whoami or echo 
$USER 
37)
To check the groups you are a member of use the command 
groups 
38)
To check your user id, or group id use the command id 
39)
Users typically perform the following operations on files: 
Read files (using more, cat, etc.) 
Write files (using >, vi, etc.)
Execute commands in a file (executables, etc.) 
Each file has three permissions – read, write and execute 
(rwx) 
 
• Person creating the file is the owner or user and can modify 
permissions as desired 
– Owner can modify permissions on files to grant or revoke 
access to other users 
To check the file permissions use the -l flag with the 
ls command 

login4$ ls -l 
total 24 
drwx------ 2 rauta G-25072 4096 Jan 17 14:07 junk 
drwx------ 2 rauta G-25072 4096 Jan 17 14:15 junk2 
-rw------- 1 rauta G-25072 65 Jan 17 13:59 test.txt 

40)
chmod command is used to change permissions on a file
To add specific permission use chmod + 
– To add write permission to all users use: 
 chmod a+w filename 
– To add read permission to only the users in your group use: 
 chmod g+r filename 
– To make a file executable and runnable by any user 
 chmod a+x myfile 
 
 To remove specific permission use chmod –
 Add and remove permissions can be combined in a single step 
– chmod u+x,g+r,o-rwx filename 

Instead of using alphabets u, g, o for user, group, and others we 
can use numbers to specify file permissions 
rwx = 111 = 7 
rw- = 110 = 6 
r-x = 101 = 5 
r-- = 100 = 4 
-wx = 011 = 3 
-w- = 010 = 2 
--x = 001 = 1 
--- = 000 = 0 

41) sed command
>cat file.txt
unix is great os. unix is opensource. unix is free os.
learn operating system.
unixlinux which one you choose.

SED COMMAND EXAMPLES
1)Replacing or substituting string
Sed command is mostly used to replace the text in a file. The below simple sed
command replaces the word "unix" with "linux" in the file.
>sed 's/unix/linux/' file.txt
linux is great os. unix is opensource. unix is free os.
learn operating system.
linuxlinux which one you choose.

Here the "s" specifies the substitution operation. The "/" are delimiters.
The "unix" is the search pattern and the "linux" is the replacement string.

By default, the sed command replaces the first occurrence of the pattern in
each line and it won't replace the second, third...occurrence in the line.

2)Replacing the nth occurrence of a pattern in a line.
Use the /1, /2 etc flags to replace the first, second occurrence of a pattern 
in a line. The below command replaces the second occurrence of the word 
"unix" with "linux" in a line.

>sed 's/unix/linux/2' file.txt
unix is great os. linux is opensource. unix is free os.
learn operating system.
unixlinux which one you choose.

3)Replacing all the occurrence of the pattern in a line.
The substitute flag /g (global replacement) specifies the sed command to replace
all the occurrences of the string in the line.

>sed 's/unix/linux/g' file.txt
linux is great os. linux is opensource. linux is free os.
learn operating system.
linuxlinux which one you choose.

Running multiple sed commands.
You can run multiple sed commands by piping the output of one sed command 
as input to another sed command.
>sed 's/unix/linux/' file.txt| sed 's/os/system/'
linux is great system. unix is opensource. unix is free os.
learn operating system.
linuxlinux which one you chosysteme.


Sed provides -e option to run multiple sed commands in a single sed command. 
The above output can be achieved in a single sed command as shown below.

>sed -e 's/unix/linux/' -e 's/os/system/' file.txt
linux is great system. unix is opensource. unix is free os.
learn operating system.
linuxlinux which one you chosysteme.




