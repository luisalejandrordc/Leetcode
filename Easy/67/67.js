/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */

var addBinary = function (a, b) {
	let max = a.length > b.length ? a.length : b.length;
	let sum = [];
	for (let i = 0; i < max; i++) {
		if (a[i] === undefined || b[i] === undefined) {
			sum[i] = a[i] === undefined ? b[i] : a[i];
		} else {
			if (a[i] === "1" && b[i] === "1") {
				sum[i] = "0";
			} else {
				sum[i] = String(Number(a[i]) + Number(b[i]));
			}
		}
		if (a[i] === 0 || b[i] === 0) {
			console.log("Hello");
		}
	}
	return sum;
};

console.log(addBinary("1010", "1011"));

console.log(4 + undefined);
