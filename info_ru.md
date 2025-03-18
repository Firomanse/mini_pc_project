### Mini_PC_project

###### \[ru | [[info_en.md|en]]\]
Это мини-проект, в котором я хочу сэмулировать компьютер, использующий минимально-рабочее количество команд.

#### Для сборки проекта, можно:
1. написать `./build.sh`, а затем запустить командой `./mini_pc_project`
2. скинуть все файлы в свою IDE и собрать программу через неё
3. дождаться обновлений...

#### Дополнительные сведения.

##### Список команд процессора
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
##### Список принимаемых аргументов
-h --help     информация с помощью
-s --start    запуск mini_pc
-l --log      запуск с выводом команд
-d --debug    запуск с выводом дампов памяти
-a --assembly запуск miasm
