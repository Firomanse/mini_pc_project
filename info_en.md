### Mini_PC_project

###### \[[[info_ru.md|ru]] | en\]
This is mini-project, which I created to emulate computer, that should use a small number of commands.

#### For build a project you can:
1. write `./build.sh`, and run program by `./mini_pc_project` command
2. copy this files to your IDE and build them
3. wait for updates...

#### Additional information

##### all CPU commands
```
opcode          instruction      size     ops
0000 - halt     `halt`           (4 bit)  r
0001 - poweroff `poweroff`       (4 bit)  r
0010 - not      `not`            (4 bit)  r-d
0011 - swap?    `?`              (?)      ?
0100 - ?        `?`              (?)      ?
0101 - ?        `?`              (?)      ?
0110 - set      `set <8bit cmd>` (12 bit) r-ow
0111 - write    `write <addr>`   (12 bit) r-w
1000 - and      `and <addr>`     (12 bit) r-d
1001 - or       `or <addr>`      (12 bit) r-d
1010 - add      `add <addr>`     (12 bit) r-d
1011 - sub      `sub <addr>`     (12 bit) r-d
1100 - jump     `jump <addr>`    (12 bit) r-c
1101 - jz       `jz <addr>`      (12 bit) r-d-c
1110 - get      `get <addr>`     (12 bit) r-w
1111 - read     `read <addr>`    (12 bit) r

r - read
d - work with data
w - (inside) write
ow - outside write
c - work with clock
```
##### List of input arguments
-h --help     help information
-s --start    start mini_pc
-l --log      start with command log
-d --debug    start with memory dumps
-a --assembly start miasm
