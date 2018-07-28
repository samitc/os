%IFNDEF _GDT_INC_
%DEFINE _GDT_INC_
; This is the beginning of the GDT. Because of this, its offset is 0.
 
; null descriptor
gdt_start: 
	dd 0 				; null descriptor--just fill 8 bytes with zero
	dd 0 
 
; Notice that each descriptor is exactally 8 bytes in size. THIS IS IMPORTANT.
; Because of this, the code descriptor has offset 0x8.
 
; code descriptor:			; code descriptor. Right after null descriptor
	dw 0FFFFh 			; limit low
	dw 0 				; base low
	db 0 				; base middle
	db 10011010b 			; access
	db 11001111b 			; granularity
	db 0 				; base high
 
; Because each descriptor is 8 bytes in size, the Data descritpor is at offset 0x10 from
; the beginning of the GDT, or 16 (decimal) bytes from start.
 
; data descriptor:			; data descriptor
	dw 0FFFFh 			; limit low (Same as code)
	dw 0 				; base low
	db 0 				; base middle
	db 10010010b 			; access
	db 11001111b 			; granularity
	db 0				; base high
gdt_end:
	dw gdt_end - gdt_start - 1 	; limit (Size of GDT)
	dd gdt_start 			; base of GDT

loadGdt:
	cli
	lgdt [gdt_end]
	sti
ret


;    Bits 56-63: Bits 24-32 of the base address
;    Bit 55: Granularity
;        0: None
;        1: Limit gets multiplied by 4K
;    Bit 54: Segment type
;        0: 16 bit
;        1: 32 bit
;    Bit 53: Reserved-Should be zero
;    Bits 52: Reserved for OS use
;    Bits 48-51: Bits 16-19 of the segment limit
;    Bit 47 Segment is in memory (Used with Virtual Memory)
;    Bits 45-46: Descriptor Privilege Level
;        0: (Ring 0) Highest
;        3: (Ring 3) Lowest
;    Bit 44: Descriptor Bit
;        0: System Descriptor
;        1: Code or Data Descriptor
;    Bits 41-43: Descriptor Type
;        Bit 43: Executable segment
;            0: Data Segment
;            1: Code Segment
;        Bit 42: Expansion direction (Data segments), conforming (Code Segments)
;        Bit 41: Readable and Writable
;            0: Read only (Data Segments); Execute only (Code Segments)
;            1: Read and write (Data Segments); Read and Execute (Code Segments)
;   Bit 40: Access bit (Used with Virtual Memory)
;   Bits 16-39: Bits 0-23 of the Base Address
;   Bits 0-15: Bits 0-15 of the Segment Limit
%ENDIF