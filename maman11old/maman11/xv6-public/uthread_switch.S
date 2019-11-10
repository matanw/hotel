	.text

/* Switch from current_thread to next_thread. Make next_thread
 * the current_thread, and set next_thread to 0.
 * Use eax as a temporary register, which should be caller saved.
 */
	.globl thread_switch
thread_switch:
        /* Fill the missing part */

        //  *p2=*p1
   mov p2, %eax // ax=p2
   mov  i1, (%eax) //*ax=i1 -> *p2=i1 -> i2=i1
	ret				/* pop return address from stack */

