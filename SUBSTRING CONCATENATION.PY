class Solution(object):

  def findSubstring(self, s, words):
    if not s or not words:
      return []

    # Get length of a single word using the first element
    word_len = len(words[0])
    num_words = len(words)

    # Build frequency map using a plain dictionary for compatibility
    word_freq = {}
    for word in words:
      word_freq[word] = word_freq.get(word, 0) + 1

    result = []

    # Slide window over all possible offsets
    for i in range(word_len):
      left = i
      right = i
      current_freq = {}
      matched_words = 0

      while right + word_len <= len(s):
        word = s[right : right + word_len]
        right += word_len

        if word in word_freq:
          current_freq[word] = current_freq.get(word, 0) + 1
          matched_words += 1

          # Slide left boundary if a word limit is exceeded
          while current_freq[word] > word_freq[word]:
            left_word = s[left : left + word_len]
            current_freq[left_word] -= 1
            left += word_len
            matched_words -= 1

          # Found a full valid sequence permutation
          if matched_words == num_words:
            result.append(left)
        else:
          # Invalid word hit, reset the current tracking window
          current_freq.clear()
          matched_words = 0
          left = right

    return result
