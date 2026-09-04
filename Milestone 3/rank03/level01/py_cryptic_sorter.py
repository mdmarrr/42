def cryptic_sorter(strings: list[str]) -> list[str]:
	result = []

	def vowels_count(s: str) -> int:
		count = 0
		for char in s:
			if char.lower() in "aeiou":
				count += 1
		return count
	
	def key(s: str):
		return (
			len(s),
			s.lower(),
			vowels_count(s)
		)
	
	for string in strings:
		i = len(result)

		while i > 0 and key(result[i -1]) > key(string):
			i -= 1
		
		result.insert(i, string)
	
	return result