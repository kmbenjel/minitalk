# minitalk — Bit-Level Unix Signal IPC Client & Server in C

<div align="center">

[![Language](https://img.shields.io/badge/Language-C%20(C99%20%2F%2042%20Norm)-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Curriculum](https://img.shields.io/badge/1337%20%2F%2042%20Network-Common%20Core-black?style=for-the-badge)](https://1337.ma)
[![IPC](https://img.shields.io/badge/UNIX%20IPC-sigaction(2)%20%7C%20SIGUSR1%20%2F%20SIGUSR2-f59e0b?style=for-the-badge)](#)

</div>

---

## 📌 Overview

**`minitalk`** is a Unix Inter-Process Communication (IPC) project from the **1337 / 42 Network** curriculum consisting of a `server` daemon and a `client` transmitter that exchange arbitrary UTF-8/ASCII strings across processes using **only Unix user signals (`SIGUSR1` and `SIGUSR2`)**.

---

## 🏗️ Bitwise Signal Protocol

```mermaid
sequenceDiagram
    autonumber
    participant C as 💻 Client Process (client)
    participant K as 🐧 Linux Kernel (kill / sigaction)
    participant S as 🖥️ Server Daemon (server)

    Note over S: Boots, prints PID, registers sigaction(SA_SIGINFO)
    C->>C: Decomposes each byte into 8 bits (MSB to LSB)
    loop For each bit in message (+ null terminator)
        alt Bit == 1
            C->>K: kill(server_pid, SIGUSR1)
        else Bit == 0
            C->>K: kill(server_pid, SIGUSR2)
        end
        K->>S: Delivers signal + siginfo_t (si_pid)
        S->>S: Shifts bit into 8-bit accumulator (c = (c << 1) | bit)
        S-->>C: Sends per-bit/message ACK signal (Bonus)
    end
    Note over S: Outputs reconstructed byte stream to stdout
```

### Key Technical Concepts
- **Bitwise Serialization**: Each character is decomposed via bit shifts (`(byte >> bit_idx) & 1`) and transmitted as 8 consecutive signals (`SIGUSR1` for `1`, `SIGUSR2` for `0`).
- **Async-Signal-Safe Handling (`sigaction`)**: Uses `struct sigaction` with `SA_SIGINFO` to inspect `info->si_pid`, identify the sending client, reset state cleanly if a client PID changes mid-transmission, and acknowledge receipt.
- **Unicode & Multi-Byte Support**: Because transmission operates transparently at the raw byte/bit level, multi-byte UTF-8 sequences (Arabic, emojis, symbols) reconstruct identically on the server.

---

## 🛠️ Build & Run

```bash
# Build mandatory & bonus client/server binaries
make
make bonus

# 1. Start the server in Terminal 1 (prints its PID)
./server
# -> Server PID: 42137

# 2. Send a message from Terminal 2 using the server's PID
./client 42137 "Hello from 1337 / 42 Network! 🚀 مرحبا"
```

---

## 🔗 Companion 1337 / 42 Network Projects

| Repository | Focus Area |
|---|---|
| [**`libft`**](https://github.com/kmbenjel/libft) | 43 standard C library functions + singly linked list API reimplemented from scratch |
| [**`ft_printf`**](https://github.com/kmbenjel/ft_printf) | Variadic `printf(3)` reimplementation using `<stdarg.h>` |
| [**`get_next_line`**](https://github.com/kmbenjel/get_next_line) | Stateful buffered line reader across arbitrary Unix file descriptors (`read(2)`) |
