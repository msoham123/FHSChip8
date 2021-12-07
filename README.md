
# FHSChip8

An experimental CHIP-8 intepreter designed to serve as a learning experience for members of the Fremont High School Programming Club.

## Introduction

CHIP-8 is an interpreted programming language, developed by Joseph Weisbecker. It was initially used on the COSMAC VIP and Telmac 1800 8-bit microcomputers in the mid-1970s. CHIP-8 programs are run on a CHIP-8 virtual machine. It was made to allow video games to be more easily programmed for these computers

There are a number of classic video games ported to CHIP-8, such as Pong, Space Invaders, Tetris, and Pac-Man. There are also applications like a random maze generator and Conway's Game of Life.

## Contribute

For classes, use PascalCase. For variables and and methods, use CamelCase. Constants should be upper case. Create header files for any classes you create. 

Clone the project, checkout to a new branch, and submit a PR which will then be reviewed before being merged into master. A PR must address an issue. If there isn't one, create a new issue and mention it in your PR.

## Usage

1). Install Visual Studio 2019 on your machine. Proceed with the standard installation.
2). Clone this repo.
3). Install SDL 2 from [here](https://www.libsdl.org/download-2.0.php). Make sure you install the *Visual C++ 32/64-bit* edition. Extract the download and move it to ```C:\SDL\SDL2```. 
4). Open the actual ```FHSChip8Graphics.vcxproj``` file. In the repo the file is located in, the path to this file is ```FHSChip8/src/FHSChip8Graphics.vcxproj```. This file should open a workspace in Visual Studio 2019.
5). Verify that SDL2 is linked to the project locally. Right click on FHSChip8Graphics in the file menu in Visual Studio 2019 and click Properties. 

![image](https://user-images.githubusercontent.com/51520568/145117971-3f6570c3-9089-4c6e-bc26-86d062b156a7.png)

Ensure that the following settings look accurate to your own configuration.

![image](https://user-images.githubusercontent.com/51520568/145116409-8d645ceb-7201-44a1-b8b2-61ae0f6bd2e4.png)
![image](https://user-images.githubusercontent.com/51520568/145116508-f943bcc1-77d3-46dd-9cd0-b8412d689401.png)
![image](https://user-images.githubusercontent.com/51520568/145116545-f5d6d462-096c-43d2-926f-ca198aca57d9.png)
![image](https://user-images.githubusercontent.com/51520568/145116584-381023c1-982e-4693-8fff-3c9f6063133d.png)

6). You should be able to click on Run (the green arrow) and run this project on your machine! Make sure type is set to x64.

![image](https://user-images.githubusercontent.com/51520568/145118321-2dfb51fa-cb31-4139-83bf-b053fdda8124.png)
![image](https://user-images.githubusercontent.com/51520568/145118245-ad4cea5c-73c6-4cdb-a148-67e5d90beaaa.png)

## Credits

This is purely intended as a learning experience, so we are using a lot of external resources:

- [Guide to Making a CHIP-8 Emulator](https://tobiasvl.github.io/blog/write-a-chip-8-emulator/#fetchdecodeexecute-loop)
- [How to write an emulator (CHIP-8 interpreter)](https://multigesture.net/articles/how-to-write-an-emulator-chip-8-interpreter/)
- [Wikipedia](https://en.wikipedia.org/wiki/CHIP-8#Virtual_machine_description)

Additional useful resources:

- [Bitwise Operations](https://en.wikipedia.org/wiki/Bitwise_operation)
- [Opcode](https://en.wikipedia.org/wiki/Opcode)

