// // const test = require("./Exporting");

// require("./Exporting")


// const name = "Hello gay";
// // console.log(process)
// // setInterval(() => {
// //     console.log(`Gay shit`)
// // }, 1)
// console.log(gayshit + " ")
// // NewFunc("Karthik", gayshit)

const fs = require("fs")
fs.readFile("./DataBase/File1.txt", "utf8", (err, result) => {
    if (err) {
        console.log("The error is", err);
        return;
    }
    const first = result;
    fs.readFile("./DataBase/File2.txt", "utf8", (err, result) => {
        if (err) {
            console.log("The error is", err);
            return;
        }
        const second = result;
        fs.writeFile(
            "./DataBase/OwO.txt",
            `\n${first} + ${second} makes the world a better place`,
            {flag: 'a'},
            (err, result) => {
                if (err) {
                    console.log(err);
                    return;
                }
                console.log(result);
            })
    })
})