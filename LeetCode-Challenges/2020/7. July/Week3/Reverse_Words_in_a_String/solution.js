/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
	const splited = s.split(' ');
	const op = [];
	for(let i = splited.length - 1; i >= 0; --i) {
			if(splited[i].trim() !== "") {
				op.push(splited[i]);
			}
	}
	
	return op.join(' ');
};