#include <iostream> /* <-- cout defined in here. */
/* NOTE: the "#include" just copy/pastes the contents
 * of the file where that line appears!  We need it
 * to help us read / write from standard input/output. */
using std::cout;
/* NOTE: cout has a first name (cout) and a last name
 * which is (std).  Without this "using" statement we
 * would have to say "std::cout" instead of just "cout".
 * */

/* this is the starting point of the program: */
int main()
{
	/* let's try to print a message to the screen. */
	/* here's the usual way: */
	cout << "hello class!\n";
	/* NOTE: the "int" before main indicates that main
	 * should ultimately return ("compute") an integer result.
	 * We'll always give 0 as the result: */
	return 0;
	/* NOTE: this return value is how our program communicates
	 * back to the shell that started it.  In this context, 0 means
	 * the program "worked" (didn't encounter any errors). */
}

/* To run this on our computer, we have to first translate it into those tiny
 * instructions the cpu understands.  Do this with the help of g++:
 * $ g++ hello.cpp
 * Then run it with
 * $ ./a.out
 * NOTE: you can see some of the commands we ran during lecture in the
 * "bash-history" file.
 * */

/* TODO: follow the tutorial on "building on the command line" from our
 * homepage.  Then just spend some time experimenting and see what you
 * can learn.  */

/* TODO: take a look at what's really involved in running this
 * program (the tiny instructions I mentioned).  Try this:
 * $ gdb a.out
 * (gdb) break main
 * (gdb) tui enable
 * (gdb) layout asm
 * (gdb) run
 * (gdb) si
 * <then just keep hitting enter until you're bored...>
 * */

/* NOTE: a few takeaways from our first lecture:
 * 1. There is a huge gap in abstraction levels that must be bridged.
 * 2. The compiler is your friend, but you still need to give it a
 *    seemingly unnatural amount of detail...
 * */
