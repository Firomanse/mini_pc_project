# Mini PC Project \[[ru](README.ru.md) | en\]

This is a mini-project that emulates a fully software-based computer with a small instruction set.

## Build & Run

You can build and run the project in several ways:

- **Command line:** run `./build.sh`, then start the program with `./mini_pc_project`
- **IDE:** copy these files to your IDE and build them there
- Other build methods may be added later


## Additional Information
### Command-Line Arguments

|      Argument      |           Description            |
|--------------------|----------------------------------|
| `-h`, `--help`     | Show help information            |
| `-s`, `--start`    | Start the mini-PC emulator       |
| `-l`, `--log`      | Log all executed commands        |
| `-d`, `--debug`    | Dump memory state to output      |
| `-a`, `--assembly` | Start the mini-assembler (miasm) |

### CPU Instruction Set

| Opcode |    Instruction    |  Size  |  Ops  |
|--------|-------------------|--------|-------|
| `0000` | `halt`            | 4-bit  | r     |
| `0001` | `poweroff`        | 4-bit  | r     |
| `0010` | `not`             | 4-bit  | r-d   |
| `0011` | `swap?`           | ?      | ?     |
| `0100` | `?`               | ?      | ?     |
| `0101` | `?`               | ?      | ?     |
| `0110` | `set <8-bit cmd>` | 12-bit | r-ow  |
| `0111` | `write <addr>`    | 12-bit | r-w   |
| `1000` | `and <addr>`      | 12-bit | r-d   |
| `1001` | `or <addr>`       | 12-bit | r-d   |
| `1010` | `add <addr>`      | 12-bit | r-d   |
| `1011` | `sub <addr>`      | 12-bit | r-d   |
| `1100` | `jump <addr>`     | 12-bit | r-c   |
| `1101` | `jz <addr>`       | 12-bit | r-d-c |
| `1110` | `get <addr>`      | 12-bit | r-w   |
| `1111` | `read <addr>`     | 12-bit | r     |

**Legend:**
- `r` - read operation
- `d` - data operation
- `w` - write operation
- `ow` - external write operation
- `c` - program-flow (clock) operation
