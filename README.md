# 42cursus - 03. Ft_printf
<p align="center">
	<a href="#"><img src="https://game.42sp.org.br/static/assets/achievements/ft_printfn.png"/></a>
</p>
<p align="center">
	<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/clgz3vp5u001608l5gzuhclek/project/3131263" alt="evportel's 42 ft_printf Score" /></a>
</p>

### Porque `ft_putnbr()` e `ft_putstr()` não são suficientes ;)

O objetivo deste projeto é bastante simples. Você recodificará `printf()`. Você aprenderá principalmente sobre o uso de um número variável de argumentos. Quão legal é isso?? É realmente muito legal :)

Você descobrirá uma função C popular e versátil: `printf()`. Este exercício é uma ótima oportunidade para melhorar suas habilidades de programação. É de dificuldade moderada.
Você descobrirá funções variádicas em C.
A chave para um `ft_printf` bem-sucedido é um código bem estruturado e extensível.

<strong>Developed during the step cadet, Jun 2023 - The 42 Cursus.</strong><br>

<p>
	<h3>Recodificar a função printf() da libc. </h3>
</p>

O protótipo de `ft_printf()` é: `int ft_printf(const char *, ...);`
- [ ]  Não foi implementado o gerenciamento de buffer do `printf()` original.
- [ ]  A função lida com as seguintes conversões: `c s p d i u x X %`

Você deve implementar as seguintes conversões:

`%c` Imprime um único caractere.

`%s` Imprime uma `string` (conforme definido pela convenção C comum).

`%p` O argumento do ponteiro `void *` deve ser impresso no formato hexadecimal.

`%d` Imprime um número decimal (base 10).

`%i` Imprime um inteiro na base 10.

`%u` Imprime um número decimal sem sinal (base 10).

`%x` Imprime um número em formato hexadecimal (base 16) em minúsculas.

`%X` Imprime um número em formato maiúsculo hexadecimal (base 16).

`%%` Imprime um sinal de porcentagem.

### Functions from `ft_printf.c`

- [`ft_printf`](/ft_printf.c)	- This is the main function of the file. The loop looks for the special character '%', while it doesn't find it, it prints normally. When it finds it, it sends the specifier character reference to the function that handles the formatting.
- [`show_of_parameter`](/ft_printf.c)	- Function works by identifying the formatting specifier character and directing to the correct printing of the parameter passed by the va_list variable.
- [`add_one_more`](/ft_printf.c)	- This function is dedicated to incrementing a static counter that runs through the entire execution of the function, adding 1 to each impression on the display. The flag serves to reset the static variable, informing 0, in cases where the ft_printf function is called several times. Flag 1, just keep adding one more to each character printed.

### Functions from `ft_printf_utils_1.c`
- [`ft_putchar`](/ft_printf_utils_1.c)	- Prints a single character, within the standard ascii table, and adds 1 to the static variable.
- [`ft_putstr`](/ft_printf_utils_1.c)	- Prints a valid string, reusing the ft_putchar function to print each character. When null, expressly prints the word 'null'.
- [`ft_putptr`](/ft_printf_utils_1.c)	- Prints in hexadecimal format, the memory address of the referenced pointer, prefixed with the characters '0x'. Converting an 'unsigned long' parameter to hexadecimal. When null, expressly write the word 'nil'.
- [`ft_putnbr`](/ft_printf_utils_1.c)	- Prints an integer parameter, including its sign, if it is a negative decimal.
- [`ft_putnbr_unsigned`](/ft_printf_utils_1.c)	- Prints an integer parameter, converting it to an unsigned decimal.
 

Compilation command:
``` sh
make
```

### Testes
<p>I used some community tests 42:<p/>
<p>From Paulo Santana's repository - https://github.com/paulo-santana/ft_printf_tester.<br/> And from the Tripouille repository - https://github.com/Tripouille/printfTester</p>
<p>
	You can view these tests on the Actions tab, where I created a Workflow to verify the code in accordance with the 42 standard, the generation of the library with the printf code and the two tests mentioned above.
<p/>

[![flow-with-norm-build-tests](https://github.com/evertonportela/42cursus-02-Get-Next-Line/actions/workflows/flow-with-norm-build-tests.yml/badge.svg)](https://github.com/evertonportela/42cursus-02-Get-Next-Line/actions/workflows/flow-with-norm-build-tests.yml)