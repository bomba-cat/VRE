org 0x7C00
bits 16

; Bootloader which actually boots xd

times 510-($-$$) db 0
dw 0x55AA
