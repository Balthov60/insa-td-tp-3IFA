.section .init9
main:
	mov   #0, &34
	mov.b #2, &50   /* initialisation de la diode */
	mov   #2, r15   /* valeur initiale de la valeur de la diode */
	mov   #0, r14   /*init r14 à 0*/
	mov   #2, r12

waitpressed:
	mov.b &32, r14
	cmp r14, r12
	jne waitpressed
	jmp waitreleased	

waitreleased: 
	mov.b &32, r14
	cmp r14, r12
	jeq waitreleased
	jmp toggle	

toggle: 
	mov.b r15, &49  /* transferer r15 vers la diode */
	xor #2, r15     /* que fait cette ligne? */
	jmp waitpressed
