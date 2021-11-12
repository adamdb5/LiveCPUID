global start      ; Define global entry point

extern asm_entry  ; Reference external asm_entry routine

section .text
start:            ; Entry point
  jmp asm_entry   ; Jump to asm_entry in main.c
  hlt             ; Halt the CPU