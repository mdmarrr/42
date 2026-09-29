def number_base_converter(number: str, from_base: int, to_base: int) -> str:
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    if from_base < 2 or from_base > 36 or to_base < 2 or to_base > 36:
        return "ERROR"

    try:
        number = int(number, from_base)
    except ValueError:
        return "ERROR"

    if number == 0:
        return "0"

    result = ""

    while number > 0:
        result = digits[number % to_base] + result
        number = number // to_base

    return result
