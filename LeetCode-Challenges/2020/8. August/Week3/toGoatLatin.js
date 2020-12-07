/**
 * @param {string} S
 * @return {string}
 */
var toGoatLatin = function(S) {
    const words = S.split(' ');
    let suffix = '';
    
    for(let i = 0; i < words.length; ++i) {
        let word = words[i];
        suffix += 'a';
        
        if('aeiouAEIOU'.indexOf(word[0]) === -1) 
            word = word.substr(1) + word[0];
        
        word += 'ma' + suffix;
        
        words[i] = word;
    }
    
    return words.join(' ');
};