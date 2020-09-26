### Sept. 23rd 2020
Dabbled in using the `lcc` compiler to compile `ebm.c`. Wouldn't work, and only gave `invalid argument` as the reason. Been moving the file into the examples directory with the disto, and piggybacking off the make.bat to get things up and running. Seems like a couple of strange things are happening:
- Not sure if i'm able to return values from a function. Seems to be when I try and return 0 or 1 on an Int return type function it dies. When I remove it the make file works. fun.
- Strange issues with scope. Seems to be breaking when i reference global level structs from inside the function scope, but not arrays. None of this breaks on a standard C compiler.

I think next steps are going to be amassing documentation. This project is old and the help is probably limited, so it's probably worth padding out my understanding with what I can find rather than getting frustrated. Also, I need to get Make up and running on windows (just for fun).

Looks like I was wrong about the method thing.
Compiler seems to be a path issue, can use it when compiling directly from the distro.
 ``C:\Users\punchcafe\Downloads\gbdk-2.95-3-win32\gbdk> .\bin\lcc .\examples\gb\ebm.c -o ebm.gb``

 ### Sept. 26th 2020
 Skipped a day of logging yesterday, but tl;dr managed to get the methods working by moving the while loops into sepatate methods. began to get to grips with some printing to screen. I'm not sure how the hardware works but now that I know the functionality works, I'll need to make it work within an overall control loop instead of individual while loops for burning down the counter.

 Today I looked in the `drawing.h` file. Far less overwhelming than the `gb.h`. Managed to draw a simple line. I then looked into displaying sprites. While doing so I googled Vblank address is and stumbled across an awesome site. Seems to be a good community for the GBDK but also the assembly level stuff. I'm thinking making a game in assembly will be a funner more hands on to learning assembly than aimless coding in a z80 emulator. Websites are:
 - https://gbdev.gg8.se/wiki/articles/GBDK_Sprite_Tutorial
 - https://gbdev.gg8.se/wiki/articles/Main_Page
 - https://gbdev.gg8.se/wiki/articles/Video_Display
 It's super cool to see some of the level of granularity of the sprite methods. `UINT`s are handled in hex to specifically set bit flags for determining behaviour of sprites, and all sorts. It's really cool.