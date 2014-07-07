.global _start

_start:
    mov $2, %eax
    bx lr     ; /* Return from main */