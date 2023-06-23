# 42cursus - 02. Get_Next_Line
<p align="center">
	<a href="#"><img src="https://game.42sp.org.br/static/assets/achievements/get_next_linee.png"/></a>
</p>
<p align="center">
	<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/clgz3vp5u001608l5gzuhclek/project/3118092" alt="evportel's 42 get_next_line Score" /></a>
</p>

### Ler uma linha de um fd é muito tedioso ;D

Este projeto trata da programação de uma função que retorna uma linha lida de um descritor de arquivo.

<strong>Developed during the step cadet, Jun 2023 - The 42 Cursus.</strong><br>

<p>
	Not only will this project allow you to add a very convenient function to your collection, but it will also make you learn a very interesting new concept in C programming: static variables.
</p>

<p>
	The prototype of `get_next_line()` is: `char *get_next_line(int fd);`<br/>
	Repeated calls (eg using a loop) to your get_next_line() function should allow you to read the text file pointed to by the file descriptor, one line at a time.<br/>
	The line returned must include the final \n character, unless the end of the file is reached and does not end with a \n character.<br/>
	!!! A good start would be to know what a static variable is.<p/>

### Functions from `get_next_line.c`

- [`get_next_line(int fd)`](/get_next_line.c) - Reads from a file descriptor and returns one line read per call, including \n, unless EOF (find end of file) and no \n is present, in which case whatever was read is returned immediately.
- [`free_work_memories`](/get_next_line.c) - Frees the allocated memories, clearing the memories used in work on other functions.
- [`get_only_line`](/get_next_line.c) - Last part of the get_next_line function. Free the memories if necessary, then bind the current read line to be returned, and store what's left of the buffer in the `rest_content` static variable to have the beginning of the next line saved for the next function call.
- [`content_after_line`](/get_next_line.c) - Everything else inside the buffer after the first \n found is saved in the static variable `rest`. This ensures that the start of the next line isn't lost between function calls.
- [`content_before_break_line`](/get_next_line.c) - Cuts only the beginning of the content, before the first \n.

### Functions from `get_next_line_utils.c`

- [`ft_strlen`](/get_next_line_utils.c)	- Returns the length of a valid string.
- [`ft_strdup`](/get_next_line_utils.c)	- Duplicates one string into another. allocates memory using malloc.
- [`ft_strjoin`](/get_next_line_utils.c) - Concatenates two fixed-length strings into one. Allocate memory using malloc.
- [`ft_strlcpy`](/get_next_line_utils.c) - Copies (up to size bytes) the content of a string (src) into another (dst). Replaces the contents of dst.
- [`line_break_position`](/get_next_line_utils.c) - Checks a string for a single-line character (\n). If found, returns its position (>= 0). Otherwise, it returns -1.

### Testes
<p>I used some community tests 42:<p/>
<p>From Tripouille repository - git clone https://github.com/Tripouille/gnlTester.git</p>
<p>
	You can view these tests on the Actions tab, where I created a Workflow to verify the code in accordance with the 42 standard and the tests mentioned above.
<p/>

[![flow-with-norm-build-tests](https://github.com/evertonportela/42cursus-02-Get-Next-Line/actions/workflows/flow-with-norm-build-tests.yml/badge.svg)](https://github.com/evertonportela/42cursus-02-Get-Next-Line/actions/workflows/flow-with-norm-build-tests.yml)