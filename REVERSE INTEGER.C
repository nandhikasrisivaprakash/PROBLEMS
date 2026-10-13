#include <limits.h> // Required for INT_MAX and INT_MIN

int reverse(int x) {
    int r = 0; 
    
    while (x != 0) {            
        // Check for overflow before multiplying by 10
        if (r > INT_MAX / 10 || r < INT_MIN / 10) {
            return 0; // Return 0 if it's going to overflow
        }
        
        r = r * 10 + (x % 10); 
        x = x / 10;            
    }                           
    
    return r;                   
}
