const {readFile, writeFile} = require("fs").promises;



console.log("test");

const func = async() => {
    try {
        const first = await readFile("./DataBase/File1.txt", "utf8");
        const second = await readFile("./DataBase/File2.txt", "utf8");
        await writeFile(
            "./DataBase/OwO.txt",
            `Hello Dumbfucks, ${first}, ${second} = nice`,
            {flag: "a"}
        )
        console.log(first, second);
    }
    catch (err) {
        console.log(err);
    }
}

func();


//const getText = (path) => {
//     return new Promise((resolve, reject) => {
//         readFile(path, "utf8", (err, data) => {
//             if (err) {
//                 reject(err);
//             }
//             else {
//                 resolve(data);
//             } 
//         })
//     })
// }

// getText("./DataBase/File1.txt").then((result) => console.log(result)).catch((err) => console.log(err));
