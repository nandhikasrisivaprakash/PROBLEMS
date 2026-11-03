class Solution:
    def isNumber(self, s: str) -> bool:
        seen_digit = seen_dot = seen_exponent = False
        
        for i, char in enumerate(s):
            if char.isdigit():
                seen_digit = True
                
            elif char in ('+', '-'):
                # Signs are only valid at index 0 or right after an exponent
                if i > 0 and s[i - 1] not in ('e', 'E'):
                    return False
                    
            elif char in ('e', 'E'):
                # Exponent needs a leading digit and can only appear once
                if seen_exponent or not seen_digit:
                    return False
                seen_exponent = True
                seen_digit = False  # Reset to force at least one digit after 'e'
                
            elif char == '.':
                # Decimals cannot appear after an exponent or another decimal
                if seen_dot or seen_exponent:
                    return False
                seen_dot = True
                
            else:
                return False
                
        return seen_digit
