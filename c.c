struct _IO_FILE {
    int _flags;		/* High-order word is _IO_MAGIC; rest is flags. */
  #define _IO_file_flags _flags
  
    /* The following pointers correspond to the C++ streambuf protocol. */
    /* Note:  Tk uses the _IO_read_ptr and _IO_read_end fields directly. */
    char* _IO_read_ptr;	/* Current read pointer */
    char* _IO_read_end;	/* End of get area. */
    char* _IO_read_base;	/* Start of putback+get area. */
    // 0x20
    char* _IO_write_base;	/* Start of put area. */
    char* _IO_write_ptr;	/* Current put pointer. */
    char* _IO_write_end;	/* End of put area. */
    //0x38
    char* _IO_buf_base;	/* Start of reserve area. */
    char* _IO_buf_end;	/* End of reserve area. */
    /* The following fields are used to support backing up and undo. */
    char *_IO_save_base; /* Pointer to start of non-current get area. */
    char *_IO_backup_base;  /* Pointer to first valid character of backup area */
    char *_IO_save_end; /* Pointer to end of non-current get area. */
  
    struct _IO_marker *_markers;
  
    struct _IO_FILE *_chain;
  
    int _fileno;
  #if 0
    int _blksize;
  #else
    int _flags2;
  #endif
    _IO_off_t _old_offset; /* This used to be _offset but it's too small.  */
  
  #define __HAVE_COLUMN /* temporary */
    /* 1+column number of pbase(); 0 is unknown. */
    unsigned short _cur_column;
    signed char _vtable_offset;
    char _shortbuf[1];
  
    /*  char* _save_gptr;  char* _save_egptr; */
    //0x88
  
    _IO_lock_t *_lock;
    //0x90
  #ifdef _IO_USE_OLD_IO_FILE
  };
  
  struct _IO_FILE_complete
  {
    struct _IO_FILE _file;
  #endif
  #if defined _G_IO_IO_FILE_VERSION && _G_IO_IO_FILE_VERSION == 0x20001
    _IO_off64_t _offset;
  # if defined _LIBC || defined _GLIBCPP_USE_WCHAR_T
    /* Wide character stream stuff.  */
    struct _IO_codecvt *_codecvt;
    struct _IO_wide_data *_wide_data;
    struct _IO_FILE *_freeres_list;
    void *_freeres_buf;
  # else
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
  # endif
    size_t __pad5;
    //0xc0
    int _mode;
    //0xc4
    //0x14 len
    //vtable
    /* Make sure we don't get into trouble again.  */
    char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
  #endif
  };