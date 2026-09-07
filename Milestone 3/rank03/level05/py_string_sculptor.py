def string_sculptor(text: str) -> str:
	result = ""
	index = 0

	for char in text:
		if char == " ":
			result += char
			index = 0
		elif char.isalpha():
			if index % 2 == 0:
				result += char.lower()
			else:
				result += char.upper()
			index += 1
		else:
			result += char
		
	return result
