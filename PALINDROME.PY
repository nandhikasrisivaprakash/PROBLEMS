bool isPalindrome(int x) {
    
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedHalf = 0;
    
    
    while (x > reversedHalf) {
        reversedHalf = (reversedHalf * 10) + (x % 10);
        x /= 10;
    }

    
    bool outcome = (x == reversedHalf || x == reversedHalf / 10);
    
    
    return outcome;
}
