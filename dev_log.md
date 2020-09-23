### Sept. 23rd 2020
Dabbled in using the `lcc` compiler to compile `ebm.c`. Wouldn't work, and only gave `invalid argument` as the reason. Been moving the file into the examples directory with the disto, and piggybacking off the make.bat to get things up and running. Seems like a couple of strange things are happening:
- Not sure if i'm able to return values from a function. Seems to be when I try and return 0 or 1 on an Int return type function it dies. When I remove it the make file works. fun.
- Strange issues with scope. Seems to be breaking when i reference global level structs from inside the function scope, but not arrays. None of this breaks on a standard C compiler.

I think next steps are going to be amassing documentation. This project is old and the help is probably limited, so it's probably worth padding out my understanding with what I can find rather than getting frustrated. Also, I need to get Make up and running on windows (just for fun).

Looks like I was wrong about the method thing.
Compiler seems to be a path issue, can use it when compiling directly from the distro.
 ``C:\Users\punchcafe\Downloads\gbdk-2.95-3-win32\gbdk> .\bin\lcc .\examples\gb\ebm.c -o ebm.gb``