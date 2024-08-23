org 0x7C00
bits 16

; Bootloader which actually boots xd

; A silly feature
db 'This is a silly little text, also i wanted to say that i love cats :3'

times 510-($-$$) db 0
dw 0x55AA
