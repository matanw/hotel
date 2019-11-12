	.text

/* Switch from current_thread to next_thread. Make next_thread
 * the current_thread, and set next_thread to 0.
 * Use eax as a temporary register, which should be caller saved.
 */
	.globl thread_switch
thread_switch:
        /* Fill the missing part */

        //  *p2=*p1
   movl esp_point, %eax // ax=esp_point
   movl  %esp, (%eax) //*ax=esp
   movl ebp_point, %eax // ax=ebp_point
   movl  %ebp, (%eax) //*ax=ebp

	ret				/* pop return address from stack */

