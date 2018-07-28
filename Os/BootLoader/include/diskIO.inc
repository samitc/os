%IFNDEF _DISK_IO_INC
%DEFINE _DISK_IO_INC
readFloppy:;es the segment bx the adress al number of sector to read cl sector number
        read_sectors:
                MOV AH,0x02
                INT 0x13
        JC read_sectors
ret

resetFloppy:;floppy number in dl
        reset_floppy:
                MOV AH,0
                INT 0x13
        JC reset_floppy
ret
%ENDIF