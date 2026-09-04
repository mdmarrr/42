def anagram(s1: str, s2: str) -> bool:
	s1 = s1.replace(" ", "").lower()
	s2 = s2.replace(" ", "").lower()

	if len(s1) != len(s2):
		return False
	
	for char in s1:
		if s1.count(char) != s2.cpunt(char):
			return False
		
	return True
