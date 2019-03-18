.section .init9
main:
	mov   #0, &34
	mov.b #2, &50   /* initialisation de la diode */
	mov   #2, r15   /* valeur initiale de la valeur de la diode */
	mov.b   #1, &36   /* set interrupt edge to a high-to-low */
	mov.b   #1, &37   /* enable interrupt on P1 */ 
	mov   #0, r10   /* init sleep counter */
	mov   #40000, r11 /* sleep constant */
	eint            /* enable global interrupts */

loop:
	jmp loop

.global __isr_20
__isr_20:
	mov.b #0, &35		/* interrupt ack */ 
	call #pause
	mov.b r15, &49  /* transferer r15 vers la diode */
	xor #2, r15     /* que fait cette ligne? */
	RETI


pause:
	inc r10
	cmp r11, r10
        jne pause
	mov #0, r10
	ret

