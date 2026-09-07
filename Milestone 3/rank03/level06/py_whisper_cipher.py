def whisper_cipher(text: str, shift: int) -> str:
	result = ""

	for char in text:
		if char.isalpha():
			if char.islower():
				start = ord("a")
			else:
				start = ord("A")
			
			new_char = chr((ord(char) - start + shift) % 26 + start)
			result += new_char
		else:
			result += char
		
	return result
