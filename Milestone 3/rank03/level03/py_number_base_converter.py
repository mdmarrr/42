def number_base_converter(number: str, from_base: int, to_base: int) -> str:
	digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

	if from_base < 2 or from_base > 36:
		return "ERROR"
	
	if to_base < 2 or to_base > 36:
		return "ERROR"
	
	if number == "":
		return "ERROR"
	
	value = 0

	for char in number:
		char = char.upper()

		if char not in digits:
			return "ERROR"
		
		digit = digits.index(char)

		if digit >= from_base:
			return "ERROR"
		
		value = value * from_base + digit
	
	if value == 0:
		return "0"
	
	result = ""

	while value > 0:
		digit = value % to_base
		result = digits[digit] + result
		value //= to_base

	return result
