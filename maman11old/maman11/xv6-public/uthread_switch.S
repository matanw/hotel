	.text

/* Switch from current_thread to next_thread. Make next_thread
 * the current_thread, and set next_thread to 0.
 * Use eax as a temporary register, which should be caller saved.
 */
	.globl thread_switch
thread_switch:

/*current_thread ,next_thread*/
	/*1. store registers+esp into currcet_thread*/
	pushal 
	movl current_thread, %eax
	movl %esp, (%eax)
 
	/* 2. load register+esp from next thread*/
	movl next_thread, %eax
	movl (%eax), %esp
	popal
	
	/*3. - update currrent to be next, set next to 0*/
	movl next_thread, %eax
	movl %eax, current_thread	
	movl $0, next_thread        
	
	ret	
