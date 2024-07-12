 string caesarCipher(string s, int k) {
    // Normalize the shift to be within the range of 0-25
    k = k%26;
    
    string ans = s; // jab usi ke size ka chahiya and baad mai aap har element. 
    // ko update kar hi rahe ho to...s se hi initialise kar lo....
    
    for (int i=0; i<s.length(); i++){
        if ( s[i]>='a' && s[i]<='z'){
            ans[i] = 'a' + (s[i] - 'a' + k)%26;
            // at any moment if s[i] crossed the alphabets limit then 
            // rotate it back to the 
        }
        else if ( s[i]>='A' && s[i]<='Z'){
            ans[i] = 'A' + (s[i] - 'A' + k)%26;
        }
        else ans[i] = s[i];
    }
    return ans;
}