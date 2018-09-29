%IFNDEF _DISK_IO_INC
%DEFINE _DISK_IO_INC
temp db 0
count db 0
readFloppy:;es the segment bx the adress al number of sector to read cx head:sector number(10 bits for head and 6 for sector) dh head dl drive. return: ah return code, al total read sectors.
        MOV [temp],AL
        MOV byte [count],3
        JMP read_sectors
        check_count:
            test byte [count],0xFF
            JZ end_read
            DEC byte [count]
            MOV AL,temp
        read_sectors:
            MOV AH,0x02
            INT 0x13
        JC check_count
        end_read:
ret

resetFloppy:;floppy number in dl
        PUSH AX
        reset_floppy:
                MOV AH,0
                INT 0x13
        JC reset_floppy
        POP AX
ret
%ENDIF
