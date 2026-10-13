class Solution:
    def isValid(self, s: str) -> bool:
        mapping = {'(': ')', '[': ']', '{': '}'}
        stack = []
        for char in s:
            if char in mapping:
                stack.append(mapping[char])
            elif stack and char == stack[-1]:
                stack.pop()
            else:
                return False
        return not stack
