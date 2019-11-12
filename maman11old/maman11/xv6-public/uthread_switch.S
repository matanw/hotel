	.text

/* Switch from current_thread to next_thread. Make next_thread
 * the current_thread, and set next_thread to 0.
 * Use eax as a temporary register, which should be caller saved.
 */
	.globl thread_switch
thread_switch:
// *current_thread=esp
// movl current_thread, %eax
 //movl %esp, (%eax)

movl my_thread_p, %eax
movl (%eax),%esp
// esp =*my_thread_p
	ret				/* pop return address from stack */

