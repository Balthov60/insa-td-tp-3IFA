.section .init9
main:
	mov.b   #32, &26   /* initialisation de la diode */
	mov   #32, r15   /* valeur initiale de la valeur de la diode */
	mov   #0, r14   /*init r14 à 0*/
	clr  r13
        mov   #500, r12
        mov   #0, r11
	mov  #1, r10
	mov #0, r9
loop:
	mov.b r15, &25  /* transferer r15 vers la diode */
	xor #32, r15     /* que fait cette ligne? */
        mov #0, r14
        cmp r9, r10
	jne sleep_down
	jmp sleep_up

sleep_up:
	inc r14
	cmp r14, r13
        jne sleep_up
	inc r13
	cmp r13, r12
	jn check_clear
	jmp loop

check_clear:
	cmp r9, r10
	jne clear
        mov #500, r13
	jmp loop

clear:
	clr r13
	xor #1, r10
        jmp loop
	

sleep_down:
	inc r14
	cmp r14, r13
        jne sleep_down
	dec r13
	cmp r13, r11
	jne loop
	jmp check_clear
