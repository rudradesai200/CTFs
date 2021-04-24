const { unflatten } = require("flat");

// var obj = JSON.stringify();
// console.log(obj);
const { song } = unflatten("{ 'song.name': 'hello' }");

console.log(song);
// console.log(song.name.includes("hello"));
