.section .init9
main:
	mov.b #2, &50   /* initialisation de la diode */
	mov   #2, r15   /* valeur initiale de la valeur de la diode */
	mov   #0, r14   /*init r14 à 0*/
	mov   #20000, r13

loop:
	mov.b r15, &49  /* transferer r15 vers la diode */
	xor #2, r15     /* que fait cette ligne? */
        mov #0, r14
	jmp sleep

sleep:
	inc r14
	cmp r14, r13
        jne sleep
	jmp loop
