def cryptic_sorter(strings: list[str]) -> list[str]:
    def key(s):
        return (len(s), s.lower(), sum(c.lower() in "aeiou" for c in s))

    return sorted(strings, key=key)
