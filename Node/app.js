const EventEmitter = require("events");

const customEmitter = new EventEmitter();

var test = 69

customEmitter.on("touch", (name) => {
    console.log(`Data is being touched by ${name} and number ${test}`);
})

welcome = "hi";
customEmitter.emit("touch", welcome);