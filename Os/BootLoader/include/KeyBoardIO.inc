%IFNDEF _KEY_BOARD_INC_
%DEFINE _KEY_BOARD_INC_
keyBoard_status_write:;need to define as inline
OUT 0x64,AL
ret
keyBoard_status_read:;need to define as inline
IN AL,0x64
ret
keyBoard_buffer_read:;need to define as inline
IN AL,0x60
RET
keyBoard_buffer_write:;need to define as inline
OUT 0x60,AL
RET
check_read_ready:;only set the flag register
	CAll keyBoard_status_read
	TEST AL,1
ret
wait_read_ready:
        CALL check_read_ready
        JZ wait_read_ready
ret
wait_read_ready_timeout:
	CALL check_read_ready
	JZ wait_read_finish
	LOOP wait_read_ready_timeout
	wait_read_finish:
ret
check_write_ready:
	CALL keyBoard_status_read
	TEST AL,2
ret
wait_write_ready:
        CALL check_write_ready
        JNZ wait_write_ready
ret
wait_write_ready_timeout:
        CALL check_write_ready
        JZ wait_write_finish
        LOOP wait_write_ready_timeout
        wait_write_finish:
ret
%ENDIF
