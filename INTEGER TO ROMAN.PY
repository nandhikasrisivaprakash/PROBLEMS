class Solution:
    def intToRoman(self, num: int) -> str:
        # Map values to their corresponding Roman numeral symbols in descending order
        roman_mapping = [
            (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
            (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
            (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")
        ]
        
        result = []
        
        # Iterate through the mapping and subtract values greedily
        for value, symbol in roman_mapping:
            if num == 0:
                break
            # Determine how many times the symbol fits into the current number
            count = num // value
            if count > 0:
                result.append(symbol * count)
                num -= value * count
                
        return "".join(result)
