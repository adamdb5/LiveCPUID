global start

extern asm_entry ; Reference external asm_entry routine

; Bare minimum assembly
section .text
start:
  jmp asm_entry
  hlt