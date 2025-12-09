Proyecto:

ft_printf es una función personalizada que imita el comportamiento de la función printf. Esta implementación admite los siguientes especificadores de formato:
- %c: imprime un carácter.
- %s: imprime una cadena de caracteres.
- %d / %i: imprime un número entero con signo.
- %u: imprime un número entero sin signo.
- %x: imprime un número en formato hexadecimal (en minúsculas).
- %X: imprime un número en formato hexadecimal (en mayúsculas).
- %p: imprime una dirección de memoria en formato de puntero.

Compilación:

- make			# Compila libftprintf.a
- make clean	# Elimina archivos .o
- make fclean	# Limpia todo
- make re		# Reconstruye el proyecto
