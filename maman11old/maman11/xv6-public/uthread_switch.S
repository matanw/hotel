	.text

/* Switch from current_thread to next_thread. Make next_thread
 * the current_thread, and set next_thread to 0.
 * Use eax as a temporary register, which should be caller saved.
 */
	.globl thread_switch
thread_switch:

/*current_thread ,next_thread*/
/*1. store stuff into cur*/
pushal 
movl current_thread, %eax
 movl %esp, (%eax)
 
/* 2. load from next*/
movl next_thread, %eax
movl (%eax), %esp
popal
/*in step 3 - update cur to be next*/
movl next_thread, %eax
movl %eax, current_thread	
movl $0, next_thread        
/* Fill the missing part */
	ret				/* pop return address from stack */

