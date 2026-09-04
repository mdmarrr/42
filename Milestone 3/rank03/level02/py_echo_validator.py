def echo_validator(text: str) -> bool:
	clean = ""

	for char in text:
		if char.isalpha():
			clean += char.lower()

		if clean == "":
			return False
		
		return clean == clean[::-1]
