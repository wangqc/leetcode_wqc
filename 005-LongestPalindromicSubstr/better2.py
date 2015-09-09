# The key intuition of this algorithm is that palindromes are made up of
# smaller palindromes.

# So, a palindrome of length 100 (for example), will have a palindrome of
# length 98 inside it, and one of length 96, ... 50, ... 4, and 2.

# Because of this, we can move across our string, checking if the current
# place is a palindrome of a particular length (the longest length palindrome
# found so far + 1), and if it is, update the longest length, and move forward.

# In this way, we find our longest palindromes "from the inside out", starting
# with length x, then x+2, x+4, ...

# Example:
# "xxABCDCBAio"
#  0123456789  < indexes
# As we scan our string, we initially find a palindrome of length 2 (xx)
# We always look backwards!
# When we get to index 2,3,4, we see no length 3+ palindrome ending there.
# But when we get to index 6, looking back 3 characters, we see "CDC"! So our
# longest palindrome is now length 3.
# At index 7, we look back and see no length 4 palindromes, but find one of
# length 5 ("BCDCB").
# And finally, by i = 8, we find the full "ABCDCBA"

# Hope that helps!

class Solution:
    # @return a string
    def longestPalindrome(self, s):
        longest_index = 0
        max_length = 0
        for i in xrange(len(s)):
            if is_palindrome(s, i - max_length, i):
                longest_index = i - max_length
                max_length = max_length + 1
            elif i - max_length - 1 >= 0 and is_palindrome(s, i - max_length - 1, i):
                longest_index = i - max_length - 1
                max_length = max_length + 2

        return s[longest_index:longest_index + max_length]

def is_palindrome(string, start, end):
    for i in xrange((end - start + 1) / 2):
        if string[start + i] != string[end - i]:
            return False
    return True
